## 一.概念，作用，工作机制
概念：简单来说，CMake 是一个**跨平台的自动化构建系统生成器**

:::color1
**关键词理解：构建**

**形**象地来说，就是**从源代码到可运行软件的自动化生产流水线**

为什么要构建？项目变大时，且不同的源文件相互依赖，编译效率低，命令复杂

构建可以解决这些问题

构建的具体流程（“构建”不是一个单一动作，而是一个包含多个步骤的自动化流程）

**配置：检查当前电脑的环境，比如编译器在哪里？需要的第三方库安装了吗？在什么路径**

**编译：将人类可读的源代码（**`**.c**`**, **`**.cpp**`**）翻译成机器可读的目标文件（**`**.o**`** 或 **`**.obj**`**）**

**链接：将上一步生成的目标文件以及第三方库文件结合在一起形成可执行文件**

:::

作用：回到 CMake 和 “构建”，理解 CMake 在 “构建” 过程中的角色：

1.**解决跨平台编译问题**

问题：不同的操作系统（Windows, Linux, macOS）使用不同的构建工具

cmake给出的解决方案：我只需要编写一份与平台无关的 cmakelist.txt文件。CMake 会根据目标平台，生成对应的原生构建文件

2.**管理复杂的项目结构**

**3.简化构建流程和依赖管理**

CMake 提供了强大的命令来查找系统上的库（如 `find_package`）等等

工作机制/流程：

开发者编写Cmakelist.txt-->生成原生构建文件—>形成可执行文件

## 二.编写Cmakelist.txt
（1）基本骨架

-------基本命令--------

`**1.cmake_minimum_required**`**：**指定Cmake最低版本要求，必须是文件的第一行

版本号根据使用的cmake路径，不能超过自身安装的版本号

2**.project**：定义项目的基本信息

-------目标创建命令---------

3. `add_executable`：创建可执行文件目标

```plain
add_executable(my_app
    src/main.cpp
    src/helper.cpp
    src/utils.cpp
)
```

理解：哪些要加在该条指令的后面：源文件.cpp

实现的操作：

在构建系统中注册名为 `my_app` 的目标

建立源文件到目标的映射关系

设置目标的默认属性（如类型为 EXECUTABLE）

`add_executable`**创建的是一个构建目标的定义**，它：

+ ✅ 定义了要构建什么（可执行文件）
+ ✅ 记录了需要哪些源文件
+ ✅ 作为其他属性（编译选项、包含目录等）的载体
+ ✅ 建立了依赖关系
+ ❌ **不立即生成可执行文件**
+ ❌ **不进行任何编译操作**

4.add_library():创建库目标



:::color1
库

**库**是一组预编译的代码和数据的集合，它提供了特定的功能，可以被多个程序共享和重用

分为静态库（static library）和动态库（shared library）

:::

```plain
# 静态库
add_library(my_static_lib STATIC src.cpp)（编译时连接）

# 动态库
add_library(my_shared_lib SHARED src.cpp)（运行时连接）

# 接口库（头文件库）
add_library(my_interface_lib INTERFACE)

# 对象库（不打包，只编译）
add_library(my_obj_lib OBJECT src.cpp)

# 别名库
add_library(my_alias ALIAS my_shared_lib)
```

-------依赖和链接命令-------

5.target_link_libraries:建立目标间的依赖关系

```plain
target_link_libraries(my_app
    PUBLIC          # 使用者和当前目标都需要
        Boost::filesystem
    PRIVATE         # 仅当前目标需要
        my_internal_lib
    INTERFACE       # 仅使用者需要
        my_headers_only_lib
)
```

6.find_package：查找并加载外部依赖包

:::color1
外部依赖包

**外部依赖包**是其他人编写、打包并发布的代码集合，你的项目可以引入并使用它们的功能，而不用自己重新实现。

:::

------目录与文件管理命令------

7.`target_include_directories：`为特定目标添加头文件搜索路径

```plain
target_include_directories(<target> [SYSTEM] [BEFORE]
  <INTERFACE|PUBLIC|PRIVATE> [items1...]
  [<INTERFACE|PUBLIC|PRIVATE> [items2...] ...])
```

+ `**<target>**`： 由 `add_executable()` 或 `add_library()` 创建的目标名称。
+ `**[SYSTEM]**`： 可选参数。将指定的目录视为系统头文件目录。这可能会让编译器抑制这些头文件中产生的警告。
+ `**[BEFORE]**`： 可选参数。将包含路径添加到目标已有路径的前面，而不是默认的后面。
+ `**<INTERFACE|PUBLIC|PRIVATE>**`： **关键参数**。用于指定头文件路径的**可见性**，决定了哪些其他目标可以“看到”这些路径。

示例：

```plain
# my_lib 的公共头文件在 include 目录，私有实现需要 src 目录
target_include_directories(my_lib
    PUBLIC  ${CMAKE_CURRENT_SOURCE_DIR}/include  # 给使用 my_lib 的目标用
    PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src      # 仅自己用
)
```

8.`add_subdirectory`：添加一个子目录到构建中

示例：添加src子目录

add_subdirectory(src)

-----变量与属性命令-----

9.set：设置一个普通变量、缓存变量或环境变量

:::color1
普通变量：

+ 在程序或脚本内部定义和使用
+ 生命周期限于当前进程或作用域
+ 进程结束后自动销毁

缓存变量：

+ 用于临时存储频繁访问的数据
+ 提高数据访问速度
+ 可以存在于内存、磁盘或专用缓存系统中

环境变量：

+ 用于临时存储频繁访问的数据
+ 提高数据访问速度
+ 可以存在于内存、磁盘或专用缓存系统中

:::

10.unset：取消设置一个变量

11.message:在配置时输出一个信息

