### 一.概念解析
#### （1）镜像（image）
**概念**：镜像是一种轻量级的、可执行的独立软件包。用来打包软件运行环境和基于运行环境的开发软件，它包含运行某个软件所需要的内容，包括代码、运行时、库、环境变量和配置文件。

一个**只读的模板**或**快照**（<font style="color:#DF2A3F;">只读：镜像一旦被创建，内容不可以修改）</font>

**作用：** 镜像是创建容器的基础<font style="color:#DF2A3F;">（蓝图）</font>

面向对象的编程中，镜像被理解为类，而容器被理解为实例化后的对象

#### （2）容器（container）
**概念: **容器是镜像的一个**运行时的实例，**容器是一个符合 OCI 标准的、轻量级、可执行的独立软件包。它通过操作系统内核提供的隔离技术，将一个应用及其所有依赖项封装在一起，使其可以在任何支持容器的环境中一致、可靠地运行。

**特点：**

+ **可写层**：当容器启动时，Docker会在镜像的只读层之上添加一个可写的薄层。所有对容器的修改（如创建文件、安装软件）都发生在这个可写层。
+ **隔离性**：容器与主机以及其他容器是相互隔离的，拥有自己的进程空间、网络接口、文件系统等。
+ **轻量级**：因为多个容器可以共享同一个底层镜像，所以它们启动非常快，占用资源极少。
+ **临时性**：容器可以被创建、启动、停止、删除。删除容器时，其可写层也会被删除（数据会丢失，除非使用数据卷）。

🤔<font style="color:#DF2A3F;">linux系统与容器：</font>

<font style="color:#DF2A3F;">一开始我错误的理解为linux就是一个容器，通过查阅资料：</font>

+ **Linux 系统是“主机”和“基石”**<font style="color:#DF2A3F;">。它提供了运行一切的基础环境，特别是</font>**内核**<font style="color:#DF2A3F;">。</font>
+ **容器是“客人”和“产品”**<font style="color:#DF2A3F;">。它是在这个基石之上，利用内核特性创造出来的一个</font>**隔离的进程环境**<font style="color:#DF2A3F;">。</font>

#### （3）仓库（Registry/Docker Hub）
**概念**： 仓库是集中存放镜像的地方

<font style="color:#DF2A3F;">可以理解为手机里的应用商店</font>

Docker Hub是docker官方的镜像存放仓库，任何人都可以从上面拉取（下载）公共镜像，也可以推送（上传）自己的镜像

#### （4）docker
 Docker是一个**开源的应用容器引擎**，让开发者可以打包他们的应用以及依赖包到一个可抑制的容器中，然后发布到任何流行的Linux机器上，也可以实现虚拟化。

<font style="color:#DF2A3F;">docker是一种容器技术，解决软件跨环境迁移的问题</font>

#### （5）docker与虚拟机的区别
虚拟机是**硬件虚拟化**，它在物理硬件上虚拟出一整套完整的硬件环境，然后在其上安装完整的操作系统。这导致了它的**重**。

Docker是**操作系统虚拟化**，它利用主机操作系统的内核，通过隔离技术为每个容器创建独立的进程空间、文件系统等。这使得它非常**轻量**，但因为共享内核，所以容器内的系统必须与主机系统兼容（例如，不能在Linux主机上运行Windows容器，反之亦然）。

#### （6）构建概念间联系
**<font style="color:#DF2A3F;">Docker是工厂，镜像是模具，容器是产品，仓库是仓库/商店</font>**

流程联系：

从仓库拉取镜像 → 用镜像创建容器 → 运行容器

      ↓               ↓             ↓

   (获取模板)      (实例化)       (执行应用)

开发工作流：

开发环境：编写代码 → 构建镜像 → 运行容器 → 测试

                      ↓

生产环境：从仓库拉取镜像 → 运行容器

