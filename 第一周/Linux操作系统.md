### 
#### 打开终端 (Terminal)
**命令**: `ctrl + alt + T`

**作用**: 这是打开 Ubuntu 系统命令行界面（称为“终端”或“Terminal”）的快捷键。终端是与操作系统进行文字交互的核心工具，可以通过输入命令来安装软件、运行程序、管理文件等。

## 一.终端命令
## （1）软件安装
### 1.apt
:::info
ubuntu中用于管理软件的工具，“应用商店”

:::

**1.1更新软件源列表**

```plain
sudo apt update
```

<font style="color:#DF2A3F;">sudo：</font>以管理员权限执行后面的命令；

<font style="color:#DF2A3F;">apt</font>：ubuntu中用于管理软件的工具，“应用商店”

<font style="color:#DF2A3F;">update</font>：不是更新软件本身，而是刷新“软件源列表”获取一份当前所有可用软件及其最新版本号的清单

理解：去超市购物前，先打开手机 App 查看一下超市今天有哪些商品在售，以及它们的价格但并不真正购买。

1**.2升级已安装的软件**

```plain
sudo apt-get upgrade
```

<font style="color:#DF2A3F;">apt-get</font>: 是另一个较早的软件包管理命令，功能与 `apt` 类似，`upgrade` 是它的一个核心功能。

<font style="color:#DF2A3F;">upgrade: </font>这个指令会根据 `apt update` 获取到的最新清单，对比你系统中已安装的软件，然后将所有可以升级的软件升级到最新版本。

### 2.snap
:::info
`snap` 是 Ubuntu 中一个很重要的软件包管理工具

:::

1. 搜索软件包

```plain
snap find [软件名]
```

e.g.

```plain
 snap find firefox
名称        版本    发布者    备注    摘要
firefox     latest    mozilla✓    -     Mozilla Firefox
```



2. 安装软件



```plain
sudo snap install [软件名]
# 示例：安装 Firefox
sudo snap install firefox
2025-01-08T21:50:12+08:00 INFO Waiting for automatic snapd restart...
firefox 128.0.2 from Mozilla✓ installed
```

3. 列出已安装的 Snap 软件



```plain
snap list
名称        版本        修订    发布者    备注
core22      20240111    1001    canonical✓    base
firefox     128.0.2     4006    mozilla✓    -
```

4. 更新 Snap 软件



```plain
# 更新单个软件
sudo snap refresh [软件名]

# 更新所有 Snap 软件
sudo snap refresh
```

5. 卸载软件



```plain
sudo snap remove [软件名]
# 示例：卸载 Firefox
sudo snap remove firefox
firefox 已移除
```

来自粘贴：liuwanyun@LWY:~$ snap list

名称                         版本                              修订版本   追踪               发布者         注记

bare                       1.0                             5      latest/stable    canonical✓  base

code                       03c265b1                        210    latest/stable    vscode✓     classic

core20                     20250730                        2669   latest/stable    canonical✓  base

core22                     20250822                        2133   latest/stable    canonical✓  base

firefox                    143.0.4-1                       6966   latest/stable/…  mozilla✓    -

gnome-42-2204              0+git.837775c-sdk0+git.7b07595  226    latest/stable/…  canonical✓  -

gtk-common-themes          0.1-81-g442e511                 1535   latest/stable/…  canonical✓  -

snap-store                 41.3-72-g80e7130                1216   latest/stable/…  canonical✓  -

snapd                      2.71                            25202  latest/stable    canonical✓  snapd

snapd-desktop-integration  0.9                             315    latest/stable/…  canonical✓  -

---

## （2）文件管理
### 1.ls-列出<font style="color:#DF2A3F;">目录*</font>内容
:::color2
*目录

**目录** 就是 **文件夹**！在Windows和macOS中叫"文件夹"，在Linux中叫"目录"，它们是同一个概念

详见后续章节

:::



```plain
# 列出当前目录内容
ls
桌面  文档  下载  音乐  图片

# 详细列表
ls -l
总用量 32
drwxr-xr-x 2 ltmvenyun ltmvenyun 4096 1月  8 21:45 桌面
drwxr-xr-x 2 ltmvenyun ltmvenyun 4096 1月  8 21:45 文档
drwxr-xr-x 2 ltmvenyun ltmvenyun 4096 1月  8 21:45 下载

# 显示隐藏文件（以 . 开头的文件）
ls -a
.  ..  .bashrc  .config  桌面  文档

# 人类可读的文件大小
ls -lh
```