`message([<mode>] "message text" ...)`

**常用模式**：

`STATUS`：前缀为 `--` 的信息。

`WARNING`：CMake 警告，继续处理。

`AUTHOR_WARNING`：CMake 作者警告，继续处理。

`SEND_ERROR`：CMake 错误，继续处理，但跳过生成。

`FATAL_ERROR`：CMake 错误，停止所有处理。

-----查找与依赖管理-----

12.find_package:查找并加载外部项目的设置

+ `REQUIRED`：如果找不到包，则停止配置。
+ `COMPONENTS`：指定需要查找的包的组件

示例：

   f ind_package(OpenCV 4.0 REQUIRED COMPONENTS core imgproc)

如果找到，会定义 OpenCV_LIBS, OpenCV_INCLUDE_DIRS 等变量（旧式）

 或者提供 IMPORTED TARGETS（现代方式），如 OpenCV::core, OpenCV::imgproc

target_link_libraries(my_app PRIVATE OpenCV::core OpenCV::imgproc)

13.install（）：用于定义项目的安装规则，指定构建后文件应该被复制到哪些位置

```plain
install(TARGETS <target>... 
        [EXPORT <export-name>]
        [RUNTIME DESTINATION <dir>]
        [LIBRARY DESTINATION <dir>] 
        [ARCHIVE DESTINATION <dir>]
        [INCLUDES DESTINATION <dir>])
```

安装可执行文件

cmake

```plain
# 安装可执行文件到 bin 目录
install(TARGETS my_app
        RUNTIME DESTINATION bin)
```

安装库文件

cmake

```plain
# 安装库文件
install(TARGETS my_lib
        RUNTIME DESTINATION bin    # DLL 在 Windows 上
        LIBRARY DESTINATION lib    # 共享库在 Unix 上
        ARCHIVE DESTINATION lib)   # 静态库
```

安装头文件

cmake

```plain
# 安装头文件
install(DIRECTORY include/ 
        DESTINATION include
        FILES_MATCHING PATTERN "*.h")
```

安装其他文件

cmake

```plain
# 安装配置文件、文档等
install(FILES config.xml README.md
        DESTINATION share/myproject)
        
install(DIRECTORY docs/
        DESTINATION share/doc/myproject)
```

## 三.源码外构建
**源码内构建**：在源码目录中直接构建，会产生大量构建文件，污染源码目录

**源码外构建**：在独立的构建目录中进行编译，保持源码目录干净整洁

标准流程：

```plain
# 1. 创建并进入构建目录
mkdir build && cd build

# 2. 配置项目，生成构建系统文件
cmake ..

# 3. 编译项目
make

# 4. （可选）运行程序
./你的可执行文件名
```

这是我源码外构建cryptotool项目，以及运行

![](https://cdn.nlark.com/yuque/0/2025/png/61384029/1760851603252-64b3d278-63e8-4e19-826d-c2a2b41c68c3.png)![](https://cdn.nlark.com/yuque/0/2025/png/61384029/1760851602707-d92a5fb0-76c8-4fe4-8a35-ad48dbf2b293.png)![](https://cdn.nlark.com/yuque/0/2025/png/61384029/1760851602943-7a92c741-80a9-44c3-9a0b-860296301e39.png)![](https://cdn.nlark.com/yuque/0/2025/png/61384029/1760851602857-3b3ae11a-34d2-4660-9d0a-ee63d7de3a3d.png)![](https://cdn.nlark.com/yuque/0/2025/png/61384029/1760851602902-495ff579-8b08-42e5-86e6-e55fb9a4c63f.png)

## 四.构建问题排查
#### 1. 路径错误
**问题表现**：

text

Cannot find source file: "src/main.cpp"

**解决方案**：

cmake

```plain
# 使用绝对路径或正确的相对路径
add_executable(my_app ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp)

# 或者确保在正确的目录中运行 CMake
# 使用 CMAKE_SOURCE_DIR 或 PROJECT_SOURCE_DIR
include_directories(${PROJECT_SOURCE_DIR}/include)
```

#### 2. 依赖找不到
**问题表现**：

text

Could not find a package configuration file provided by "OpenCV"

**解决方案**：

cmake

```plain
# 方法1：设置查找路径
set(OpenCV_DIR "/path/to/opencv/build")
find_package(OpenCV REQUIRED)

# 方法2：使用 pkg-config（如果可用）
find_package(PkgConfig)
pkg_check_modules(OPENCV REQUIRED opencv4)

# 方法3：手动指定路径
find_library(OPENCV_LIB opencv4 PATHS "/usr/local/lib")
find_path(OPENCV_INCLUDE opencv4/opencv2.hpp PATHS "/usr/local/include")
```

#### 3. 版本不兼容
**问题表现**：

text

```plain
CMake Error at CMakeLists.txt:1 (cmake_minimum_required):
  CMake 3.10 or higher is required.  You are running version 3.5.1
```

**解决方案**：

bash

```plain
# 升级 CMake
# Ubuntu/Debian
sudo apt update && sudo apt install cmake

# macOS
brew update && brew install cmake

# 或者检查现有版本
cmake --version
```

#### 4. 编译器问题
**问题表现**：

text

error: C++ standard requested is unavailable

**解决方案**：

cmake

```plain
# 明确设置 C++ 标准
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# 或者针对特定目标
target_compile_features(my_target PRIVATE cxx_std_17)
```

#### 5. 链接错误
**问题表现**：

text

undefined reference to `function_name'

**解决方案**：

cmake

```plain
# 确保正确链接所有依赖库
target_link_libraries(my_app PRIVATE 
    my_lib 
    pthread 
    ${OPENCV_LIBRARIES})

# 检查库顺序（被依赖的库放在后面）
```













****