![](https://cdn.nlark.com/yuque/0/2025/jpeg/61384029/1760504734965-bf1c05ac-e5fd-4fbd-a615-66aca2f6360c.jpeg)

1. Docker 与 镜像

关系：Docker引擎负责构建、管理和存储镜像

类比：就像工厂的生产线可以制造和存储模具

2. 镜像 与 容器

关系：镜像是蓝图，容器是根据蓝图建好的房子

关键点：一个镜像可以创建多个容器实例

例子：一个Nginx镜像可以同时运行10个Nginx容器

3. Docker 与 容器

关系：Docker引擎负责创建、启动、停止、删除容器

类比：工厂的生产线根据模具生产具体产品

4. 仓库 与 整个体系

关系：仓库是镜像的集散中心，连接开发、测试、生产环境

价值：确保所有环境使用的都是同一个镜像，解决环境一致性问题

**<font style="color:#D22D8D;">一句话总结：Docker引擎使用从仓库获取的镜像，来创建和运行隔离的容器环境</font>**

![](https://cdn.nlark.com/yuque/0/2025/png/61384029/1760532120873-e7112b32-5536-451f-82c5-83f301000f02.png)

#### （7）镜像的分层结构
---

### 二.常用的docker命令
#### (1)命令及详解
| **命令** | **功能** | **示例** |
| --- | --- | --- |
| `<font style="color:#DF2A3F;">docker run</font>` | 启动一个新的容器并运行命令 | `docker run -d ubuntu` |
| `<font style="color:#DF2A3F;">docker ps</font>` | 列出当前正在运行的容器 | `docker ps` |
| `<font style="color:#DF2A3F;">docker ps -a</font>`<br/><font style="color:#DF2A3F;">(-a的意思是all）</font> | 列出所有容器（包括已停止的容器） | `docker ps -a` |
| `docker build` | 使用 Dockerfile 构建镜像 | `docker build -t my-image .` |
| `<font style="color:#DF2A3F;">docker images</font>` | 列出本地存储的所有镜像 | `docker images` |
| `<font style="color:#DF2A3F;">docker pull</font>` | 从 Docker 仓库拉取镜像 | `docker pull ubuntu` |
| `docker push` | 将镜像推送到 Docker 仓库 | `docker push my-image` |
| `docker exec` | 在运行的容器中执行命令 | `docker exec -it container_name bash` |
| `<font style="color:#DF2A3F;">docker stop</font>` | 停止一个或多个容器 | `docker stop container_name` |
| `docker start` | 启动已停止的容器 | `docker start container_name` |
| `docker restart` | 重启一个容器 | `docker restart container_name` |
| `<font style="color:#DF2A3F;">docker rm</font>` | 删除一个或多个容器 | `docker rm container_name` |
| `<font style="color:#DF2A3F;">docker rmi</font>` | 删除一个或多个镜像 | `docker rmi my-image/ID` |
| `<font style="color:#DF2A3F;">docker logs</font>` | 查看容器的日志 | `docker logs container_name` |
| `docker inspect` | 获取容器或镜像的详细信息 | `docker inspect container_name` |
| `<font style="color:#DF2A3F;">docker exec -it</font>` | 进入容器的交互式终端 | `docker exec -it container_name /bin/bash` |
| `docker network ls` | 列出所有 Docker 网络 | `docker network ls` |
| `docker volume ls` | 列出所有 Docker 卷 | `docker volume ls` |
| `docker-compose up` | 启动多容器应用（从 `docker-compose.yml`<br/> 文件） | `docker-compose up` |
| `docker-compose down` | 停止并删除由 `docker-compose`<br/> 启动的容器、网络等 | `docker-compose down` |
| `docker info` | 显示 Docker 系统的详细信息 | `docker info` |
| `docker version` | 显示 Docker 客户端和守护进程的版本信息 | `docker version` |
| `docker stats` | 显示容器的实时资源使用情况 | `docker stats` |
| `docker login` | 登录 Docker 仓库 | `docker login` |
| `docker logout` | 登出 Docker 仓库 | `docker logout` |


部分命令详解：

1.**常用选项说明:**

+ `**-d**`：后台运行容器，例如 `docker run -d ubuntu`。
+ `**-it**`：以交互式终端运行容器，例如 `docker exec -it container_name bash`。
+ `**-t**`：为镜像指定标签，例如 `docker build -t my-image .`。

2.输出说明

![](https://cdn.nlark.com/yuque/0/2025/png/61384029/1760539153944-efc05f22-2147-45d4-b2cb-c11e8149b5b9.png)

<font style="color:#DF2A3F;">docker.io/library/nginx:latest:</font>

**registry：仓库地址/namespace：命名空间（作者名）**

docker.io表示是docker的官方仓库，可略/  ：tag：标签（版本号）

library是docker官方仓库的命名空间，可略

latest最新版本，也可省略

简化后的命令：<font style="color:#DF2A3F;">docker  pull nginx表示从docker官方仓库的官方命名空间里面下载最新版本的nginx docker镜像</font>

![](https://cdn.nlark.com/yuque/0/2025/png/61384029/1760542462303-9c437f04-cee1-4b14-8d8f-caf612aaf8ca.png)

显示本地下载的所有镜像

各个选项说明:

+ **REPOSITORY：**表示镜像的仓库源
+ **TAG：**镜像的标签<font style="color:#DF2A3F;">（最新的）</font>
+ **IMAGE ID：**镜像ID

<font style="color:#DF2A3F;">（可用于指定特定的镜像）</font>

+ **CREATED：**镜像创建时间
+ **SIZE：**镜像大小

**基础操作记录：**

![image](https://cdn.nlark.com/yuque/0/2025/png/61384029/1760537691930-8027d0cb-8b93-4f82-8f71-0a329c0a6ded.png)  
![image](https://cdn.nlark.com/yuque/0/2025/png/61384029/1760537692135-f82edf9c-f4c2-4923-b38f-9e2f2c0cc6ed.png)  
![image](https://cdn.nlark.com/yuque/0/2025/png/61384029/1760537691937-ab1666ab-cfc7-4723-81b9-d20ae7324a43.png)  

3.相关参数：docker run --name后面可以给容器起一个自定义的名字（整个宿主机唯一，不能重复

![](https://cdn.nlark.com/yuque/0/2025/png/61384029/1760546871474-87eb973a-5431-47d0-b9f0-b2b453841d03.png)

观察names变化

名字与ID作用等价

例如docker rm <名字>

#### （2）端口映射
docker run <font style="color:#DF2A3F;">-p</font> 80:80:**<font style="color:#DF2A3F;">-p的作用是端口映射</font>**

**语法：**`**docker run -p <外部访问的端口>:<容器内部的端口>**`

<font style="color:#000000;">每个docker容器都运行在一个独立的虚拟环境里，容器的网络与宿主机是隔离的，默认情况下并不能从宿主机访问到docker的内部网络，这时候我们需要添加一个启动参数，把容器的端口与宿主机的端口进行一个映射或者说绑定</font>

<font style="color:#000000;">-p 80:80</font>

<font style="color:#000000;">冒号前后各填写一个端口，前为宿主机的端口，后面为容器内的端口</font>

#### <font style="color:#000000;">（3）卷</font>
概念解析：

在 Docker 中，**卷（Volume）** 是一种专门用于**数据持久化和共享**的机制， Docker 管理的、独立于容器生命周期的**持久化数据存储区域**。

形象化：

+ **容器** = 员工的办公电脑
+ **卷** = 公司提供的共享云盘（如Google Drive、OneDrive）
+ **数据** = 工作文件

与-p参数类似，-v是**把宿主机与容器的文件目录进行绑定**，容器内对这个文件夹的修改会影响宿主机的文件夹，反之亦然，宿主机与容器通过这个目录紧密联系到了一起，这种目录也被称为**挂载卷**

**挂载卷的最大作用是数据的持久化保存，使用挂载卷，删除容器时保证数据不会被删除**

**-v 宿主机目录：容器内目录———绑定挂载**

**创建一个存储空间（命名卷）**

**-v 卷的名字：容器内目录）———命名卷挂载**

相关命令：

 docker volume list:列出所有创建过的卷

docker volume rm :可以删除一个卷

docker volume prune -a:删除所有没有任何容器在使用的卷

## 三.dockerfile 编写
### （1）dockerfile是什么
Dockerfile 是一个文本文件，里面包含了一系列的**指令(Instruction)**，每一条指令都会构建一层镜像。Docker 引擎通过读取这些指令，自动构建出最终的 Docker 镜像。

### （2）dockerfile结构
#### 1. 基础镜像信息 
几乎所有 Dockerfile 都以 `FROM` 指令开始，它指定了构建新镜像所基于的基础镜像。

dockerfile

FROM ubuntu:20.04

+ **说明**：这就像是盖房子打地基。你基于一个已有的、稳定的镜像（如 Ubuntu、Alpine、Python、Node.js 等）开始构建，而不是从零开始。

<font style="color:#DF2A3F;">这是 Dockerfile 的</font>**<font style="color:#DF2A3F;">必需指令</font>**<font style="color:#DF2A3F;">，必须是第一条有效指令</font>

---

#### 2. 维护者信息 (Maintainer) - 已弃用，推荐使用 LABEL
这个指令用来标识镜像的作者，但现在更推荐使用 `LABEL` 指令。

dockerfile

```plain
# 旧方式 (已弃用)
MAINTAINER Your Name <your_email@example.com>

# 新推荐方式
LABEL maintainer="Your Name <your_email@example.com>"
```

<font style="color:#DF2A3F;">解释：添加了一个名为 </font>`<font style="color:#DF2A3F;">maintainer</font>`<font style="color:#DF2A3F;"> 的标签，值为 </font>`<font style="color:#DF2A3F;">dev@example.com</font>`<font style="color:#DF2A3F;">。这有助于其他人知道谁维护这个镜像。</font>

---

### 3. 元数据信息 (Metadata)
使用 `LABEL` 指令为镜像添加元数据，是键值对的形式。

dockerfile

```plain
LABEL version="1.0"
LABEL description="This is a custom webserver image"
```

:::warning
元数据：

**元数据（Metadata）** 是“关于数据的数据”，即用来描述其他数据的特征、属性或信息的数据。它提供了对数据内容、结构、来源、使用方式等的附加信息，帮助用户更好地理解、管理和利用数据。  
简单来说，元数据是为数据提供上下文的信息。例如，一本书的内容是数据，而书的标题、作者、出版日期、ISBN号等就是元数据。

:::

---

### 4. 构建时的环境配置和准备工作
在构建过程中，我们经常需要安装软件、设置环境变量等。

`**ENV**`** (设置环境变量)**：设置的环境变量在构建阶段和最终的容器运行时都可用。

+ dockerfile

```plain
ENV NODE_ENV=production
ENV APP_PORT=8080
```

`**RUN**`** (执行命令)**：在构建镜像时执行的命令，常用于安装软件包、创建目录等。

dockerfile

```plain
# 更新包管理器并安装软件 (以 Ubuntu 为例)
RUN apt-get update && apt-get install -y \
    python3 \
    python3-pip \
    nginx

# 使用 && 连接命令可以减少镜像层数，并使用 \ 换行提高可读性。
```

`**WORKDIR**`** (设置工作目录)**：相当于 `cd` 命令，设置后续指令（如 `RUN`, `CMD`, `COPY` 等）的工作目录。如果目录不存在，会自动创建。

dockerfile

```plain
WORKDIR /app
# 之后的 RUN, COPY 等指令都会在 /app 目录下执行
```

---

### 5. 复制文件/目录到镜像中
将构建上下文（你运行 `docker build` 命令的目录）中的文件复制到镜像里。

`**COPY**`** (复制文件)**：

+ dockerfile

```plain
# 复制当前目录下的所有文件到镜像的 /app 目录
COPY . /app

# 复制特定的文件
COPY requirements.txt /app/
```

+ `**ADD**`** (高级复制)**：功能与 `COPY` 类似，但增加了一些功能，比如：
    - 可以自动解压 tar 归档文件。
    - 可以从 URL 下载文件。
    - **最佳实践**：除非你需要 `ADD` 的特殊功能，否则一律使用 `COPY`，因为它更透明、可预测。

---

### 6. 声明运行时需要的参数
这些指令主要影响容器的运行行为。

`**EXPOSE**`** (暴露端口)**：声明容器在运行时监听的端口。**这只是一个文档说明，并不会自动发布端口**。真正的端口发布需要在 `docker run` 时使用 `-p` 参数。

+ dockerfile

```plain
EXPOSE 80
EXPOSE 443
```

---

### 7. 定义容器启动时执行的命令
这是决定容器**最终行为**的关键指令。

`**CMD**`** (容器启动命令)**：指定容器**启动时**默认运行的命令。一个 Dockerfile 中只能有一个 `CMD` 指令，如果有多条，则只有最后一条生效。

    - **形式**：有三种形式，但推荐使用 **exec 形式** (`["可执行文件", "参数1", "参数2"]`)。
+ dockerfile

```plain
# Exec 形式 (推荐)
CMD ["python3", "app.py"]

# Shell 形式
CMD python3 app.py

# 作为 ENTRYPOINT 的默认参数
CMD ["--help"]
```

`**ENTRYPOINT**`** (入口点)**：也用于指定容器启动时运行的命令，但它的优先级更高，并且不容易被 `docker run` 后面的参数覆盖。通常用于将容器设置为一个可执行程序。

+ `CMD` 和 `ENTRYPOINT` 可以组合使用，`CMD` 的内容会作为 `ENTRYPOINT` 的默认参数。

dockerfile

```plain
# 设置 ENTRYPOINT
ENTRYPOINT ["nginx"]

# 设置 CMD 作为 ENTRYPOINT 的默认参数
CMD ["-g", "daemon off;"]
```

    - 这样构建的镜像，直接 `docker run my-image` 会执行 `nginx -g 'daemon off;'`。
    - 而 `docker run my-image -c /etc/nginx/nginx.conf` 则会执行 `nginx -c /etc/nginx/nginx.conf`，`CMD` 的内容被覆盖了。

---

### 8.实践记录
（1）编写一份dockerfile

在主目录中/app下创建dockerfile文件，使用<font style="color:#DF2A3F;">touch dockerfile</font>命令，注意不要有文件名后缀！

![](https://cdn.nlark.com/yuque/0/2025/png/61384029/1760613573933-795f119b-e936-4d57-99cf-23c528790e6d.png)

使用一个编辑器编写

![](https://cdn.nlark.com/yuque/0/2025/png/61384029/1760613700306-b976079b-af6e-4db9-8bc6-a03e8135cca4.png)

创建容器

![](https://cdn.nlark.com/yuque/0/2025/png/61384029/1760617874624-694095d9-527c-4e12-a03e-6dbe91fb5b99.png)

运行容器（-d在后台，所以显示ID号）

![](https://cdn.nlark.com/yuque/0/2025/png/61384029/1760617522258-914a5354-fe1d-433a-a42c-23bb332157d2.png)



![](https://cdn.nlark.com/yuque/0/2025/png/61384029/1760617522315-0f7eae85-04b6-4126-bf1b-0352e5e99db3.png)![](https://cdn.nlark.com/yuque/0/2025/png/61384029/1760617522480-2ba955b7-13cc-4faa-93b0-a1c697903172.png)![](https://cdn.nlark.com/yuque/0/2025/png/61384029/1760617522699-11b5bde4-25b0-4e93-8df1-717245632cda.png)



![](https://cdn.nlark.com/yuque/0/2025/png/61384029/1760617692488-86522889-a343-4e67-ac13-854ccf2a0676.png)

### ![](https://cdn.nlark.com/yuque/0/2025/png/61384029/1760617710975-dd0ed102-1719-4d33-b247-06b170b16a09.png)总结
Dockerfile 的结构遵循一个清晰的逻辑流程：

1. **从哪开始？** (`FROM`)
2. **需要什么环境？** (`ENV`, `RUN`)
3. **我的代码/文件在哪？** (`WORKDIR`, `COPY`)
4. **如何运行？** (`EXPOSE`, `CMD`/`ENTRYPOINT`)