![](https://cdn.nlark.com/yuque/0/2025/png/61384029/1760258083925-2ec10095-98be-444f-b279-5063c0397125.png)

---

### 2. `cp` - 复制文件和目录
```plain
# 复制文件
cp file1.txt file2.txt

# 复制文件到指定目录
cp file1.txt /home/ltmvenyun/文档/

# 复制目录（需要 -r 递归参数）
cp -r dir1 dir2

# 交互式*复制（询问是否覆盖）
cp -i file1.txt file2.txt
cp：是否覆盖'file2.txt'？ y

# 显示复制进度
cp -v file1.txt file2.txt
'file1.txt' -> 'file2.txt'
```

:::color2
*交互式

**交互式** 就是在执行命令时，系统会**询问你是否确认**，等你回答后再继续执行。这是一种安全保护机制。

:::

```plain
# 普通删除 - 直接删除，没有警告
rm file.txt
（文件瞬间消失，没有提示）

# 交互式删除 - 会询问确认
rm -i file.txt
rm：是否删除普通文件 'file.txt'？
```

:::color2
**这时终端会等待你的输入：**

+ 输入 `y` 或 `yes` → 删除文件
+ 输入 `n` 或 `no` → 取消删除
+ 输入其他任何内容 → 通常也视为取消

:::

![](https://cdn.nlark.com/yuque/0/2025/png/61384029/1760260001060-32519241-7b51-4e32-8d4b-4a19b9f66d9a.png)



![](https://cdn.nlark.com/yuque/0/2025/png/61384029/1760258854977-451d1528-3512-4422-8c7c-9b2fd7e316ff.png)

![](https://cdn.nlark.com/yuque/0/2025/png/61384029/1760258883587-bf4878dc-f33f-40f7-a563-f185707c8385.png)

---

### 3. `mv` - 移动或重命名文件和目录
```plain
# 重命名文件
 mv oldname.txt newname.txt

# 移动文件到其他目录
 mv file.txt /home/ltmvenyun/文档/

# 移动并重命名
 mv file.txt /home/ltmvenyun/文档/newfile.txt

# 移动目录（不需要 -r 参数）
 mv dir1 /home/ltmvenyun/文档/

# 交互式移动
 mv -i file1.txt file2.txt
```

![](https://cdn.nlark.com/yuque/0/2025/png/61384029/1760259468073-e78671e0-a566-4d1e-8f1e-2c2a1bcdff60.png)

![](https://cdn.nlark.com/yuque/0/2025/png/61384029/1760259458158-803e1808-7005-49de-a323-31b8425e0a9d.png)

---

### 4. `rm` - 删除文件和目录
### ⚠️ 警告：rm 删除的文件无法恢复！
```plain
# 删除文件
rm file.txt

# 删除目录（需要 -r 递归参数）
 rm -r directory/

# 强制删除（不询问）
rm -f file.txt

# 交互式删除（推荐使用）
rm -i file.txt
rm：是否删除普通文件 'file.txt'？ y

# 删除空目录
rmdir empty_directory/
```

---

### 5. `touch` - 创建空文件或更新文件时间
```plain
# 创建新文件
touch newfile.txt

# 创建多个文件
touch file1.txt file2.txt file3.txt

# 更新文件的访问和修改时间
touch existing_file.txt
```

![](https://cdn.nlark.com/yuque/0/2025/png/61384029/1760258483078-eaa7c225-5bc7-4284-9977-de18d696f755.png)

---

### `6.mkdir` - 创建目录
```plain
# 创建单个目录
mkdir new_directory

# 创建多级目录
mkdir -p parent/child/grandchild

# 创建带权限的目录
mkdir -m 755 shared_directory
```

![](https://cdn.nlark.com/yuque/0/2025/png/61384029/1760260563311-e17c1fcd-7c86-4b5a-93e0-4947a52d3f4a.png)

### `7.cat` - 查看文件内容
```plain
# 查看文件内容
cat file.txt

# 查看多个文件
cat file1.txt file2.txt

# 创建简单文件
cat > newfile.txt
（输入内容，按 Ctrl+D 保存）
```

![](https://cdn.nlark.com/yuque/0/2025/png/61384029/1760261165275-8d4e1066-c15c-4b0d-89ab-064a48c9b8cc.png)

### `8.pwd` - 显示当前目录
```plain
ltmvenyun@LMY:~$ pwd
/home/ltmvenyun
```

### `9.cd` - 切换目录
bash

```plain
# 切换到 home 目录
 cd
 cd ~

# 切换到上级目录
cd ..

# 切换到指定目录
cd /home/liuwanyun/文档

# 切换到上一个目录
cd -
```

---

## (3)   权限管理<font style="background:#F8CED3;color:#70000D">不太会</font>
权限管理就是决定 "谁可以对文件/目录做什么" 的一套规则系统

:::color2
#### Linux 中的三种权限
#### 1. 读权限 (r) - 4
+ **文件**：可以查看文件内容
+ **目录**：可以列出目录中的文件名

#### 2. 写权限 (w) - 2
+ **文件**：可以修改、删除文件内容
+ **目录**：可以在目录中创建、删除文件

#### 3. 执行权限 (x) - 1
+ **文件**：可以运行这个程序/脚本
+ **目录**：可以进入这个目录

:::

    

### 1. `ls -l` - 查看文件权限
#### 理解 `ls -l` 的输出：
```plain
liuwanyun@LWY:~$ ls -l

```

![](https://cdn.nlark.com/yuque/0/2025/png/61384029/1760263417972-c83a7b6a-7205-4ebb-8270-4cf3993628dd.png)

#### 权限字段分解：
```plain
drwxr-xr-x
↑ ↑↑↑ ↑↑↑ ↑↑↑
| ||| ||| |||
| ||| ||| ||+-- 其他用户权限
| ||| ||| |+--- 组用户权限  
| ||| ||| +---- 所有者权限
| ||| ||+------ 粘滞位
| ||| |+------- 设置组ID
| ||| +-------- 设置用户ID
| ||+---------- 可执行权限
| |+----------- 写权限
| +------------ 读权限
+-------------- 文件类型 (-=文件, d=目录, l=链接)
```

#### 权限符号说明：
| 位置 | 用户类型 | 说明 |
| --- | --- | --- |
| 2-4 | 所有者(user) | 文件所有者的权限 |
| 5-7 | 所属组(group) | 文件所属用户组的权限 |
| 8-10 | 其他用户(other) | 其他所有用户的权限 |


| 权限 | 符号 | 数字 | 文件权限 | 目录权限 |
| --- | --- | --- | --- | --- |
| 读 | r | 4 | 查看内容 | 列出文件 |
| 写 | w | 2 | 修改内容 | 创建/删除文件 |
| 执行 | x | 1 | 执行程序 | 进入目录 |


### 2. `chmod` - 修改文件权限
#### 数字方式（最常用）：
```plain
# 基本权限设置
liuwanyun@LWY:~$ chmod 755 script.sh
liuwanyun@LWY:~$ chmod 644 document.txt
liuwanyun@LWY:~$ chmod 700 private_file.txt
```

#### 常见权限数字：
| 权限 | 数字 | 说明 | 适用场景 |
| --- | --- | --- | --- |
| 755 | rwxr-xr-x | 所有者可读写执行，其他只读执行 | 可执行脚本、程序 |
| 644 | rw-r--r-- | 所有者可读写，其他只读 | 普通文件、文档 |
| 777 | rwxrwxrwx | 所有用户完全权限 | 临时文件（危险！） |
| 700 | rwx------ | 只有所有者有权限 | 私人文件 |


#### 符号方式：
```plain
# 添加执行权限给所有者
liuwanyun@LWY:~$ chmod u+x script.sh

# 添加写权限给组用户
liuwanyun@LWY:~$ chmod g+w document.txt

# 移除其他用户的读权限
liuwanyun@LWY:~$ chmod o-r secret.txt

# 设置所有用户都有读权限
liuwanyun@LWY:~$ chmod a+r public.txt
```

#### 符号说明：
+ `u` = 所有者(user)
+ `g` = 组用户(group)
+ `o` = 其他用户(other)
+ `a` = 所有用户(all)
+ `+` = 添加权限
+ `-` = 移除权限
+ `=` = 设置权限

### 3. `chown` - 修改文件所有者
```plain
# 修改文件所有者
liuwanyun@LWY:~$ sudo chown newuser file.txt

# 修改文件所有者和组
liuwanyun@LWY:~$ sudo chown newuser:newgroup file.txt

# 只修改组
liuwanyun@LWY:~$ sudo chown :newgroup file.txt

# 递归修改目录下所有文件
liuwanyun@LWY:~$ sudo chown -R liuwanyun:liuwanyun 我的项目/
```

### 4.权限位
#### 基本结构：
text

```plain
rwx rwx rwx
↑   ↑   ↑
|   |   |
|   |   +-- 其他用户权限 (other)
|   +------ 组用户权限 (group)  
+---------- 所有者权限 (user)
```

#### 实际例子：
```plain
liuwanyun@LWY:~$ ls -l script.sh
-rwxr-xr-x 1 liuwanyun liuwanyun 845 1月  9 10:35 script.sh
```

这里的 `rwxr-xr-x` 就是权限位。

#### 权限位的三种表示方法
#### 方法1：符号表示（人类可读）
text

```plain
rwxr-xr--
↓↓↓ ↓↓↓ ↓↓↓
||| ||| |||
||| ||| |+-- 其他用户：读(无) 写(无) 执行(无)  
||| ||| +--- 其他用户：读(r) 写(-) 执行(-)
||| ||+----- 组用户：读(r) 写(-) 执行(x)
||| |+------ 组用户：读(r) 写(-) 执行(x)
||| +------- 所有者：读(r) 写(w) 执行(x)
||+--------- 所有者：读(r) 写(w) 执行(x)
|+---------- 所有者：读(r) 写(w) 执行(x)
+----------- 文件类型 (- = 普通文件)
```

#### 方法2：二进制表示（计算机理解）
text

```plain
rwx r-x r--
↓↓↓ ↓↓↓ ↓↓↓
111 101 100
```

#### 方法3：八进制表示（数字表示）
text

```plain
rwx r-x r--
↓↓↓ ↓↓↓ ↓↓↓  
111 101 100
↓   ↓   ↓
7   5   4
```

#### 权限位的详细分解
##### 第一组：所有者权限 (user)
| 位置 | 权限 | 含义 | 数字值 |
| --- | --- | --- | --- |
| 第1位 | r | 所有者读权限 | 4 |
| 第2位 | w | 所有者写权限 | 2 |
| 第3位 | x | 所有者执行权限 | 1 |


##### 第二组：组权限 (group)
| 位置 | 权限 | 含义 | 数字值 |
| --- | --- | --- | --- |
| 第4位 | r | 组用户读权限 | 4 |
| 第5位 | w | 组用户写权限 | 2 |
| 第6位 | x | 组用户执行权限 | 1 |


##### 第三组：其他用户权限 (other)
| 位置 | 权限 | 含义 | 数字值 |
| --- | --- | --- | --- |
| 第7位 | r | 其他用户读权限 | 4 |
| 第8位 | w | 其他用户写权限 | 2 |
| 第9位 | x | 其他用户执行权限 | 1 |


#### 权限位计算示例
##### 示例1：`rwxr-xr--` (754)
text

```plain
所有者: rwx = 4+2+1 = 7
组用户: r-x = 4+0+1 = 5  
其他用户: r-- = 4+0+0 = 4
结果：754
```

##### 示例2：`rw-r--r--` (644)
text

```plain
所有者: rw- = 4+2+0 = 6
组用户: r-- = 4+0+0 = 4
其他用户: r-- = 4+0+0 = 4
结果：644
```

##### 示例3：`rw-------` (600)
text

```plain
所有者: rw- = 4+2+0 = 6
组用户: --- = 0+0+0 = 0
其他用户: --- = 0+0+0 = 0
结果：600
```

#### 特殊权限位
除了基本的 9 个权限位，还有 3 个特殊权限位：

##### 1. setuid (Set User ID) - 第10位
bash

```plain
# 设置 setuid（用 s 表示）
liuwanyun@LWY:~$ chmod u+s program
liuwanyun@LWY:~$ ls -l program
-rwsr-xr-x 1 root root 845 1月  9 10:35 program
# 程序运行时以文件所有者的权限执行（通常是root）
```

##### 2. setgid (Set Group ID) - 第11位
bash

```plain
# 设置 setgid
liuwanyun@LWY:~$ chmod g+s directory
liuwanyun@LWY:~$ ls -ld directory
drwxr-sr-x 2 liuwanyun liuwanyun 4096 1月  9 10:35 directory
# 在目录中创建的文件自动继承目录的组权限
```

##### 3. sticky bit (粘滞位) - 第12位
bash

```plain
# 设置粘滞位（用 t 表示）
liuwanyun@LWY:~$ chmod +t shared_dir
liuwanyun@LWY:~$ ls -ld /tmp
drwxrwxrwt 10 root root 4096 1月  9 10:35 /tmp
# 只有文件所有者和root可以删除文件
```

#### 权限位的实际应用
##### 查看权限位：
bash

```plain
liuwanyun@LWY:~$ ls -l
-rwxr-xr-x 1 liuwanyun liuwanyun  845 1月  9 10:35 script.sh
-rw-r--r-- 1 liuwanyun liuwanyun   19 1月  9 10:32 document.txt
-rw------- 1 liuwanyun liuwanyun  256 1月  9 10:30 secret.txt
drwxr-xr-x 2 liuwanyun liuwanyun 4096 1月  9 10:30 my_dir
```

##### 修改权限位：
bash

```plain
# 数字方式
liuwanyun@LWY:~$ chmod 755 script.sh    # rwxr-xr-x
liuwanyun@LWY:~$ chmod 644 document.txt # rw-r--r--
liuwanyun@LWY:~$ chmod 700 secret.txt   # rwx------

# 符号方式
liuwanyun@LWY:~$ chmod u+x script.sh    # 给所有者添加执行权限
liuwanyun@LWY:~$ chmod go-w document.txt # 移除组和其他用户的写权限
```

#### 权限位与文件类型
第一个字符表示文件类型：

| 字符 | 文件类型 | 示例 |
| --- | --- | --- |
| `-` | 普通文件 | `-rw-r--r--` |
| `d` | 目录 | `drwxr-xr-x` |
| `l` | 符号链接 | `lrwxrwxrwx` |
| `b` | 块设备文件 | `brw-rw----` |
| `c` | 字符设备文件 | `crw-rw----` |


#### 权限位总结表
| 权限位 | 符号 | 数字 | 含义 |
| --- | --- | --- | --- |
| 所有者读 | r | 4 | 文件所有者可以读文件 |
| 所有者写 | w | 2 | 文件所有者可以写文件 |
| 所有者执行 | x | 1 | 文件所有者可以执行文件 |
| 组读 | r | 4 | 组用户可以读文件 |
| 组写 | w | 2 | 组用户可以写文件 |
| 组执行 | x | 1 | 组用户可以执行文件 |
| 其他读 | r | 4 | 其他用户可以读文件 |
| 其他写 | w | 2 | 其他用户可以写文件 |
| 其他执行 | x | 1 | 其他用户可以执行文件 |


#### 简单记忆方法
**记住这三个数字：**

+ **4** = 读 (Read)
+ **2** = 写 (Write)
+ **1** = 执行 (eXecute)

**组合计算：**

+ 7 = 4+2+1 = 读 + 写 + 执行
+ 6 = 4+2+0 = 读 + 写
+ 5 = 4+0+1 = 读 + 执行
+ 4 = 4+0+0 = 只读

---

## （4）进程控制
**进程控制**就是管理和控制系统中正在运行的**程序实例**。简单说，就是管理"正在运行的程序"。

### 1. `ps` - 查看进程状态
```plain
# 查看当前终端相关的进程
liuwanyun@LWY:~$ ps
 
# 查看所有进程（最常用）
liuwanyun@LWY:~$ ps aux

```

![](https://cdn.nlark.com/yuque/0/2025/png/61384029/1760265633228-1158f07e-dac6-4b88-8f9c-e4e0b170dcf8.png)

### 2. `kill` - 终止进程
#### 基本用法：
```plain
# 优雅地终止进程（发送 TERM 信号）
liuwanyun@LWY:~$ kill 1234

# 强制终止进程（发送 KILL 信号）
liuwanyun@LWY:~$ kill -9 1234

# 终止所有指定名称的进程
liuwanyun@LWY:~$ killall firefox

# 通过名称查找并终止
liuwanyun@LWY:~$ pkill firefox
```

#### 常用信号：
| 信号 | 数字 | 含义 | 使用场景 |
| --- | --- | --- | --- |
| TERM | 15 | 终止（默认） | 正常关闭程序 |
| KILL | 9 | 强制终止 | 程序无响应时 |
| HUP | 1 | 挂起 | 重新加载配置 |
| INT | 2 | 中断 | Ctrl+C |


### 3. `top` - 实时进程监控
#### 启动 top：
```plain
liuwanyun@LWY:~$ top
top - 10:35:45 up 2:30,  1 user,  load average: 0.15, 0.20, 0.25
Tasks: 250 total,   1 running, 249 sleeping,   0 stopped,   0 zombie
%Cpu(s):  2.5 us,  1.2 sy,  0.0 ni, 96.0 id,  0.3 wa,  0.0 hi,  0.0 si,  0.0 st
MiB Mem :  15927.8 total,   4523.2 free,   6789.1 used,   4615.5 buff/cache
MiB Swap:   2048.0 total,   2048.0 free,      0.0 used.   8654.2 avail Mem 

  PID USER      PR  NI    VIRT    RES    SHR S  %CPU  %MEM     TIME+ COMMAND
 2345 liuwanyun 20   0 1023456 812344 245688 S   5.2   5.0   2:34.67 firefox
 1234 liuwanyun 20   0   25364  19240  14568 S   0.3   0.1   0:01.23 bash
    1 root      20   0  169284  13156   8456 S   0.0   0.1   0:01.45 systemd
```

#### top 界面操作：
| 按键 | 功能 |
| --- | --- |
| `q` | 退出 top |
| `k` | 终止进程（输入PID） |
| `r` | 调整进程优先级 |
| `M` | 按内存使用排序 |
| `P` | 按CPU使用排序 |
| `1` | 显示所有CPU核心 |
| `h` | 显示帮助 |


#### top 输出详解：
+ **第一行**：系统时间、运行时间、负载
+ **第二行**：进程统计（总数、运行中、睡眠等）
+ **第三行**：CPU使用情况
+ **第四行**：内存使用
+ **第五行**：交换空间
+ **列表**：进程详细信息

### 4. `systemctl` - 系统服务管理
#### 基本用法：
bash

```plain
# 查看服务状态
liuwanyun@LWY:~$ systemctl status ssh
● ssh.service - OpenBSD Secure Shell server
   Loaded: loaded (/lib/systemd/system/ssh.service; enabled; vendor preset: enabled)
   Active: active (running) since Mon 2025-01-09 10:30:45 CST; 2h ago
     Docs: man:sshd(8)
 Main PID: 789 (sshd)
    Tasks: 1 (limit: 4915)
   Memory: 5.2M
   CGroup: /system.slice/ssh.service
           └─789 /usr/sbin/sshd -D
```

#### 服务管理命令：
bash

```plain
# 启动服务
liuwanyun@LWY:~$ sudo systemctl start service_name

# 停止服务
liuwanyun@LWY:~$ sudo systemctl stop service_name

# 重启服务
liuwanyun@LWY:~$ sudo systemctl restart service_name

# 重新加载配置（不重启）
liuwanyun@LWY:~$ sudo systemctl reload service_name

# 查看服务状态
liuwanyun@LWY:~$ systemctl status service_name

# 启用开机自启
liuwanyun@LWY:~$ sudo systemctl enable service_name

# 禁用开机自启
liuwanyun@LWY:~$ sudo systemctl disable service_name
```

#### 常用服务示例：
bash

```plain
# 网络服务
liuwanyun@LWY:~$ sudo systemctl restart networking

# SSH 服务
liuwanyun@LWY:~$ sudo systemctl restart ssh

# Apache/Nginx 网页服务
liuwanyun@LWY:~$ sudo systemctl restart apache2
liuwanyun@LWY:~$ sudo systemctl restart nginx

# 数据库服务
liuwanyun@LWY:~$ sudo systemctl restart mysql
```

---

## 二.“一切皆文件”的理解
在 Linux 系统中，**几乎所有东西都可以像普通文件一样进行读写操作**

在 Linux 中：

+ **普通文件** → 可以用文件操作命令处理
+ **硬件设备** → 可以用文件操作命令处理(<font style="color:#DF2A3F;">例如下图中的disk，cpu，input等硬件设备均被系统写为文件管理）</font>
+ **进程信息** → 可以用文件操作命令处理
+ **网络连接** → 可以用文件操作命令处理

![](https://cdn.nlark.com/yuque/0/2025/png/61384029/1760270057438-9159b475-85f0-4a41-a53e-6c3bc4ad59a2.png)

---

## 三.文件系统结构
### 1.核心结构概览
```plain
/
├── bin/          # 基本命令程序
├── boot/         # 启动相关文件
├── dev/          # 设备文件
├── etc/          # 系统配置文件
├── home/         # 用户主目录
│   └── liuwanyun/ # 你的个人文件
├── proc/         # 进程信息
├── root/         # root用户主目录
├── sbin/         # 系统管理命令
├── tmp/          # 临时文件
├── usr/          # 用户程序和数据
├── var/          # 经常变化的文件
└── ...
```

![](https://cdn.nlark.com/yuque/0/2025/png/61384029/1760270122843-6d7502d2-ae0c-4cfe-9ece-6ae14a0d371a.png)

### 2./-根目录
**作用**：整个文件系统的起点和根基

```plain
liuwanyun@LWY:~$ ls /
bin   boot  dev  etc  home  lib   lib64  media  mnt  opt  proc  root  run  sbin  srv  tmp  usr  var
```

**包含**：所有其他目录的父目录  
**重要性**：系统无法启动如果根目录损坏

### 3. `/bin` - 基本命令二进制文件
**作用**：存放系统最基本的命令

```plain
liuwanyun@LWY:~$ ls /bin
ls  cp  mv  rm  cat  echo  bash  chmod  chown  date  kill  ps
```

![](https://cdn.nlark.com/yuque/0/2025/png/61384029/1760270595488-57d61f97-db0c-4d4e-b093-5a5fe38c045a.png)

### 4. `/sbin` - 系统管理命令
**作用**：系统管理员使用的命令

<font style="color:#DF2A3F;">s是super user的意思</font>

```plain
liuwanyun@LWY:~$ ls /sbin
fdisk  fsck  ifconfig  init  iptables  reboot  shutdown
```

**包含**：`fdisk`, `fsck`, `ifconfig`, `reboot` 等  
**特点**：通常需要 root 权限执行

### 5. `/home` - 用户主目录
**作用**：普通用户的个人文件存储空间

```plain
liuwanyun@LWY:~$ ls /home
liuwanyun  user2  user3

liuwanyun@LWY:~$ ls ~
桌面  文档  下载  音乐  图片  视频  .bashrc  .ssh
```

**包含**：每个用户的文档、下载、配置等  
**特点**：用户对自己的主目录有完全控制权

![](https://cdn.nlark.com/yuque/0/2025/png/61384029/1760271054973-25291c76-ba36-46c8-b4fd-ddc375597eab.png)  


### 6. `/root` - 管理员主目录
**作用**：root 用户（系统管理员）的个人目录

```plain
liuwanyun@LWY:~$ sudo ls /root
```

**包含**：root 用户的配置和文件  
**特点**：普通用户无权访问

### 7. `/etc` - 配置文件
**作用**：系统和应用程序的配置文件

```plain
liuwanyun@LWY:~$ ls /etc
passwd  group  hosts  fstab  network/  apt/  ssh/  nginx/  profile  bash.bashrc
```

**重要文件**：

+ `/etc/passwd` - 用户账户信息
+ `/etc/group` - 用户组信息
+ `/etc/hosts` - 主机名解析
+ `/etc/fstab` - 文件系统挂载表
+ `/etc/ssh/sshd_config` - SSH 服务配置

**特点**：文本文件，可以直接编辑配置

### 8. `/usr` - 用户程序
**作用**：用户安装的应用程序和文件

bash

```plain
liuwanyun@LWY:~$ ls /usr
bin/  lib/  share/  local/  include/  src/  games/
```

### 9. `/dev` - 设备文件
**作用**：硬件设备的接口文件

```plain
liuwanyun@LWY:~$ ls /dev
sda   sdb    # 硬盘
tty1  tty2   # 终端
null  zero   # 空设备
random       # 随机数生成器
```

### 10. `/boot` - 启动文件
**作用**：系统启动所需的核心文件（<font style="color:#DF2A3F;">如删除则无法启动）</font>

```plain
liuwanyun@LWY:~$ ls /boot
initrd.img-5.15.0-91-generic  vmlinuz-5.15.0-91-generic  grub/  config-5.15.0-91-generic
```

**重要文件**：

+ `vmlinuz-*` - 压缩的内核<font style="color:#DF2A3F;">镜像*</font>
+ `initrd.img-*` - 初始内存磁盘
+ `grub/` - 引导加载程序配置

:::color2
***镜像**

**系统镜像 ：**整个操作系统的"完整照片"或"完美复制品"，包含系统文件、配置、程序等所有内容

**容器镜像** ：一个轻量级的、可执行的软件包，包含运行某个软件所需的一切：代码、运行时、库、环境变量和配置文件

**软件源镜像**（下载镜像）：软件下载站点的"镜像"或"副本"，提供相同的内容但位于不同的地理位置

eg

+ **官方软件源** = 北京的总仓库
+ **清华镜像源** = 上海的分仓库（内容完全一样，但离你更近）
+ **下载软件** = 从最近的仓库取货

**虚拟机镜像** ：包含完整的虚拟机状态：操作系统、应用程序、数据、配置等

**磁盘镜像：** 是整个磁盘或分区的逐扇区复制。

:::

### 11. `/var` - 可变数据
**经常变化的文件**

```plain
liuwanyun@LWY:~$ ls /var
log/    cache/  lib/    spool/  tmp/    www/

# 查看系统日志
liuwanyun@LWY:~$ sudo tail /var/log/syslog
Jan  9 11:00:01 LWY systemd: Started Daily apt download activities.
```

![](https://cdn.nlark.com/yuque/0/2025/png/61384029/1760272396214-480f8721-8a53-41f8-847c-1d191ad5d5e7.png)

### 重要特点总结
1. **树状结构**：从 `/` 开始的一棵<font style="background-color:#FBDE28;">倒置的树</font>
2. **统一命名空间**：所有设备、文件、进程都出现在文件系统中
3. **区分大小写**：`File.txt` 和 `file.txt` 是不同的文件
4. **路径分隔符**：使用<font style="background-color:#FBDE28;">正斜杠</font> `/`（与 Windows 的反斜杠 `\` 不同）
5. **没有盘符**：不像 Windows 有 C:、D: 盘的概念

### 绝对路径&相对路径
:::color2
**路径**

路径就是找到文件的"地址"，就像现实生活中的地址一样

:::

:::color1
#### 生活比喻：
**绝对路径** = "中国北京市海淀区清华园1号清华大学"

**相对路径** = "从你现在的位置，向前走100米，左转的那栋楼"

:::

#### 1.绝对路径——<font style="color:#DF2A3F;">无需知道当前位置</font>
定义：

从根目录 `/` 开始的完整路径，无论你在什么位置，绝对路径都指向同一个文件。

特点：

1.总是以 `/` 开头

2.唯一确定一个文件或目录

3.与当前目录无关

示例：

```plain
# 查看当前目录
liuwanyun@LWY:~$ pwd
/home/liuwanyun

# 使用绝对路径访问文件（无论在哪都能找到）
liuwanyun@LWY:~$ ls /home/liuwanyun/文档/file.txt
liuwanyun@LWY:/tmp$ ls /home/liuwanyun/文档/file.txt    # 即使在/tmp目录也能找到
liuwanyun@LWY:/etc$ ls /home/liuwanyun/文档/file.txt    # 在任何目录都能找到
```

常见的绝对路径：

```plain
/home/liuwanyun/               # 你的主目录
/etc/passwd                    # 用户账户文件
/var/log/syslog                # 系统日志文件
/usr/bin/ls                    # ls命令的位置
```

#### 2. 相对路径——<font style="color:#DF2A3F;">需要知道当前位置</font>
定义：

从当前目录开始的路径，根据你当前的位置而变化。

特点：

1.不以 `/` 开头

2.依赖于当前工作目录

3.更简短方便

特殊符号：

| 符号 | 含义 | 示例 |
| --- | --- | --- |
| `.` | 当前目录 | `./file.txt` |
| `..` | 上级目录 | `../other/file.txt` |
| `~` | 用户主目录 | `~/文档/file.txt` |
| `-` | 上一个目录 | `cd -` |


#### 详细示例演示
创建一些测试文件来练习：

bash

```plain
# 1. 创建测试目录结构
liuwanyun@LWY:~$ mkdir -p 测试/目录1/目录2
liuwanyun@LWY:~$ touch 测试/file1.txt
liuwanyun@LWY:~$ touch 测试/目录1/file2.txt
liuwanyun@LWY:~$ touch 测试/目录1/目录2/file3.txt

# 2. 查看结构
liuwanyun@LWY:~$ tree 测试/
测试/
├── file1.txt
└── 目录1
    ├── file2.txt
    └── 目录2
        └── file3.txt
```

#### 练习各种路径：
bash

```plain
# 当前在主目录
liuwanyun@LWY:~$ pwd
/home/liuwanyun

# 访问 file1.txt
绝对路径: cat /home/liuwanyun/测试/file1.txt
相对路径: cat 测试/file1.txt

# 切换到目录1
liuwanyun@LWY:~$ cd 测试/目录1
liuwanyun@LWY:~/测试/目录1$ pwd
/home/liuwanyun/测试/目录1

# 访问 file2.txt (当前目录)
绝对路径: cat /home/liuwanyun/测试/目录1/file2.txt
相对路径: cat file2.txt 或 cat ./file2.txt

# 访问 file1.txt (上级目录)
绝对路径: cat /home/liuwanyun/测试/file1.txt
相对路径: cat ../file1.txt

# 访问 file3.txt (子目录)
绝对路径: cat /home/liuwanyun/测试/目录1/目录2/file3.txt
相对路径: cat 目录2/file3.txt

# 返回主目录
liuwanyun@LWY:~/测试/目录1$ cd ~
liuwanyun@LWY:~$ pwd
/home/liuwanyun
```

![](https://cdn.nlark.com/yuque/0/2025/png/61384029/1760273398598-dd04c402-0f2f-4d16-8985-9574ba033eed.png)![](https://cdn.nlark.com/yuque/0/2025/png/61384029/1760273852957-1b65a9fa-f20f-4edb-ab75-12e35b6078de.png)

## 四.服务管理
:::color1
**服务**是在后台运行的程序，提供特定功能（如网页服务、数据库服务等）

:::

### 1.systemctl - 主要的服务管理工具
#### 查看服务状态
bash

```plain
# 查看所有服务状态
liuwanyun@LWY:~$ systemctl status

# 查看特定服务状态
liuwanyun@LWY:~$ systemctl status ssh
liuwanyun@LWY:~$ systemctl status nginx
liuwanyun@LWY:~$ systemctl status apache2

# 查看输出示例：
● ssh.service - OpenBSD Secure Shell server
   Loaded: loaded (/lib/systemd/system/ssh.service; enabled; vendor preset: enabled)
   Active: active (running) since Mon 2025-01-09 10:30:45 CST; 2h ago
     Docs: man:sshd(8)
 Main PID: 789 (sshd)
    Tasks: 1 (limit: 4915)
   Memory: 5.2M
   CGroup: /system.slice/ssh.service
           └─789 /usr/sbin/sshd -D
```

#### 服务生命周期管理
bash

```plain
# 启动服务
liuwanyun@LWY:~$ sudo systemctl start service_name

# 停止服务
liuwanyun@LWY:~$ sudo systemctl stop service_name

# 重启服务
liuwanyun@LWY:~$ sudo systemctl restart service_name

# 重新加载配置（不重启服务）
liuwanyun@LWY:~$ sudo systemctl reload service_name

# 查看服务是否启用开机自启
liuwanyun@LWY:~$ systemctl is-enabled service_name

# 启用开机自启
liuwanyun@LWY:~$ sudo systemctl enable service_name

# 禁用开机自启
liuwanyun@LWY:~$ sudo systemctl disable service_name
```

#### 常用服务管理示例
bash

```plain
# SSH 服务管理
liuwanyun@LWY:~$ sudo systemctl start ssh    # 启动SSH
liuwanyun@LWY:~$ sudo systemctl stop ssh     # 停止SSH
liuwanyun@LWY:~$ sudo systemctl restart ssh  # 重启SSH
liuwanyun@LWY:~$ sudo systemctl enable ssh   # 开机自启SSH

# Web 服务管理
liuwanyun@LWY:~$ sudo systemctl start nginx
liuwanyun@LWY:~$ sudo systemctl start apache2

# 数据库服务
liuwanyun@LWY:~$ sudo systemctl start mysql
liuwanyun@LWY:~$ sudo systemctl start postgresql
```

### 2.service 命令（旧式，仍然可用）
```plain
# 与服务交互
liuwanyun@LWY:~$ sudo service ssh status
liuwanyun@LWY:~$ sudo service ssh restart
liuwanyun@LWY:~$ sudo service nginx start
```

## 五. 网络配置
### 1 查看网络信息
#### 查看IP地址和网络接口
```plain
# 现代方式（推荐）
liuwanyun@LWY:~$ ip addr show
liuwanyun@LWY:~$ ip a

# 输出示例：
1: lo: <LOOPBACK,UP,LOWER_UP> mtu 65536 qdisc noqueue state UNKNOWN group default qlen 1000
    link/loopback 00:00:00:00:00:00 brd 00:00:00:00:00:00
    inet 127.0.0.1/8 scope host lo
       valid_lft forever preferred_lft forever
2: eth0: <BROADCAST,MULTICAST,UP,LOWER_UP> mtu 1500 qdisc fq_codel state UP group default qlen 1000
    link/ether 08:00:27:3c:4d:2a brd ff:ff:ff:ff:ff:ff
    inet 192.168.1.100/24 brd 192.168.1.255 scope global dynamic noprefixroute eth0
       valid_lft 86388sec preferred_lft 86388sec

# 传统方式（仍然可用）
liuwanyun@LWY:~$ ifconfig
```

:::color1
**config** （configuration）通常指的是 **配置文件** 或 **配置操作**，用于设置软件、系统或服务的运行参数。常用于配置git  ，SSH

:::

#### 查看网络连接
```plain
# 查看所有网络连接
liuwanyun@LWY:~$ ss -tuln

# 输出示例：
Netid  State   Recv-Q  Send-Q   Local Address:Port   Peer Address:Port
udp    UNCONN  0       0        127.0.0.1:53         0.0.0.0:*
tcp    LISTEN  0       128      0.0.0.0:22           0.0.0.0:*
tcp    LISTEN  0       128      127.0.0.1:631        0.0.0.0:*

# 查看进程使用的端口
liuwanyun@LWY:~$ sudo lsof -i :22
COMMAND  PID USER   FD   TYPE DEVICE SIZE/OFF NODE NAME
sshd    1234 root    3u  IPv4  12345      0t0  TCP *:ssh (LISTEN)
```

#### 测试网络连接
bash

```plain
# 测试到目标主机的连通性
liuwanyun@LWY:~$ ping google.com
PING google.com (142.251.42.206) 56(84) bytes of data.
64 bytes from 142.251.42.206: icmp_seq=1 ttl=117 time=12.3 ms

# 查看数据包路由路径
liuwanyun@LWY:~$ traceroute google.com

# 测试特定端口连通性
liuwanyun@LWY:~$ telnet google.com 80
liuwanyun@LWY:~$ nc -zv google.com 443
```

### 2. 网络配置管理
#### 查看网络管理器状态
```plain
# 查看 NetworkManager 状态
liuwanyun@LWY:~$ systemctl status NetworkManager

# 查看网络连接配置
liuwanyun@LWY:~$ nmcli connection show
NAME                UUID                                  TYPE      DEVICE
有线连接 1          12345678-1234-1234-1234-123456789abc  ethernet  eth0
WIFI连接            abcd1234-5678-90ab-cdef-1234567890ab  wifi      wlan0
```

#### 使用 nmcli 配置网络
```plain
# 查看设备状态
liuwanyun@LWY:~$ nmcli device status
DEVICE  TYPE      STATE      CONNECTION
eth0    ethernet  已连接     有线连接 1
wlan0   wifi      已断开     --

# 连接 WiFi
liuwanyun@LWY:~$ nmcli device wifi list
liuwanyun@LWY:~$ nmcli device wifi connect "WiFi名称" password "密码"

# 断开连接
liuwanyun@LWY:~$ nmcli connection down "有线连接 1"

# 重新连接
liuwanyun@LWY:~$ nmcli connection up "有线连接 1"
```

### 3 .手动网络配置
#### 临时配置IP地址
```plain
# 为接口配置IP地址（重启后失效）
liuwanyun@LWY:~$ sudo ip addr add 192.168.1.150/24 dev eth0

# 启用/禁用网络接口
liuwanyun@LWY:~$ sudo ip link set eth0 up
liuwanyun@LWY:~$ sudo ip link set eth0 down
```

#### 配置DNS
```plain
# 查看当前DNS
liuwanyun@LWY:~$ cat /etc/resolv.conf
nameserver 8.8.8.8
nameserver 114.114.114.114

# 临时修改DNS
liuwanyun@LWY:~$ echo "nameserver 8.8.8.8" | sudo tee /etc/resolv.conf
```

:::color1
**DNS**

**DNS（Domain Name System） = 域名系统，它把难记的IP地址转换成好记的域名**

+ **DNS**** = 手机通讯录**
+ **IP地址**** = 电话号码（难记，如 **`**13800138000**`**）**
+ **域名 = 联系人姓名（好记，如 **`**张三**`**）**

:::

### 4. 防火墙管理 (UFW)
#### 基本防火墙操作
bash

```plain
# 查看防火墙状态
liuwanyun@LWY:~$ sudo ufw status
状态：不活动

# 启用防火墙
liuwanyun@LWY:~$ sudo ufw enable

# 禁用防火墙
liuwanyun@LWY:~$ sudo ufw disable
```

#### 配置防火墙规则
bash

```plain
# 允许 SSH 连接
liuwanyun@LWY:~$ sudo ufw allow ssh
liuwanyun@LWY:~$ sudo ufw allow 22/tcp

# 允许 HTTP 和 HTTPS
liuwanyun@LWY:~$ sudo ufw allow http
liuwanyun@LWY:~$ sudo ufw allow https
liuwanyun@LWY:~$ sudo ufw allow 80/tcp
liuwanyun@LWY:~$ sudo ufw allow 443/tcp

# 允许特定IP范围
liuwanyun@LWY:~$ sudo ufw allow from 192.168.1.0/24

# 拒绝特定端口
liuwanyun@LWY:~$ sudo ufw deny 25/tcp

# 删除规则
liuwanyun@LWY:~$ sudo ufw delete allow 80/tcp
```

:::color1
**防火墙**

**防火墙就是系统的"保安"，控制哪些网络流量可以进入或离开你的计算机。**

+ **防火墙**** = 小区的门禁系统**
+ **端口**** = 不同的门（大门、侧门、后门）**
+ **规则 = 谁可以从哪个门进出**

Ubuntu 默认使用 **UFW**为防火墙

:::

---

## 六.vim编辑器入门
:::color1
Vim 是一个**模态文本编辑器**，意思是它有不同"模式"，每个模式下键盘按键有不同的功能。

:::

### 1. Vim 的三种基本模式
#### 1.1 正常模式（Normal Mode）
**用途**：移动光标、复制、粘贴、删除等操作  
**进入方式**：启动 Vim 默认模式，或按 `Esc` 键

#### 1.2 插入模式（Insert Mode）
**用途**：输入和编辑文本  
**进入方式**：在正常模式下按 `i`, `a`, `o` 等键

#### 1.3 命令行模式（Command-Line Mode）
**用途**：保存文件、退出、搜索等命令  
**进入方式**：在正常模式下按 `:`

![画板](https://cdn.nlark.com/yuque/0/2025/jpeg/61384029/1760281585397-ca7b1516-b4d8-4f77-82cd-160527efe5d4.jpeg)

## 2. 启动和退出 Vim
### 启动 Vim：
bash

```plain
# 启动 Vim（不指定文件名）
liuwanyun@LWY:~$ vim

# 编辑指定文件
liuwanyun@LWY:~$ vim filename.txt

# 打开文件并定位到第 10 行
liuwanyun@LWY:~$ vim +10 filename.txt
```

### Vim 启动后的界面：
text

```plain
~
~
~
~
~
~
~
~
"filename.txt" [新文件]                         0,0-1        全部
```

### 退出 Vim（重要！）：
bash

```plain
# 在正常模式下输入：
:q              # 退出（如果文件未修改）
:q!             # 强制退出，不保存修改
:w              # 保存文件
:wq             # 保存并退出
:x              # 保存并退出（同 :wq）
ZZ              # 保存并退出（Shift + zz）
```

## 3. 基本移动光标
### 字符移动（正常模式下）：
text

h ←     j ↓     k ↑     l →

### 单词移动：
bash

```plain
w       # 移动到下一个单词开头
b       # 移动到上一个单词开头
e       # 移动到当前单词末尾
```

### 行移动：
bash

```plain
0       # 移动到行首
$       # 移动到行尾
^       # 移动到行首第一个非空字符
gg      # 移动到文件第一行
G       # 移动到文件最后一行
50G     # 移动到第 50 行
:50     # 移动到第 50 行（命令行模式）
```

### 屏幕移动：
bash

```plain
Ctrl + f    # 向下翻一页
Ctrl + b    # 向上翻一页
Ctrl + d    # 向下翻半页
Ctrl + u    # 向上翻半页
H           # 移动到屏幕顶部
M           # 移动到屏幕中间
L           # 移动到屏幕底部
```

---

## 4. 基本编辑操作
### 进入插入模式：
bash

```plain
i       # 在光标前插入
I       # 在行首插入
a       # 在光标后插入
A       # 在行尾插入
o       # 在下一行插入新行
O       # 在上一行插入新行
s       # 删除当前字符并插入
S       # 删除当前行并插入
```

### 删除操作：
bash

```plain
x       # 删除当前字符
dd      # 删除当前行
3dd     # 删除 3 行
dw      # 删除一个单词
d$      # 删除到行尾
d0      # 删除到行首
```

### 复制和粘贴：
bash

```plain
yy      # 复制当前行
3yy     # 复制 3 行
yw      # 复制一个单词
p       # 在光标后粘贴
P       # 在光标前粘贴
```

### 撤销和重做：
bash

```plain
u       # 撤销上一次操作
Ctrl + r # 重做（恢复撤销）
U       # 撤销当前行的所有修改
```

---

## 5. 搜索和替换
### 搜索：
bash

```plain
/pattern       # 向前搜索 pattern
?pattern       # 向后搜索 pattern
n              # 下一个匹配项
N              # 上一个匹配项
*              # 搜索当前光标下的单词
```

### 替换：
bash

```plain
:%s/old/new/g           # 全局替换所有 old 为 new
:%s/old/new/gc          # 全局替换，每次确认
:10,20s/old/new/g       # 替换第10-20行的 old 为 new
```

## 七.常用命令行工具
### 1. tmux - 终端复用器
**tmux** 可以让你在一个终端窗口中创建多个会话、窗口和面板，即使断开 SSH 连接，程序也会继续运行。

#### 基本使用：
bash

```plain
# 启动 tmux
liuwanyun@LWY:~$ tmux

# 启动并命名会话
liuwanyun@LWY:~$ tmux new-session -s mysession

# 查看所有会话
liuwanyun@LWY:~$ tmux list-sessions

# 重新连接会话
liuwanyun@LWY:~$ tmux attach -t mysession
```

#### tmux 快捷键（先按 `Ctrl + b`，然后按以下键）：
bash

```plain
# 面板操作
%          # 垂直分割面板
"          # 水平分割面板
方向键      # 切换面板
x          # 关闭当前面板

# 窗口操作
c          # 创建新窗口
n          # 下一个窗口
p          # 上一个窗口
数字键      # 切换到指定窗口

# 会话操作
d          # 分离会话（程序在后台继续运行）
s          # 选择会话
$          # 重命名会话
```

#### 实际例子：
bash

```plain
# 1. 开始一个长时间运行的任务
liuwanyun@LWY:~$ tmux new -s download
# 在tmux中开始下载
wget http://example.com/large-file.zip

# 2. 按 Ctrl+b 然后按 d 断开
# 3. 关闭终端，做其他事情...
# 4. 重新连接，下载仍在继续！
liuwanyun@LWY:~$ tmux attach -t download
```

---

### 2. grep - 文本搜索工具
#### 基本语法：
bash

grep [选项] "模式" [文件]

#### 常用选项：
bash

```plain
-i    # 忽略大小写
-r    # 递归搜索目录
-n    # 显示行号
-v    # 反向匹配（显示不包含模式的行）
-c    # 只显示匹配行数
-l    # 只显示包含匹配的文件名
```

#### 实际例子：
bash

```plain
# 在当前目录搜索包含 "error" 的文件
liuwanyun@LWY:~$ grep -r "error" .

# 在日志文件中搜索错误，显示行号
liuwanyun@LWY:~$ grep -n "ERROR" /var/log/syslog

# 搜索不包含 "test" 的行
liuwanyun@LWY:~$ grep -v "test" file.txt

# 统计包含 "warning" 的行数
liuwanyun@LWY:~$ grep -c "warning" logfile.log

# 使用正则表达式
liuwanyun@LWY:~$ grep "^[0-9]" file.txt          # 以数字开头的行
liuwanyun@LWY:~$ grep "\.txt$" filelist.txt      # 以 .txt 结尾的行
```

#### 组合使用：
bash

```plain
# 查找进程并排除 grep 自身
liuwanyun@LWY:~$ ps aux | grep firefox | grep -v grep

# 在多个文件中搜索
liuwanyun@LWY:~$ grep -r "function" src/ include/

# 搜索并显示前后内容
liuwanyun@LWY:~$ grep -A 2 -B 2 "error" logfile.log  # 显示匹配行前后各2行
```

---

### 3. awk - 文本处理语言
#### 基本语法：
bash

awk '模式 {动作}' 文件

#### 常用变量：
bash

```plain
$0    # 整行内容
$1, $2... # 第1,2...列
NF    # 字段数量
NR    # 当前行号
FS    # 字段分隔符
```

#### 实际例子：
bash

```plain
# 打印文件的第一列
liuwanyun@LWY:~$ awk '{print $1}' file.txt

# 打印最后一列
liuwanyun@LWY:~$ awk '{print $NF}' file.txt

# 自定义分隔符（以冒号分隔）
liuwanyun@LWY:~$ awk -F: '{print $1, $3}' /etc/passwd

# 条件过滤（打印第三列大于1000的行）
liuwanyun@LWY:~$ awk '$3 > 1000' /etc/passwd

# 使用 BEGIN 和 END
liuwanyun@LWY:~$ awk 'BEGIN {sum=0} {sum+=$1} END {print sum}' numbers.txt

# 统计行数、计算平均值
liuwanyun@LWY:~$ awk '{sum+=$1} END {print "总数:", sum, "平均值:", sum/NR}' data.txt
```

#### 高级用法：
bash

```plain
# 处理 CSV 文件
liuwanyun@LWY:~$ awk -F, '$3 > 50 {print $1, $2}' data.csv

# 字符串匹配
liuwanyun@LWY:~$ awk '/error/ {print NR ":", $0}' logfile.log

# 字段计算
liuwanyun@LWY:~$ awk '{print $1, $2, $3, $2+$3}' scores.txt
```

---

### 4. sed - 流编辑器
#### 基本语法：
bash

sed [选项] '命令' 文件

#### 常用命令：
bash

```plain
s/原字符串/新字符串/    # 替换
p                      # 打印
d                      # 删除
i                      # 在行前插入
a                      # 在行后插入
```

#### 实际例子：
bash

```plain
# 替换文本（只输出到屏幕，不修改文件）
liuwanyun@LWY:~$ sed 's/old/new/' file.txt

# 替换并保存到原文件（-i 选项）
liuwanyun@LWY:~$ sed -i 's/old/new/g' file.txt

# 全局替换（一行中的所有 old）
liuwanyun@LWY:~$ sed 's/old/new/g' file.txt

# 删除包含 "test" 的行
liuwanyun@LWY:~$ sed '/test/d' file.txt

# 打印特定行范围（第10-20行）
liuwanyun@LWY:~$ sed -n '10,20p' file.txt

# 在每行行首添加内容
liuwanyun@LWY:~$ sed 's/^/# /' file.txt          # 添加注释符号

# 在每行行尾添加内容
liuwanyun@LWY:~$ sed 's/$/ --- end/' file.txt
```

#### 高级用法：
bash

```plain
# 多重操作
liuwanyun@LWY:~$ sed -e 's/foo/bar/g' -e '/baz/d' file.txt

# 使用其他分隔符（当字符串包含 / 时）
liuwanyun@LWY:~$ sed 's|/usr/local|/usr|g' file.txt

# 备份原文件并修改
liuwanyun@LWY:~$ sed -i.bak 's/old/new/g' file.txt

# 只在匹配特定模式的行中替换
liuwanyun@LWY:~$ sed '/pattern/s/old/new/g' file.txt
```

---

