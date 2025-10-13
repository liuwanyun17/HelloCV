## 1.版本控制的意义
       版本控制即记录一份或若干份文件的内容变化情况，即每次内容变化后的文件为一个版本，git等版本控制工具可记录修改情况，控制不同版本，以实现实时查阅、调取某次修改后的版本。

      <font style="background-color:#FBDE28;">对于个人开发者而言</font>，版本控制可实现随时回溯之前任意版本的代码，文件状态，降低试错成本；

提供独立于主线代码或文件内容的分支功能，便于最终版本的合并。

    <font style="background-color:#FBDE28;">  对于团队协作而言</font>，便于开发人员在不同的支线上开展工作，且过程可追溯，大大提升了工作效率

## 2.三大区域：工作区、暂存区、仓库
### (1)仓库
版本库又名仓库（Repository），可以简单理解成一个目录，这个目录里面的所有文件都可以被Git管理起来，每个文件的修改、删除，Git都能跟踪，以便任何时刻都可以追踪历史，或者在将来某个时刻可以“还原”

创建一个版本库非常简单，首先，选择一个合适的地方，创建一个空目录：

```plain
$ mkdir learngit
$ cd learngit
$ pwd
```

`pwd`命令用于显示当前目录

第二步，通过`git init`命令把这个目录变成Git可以管理的仓库：

```plain
$ git init
Initialized empty Git repository in /Users/liuwanyun/learngit/.git/
```

Git就把仓库建好了,learngit目录下又多了一个.git目录，但被隐藏了，可通过ls -ah查看

把文件添加到版本库

现在我们编写一个`readme.txt`文件，内容如下：

```plain
Git is a version control system.
Git is free software.
```

一定要放到`learngit`目录下（子目录也行），因为这是一个Git仓库，放到其他地方Git再厉害也找不到这个文件。

**把一个文件放到Git仓库只需要两步：git add 和git commit，共同完成了将工作成果永久记录到版本历史中的过程**

第一步，用命令`git add`告诉Git，把文件添加到仓库：

```plain
$ git add readme.txt
```

执行上面的命令，没有任何显示，这就对了，Unix的哲学是“没有消息就是好消息”，说明添加成功。

第二步，用命令`git commit`告诉Git，把文件提交到仓库：

```plain
$ git commit -m "wrote a readme file"
[master (root-commit) eaadf4e] wrote a readme file
 1 file changed, 2 insertions(+)
 create mode 100644 readme.txt
```



![](https://cdn.nlark.com/yuque/0/2025/png/61384029/1760316158498-a683f7c7-6cee-481e-a548-e90649e9b7f7.png)

🤔<font style="color:#D22D8D;">我用git commit -m <message>提交了一个内容，为什么我的文档里没有出现这句话？</font>

<font style="color:#01B2BC;">错误地理解了git commit提交的内容</font>

+ `<font style="color:#01B2BC;">git commit -m "消息"</font>`<font style="color:#01B2BC;"> 中的消息是</font>**<font style="color:#01B2BC;">版本元数据</font>**<font style="color:#01B2BC;">，不是文件内容</font>
+ <font style="color:#01B2BC;">使用 </font>`<font style="color:#01B2BC;">git log</font>`<font style="color:#01B2BC;"> 来查看提交历史和信息</font>
+ <font style="color:#01B2BC;">提交信息的目的是为了记录</font>**<font style="color:#01B2BC;">为什么</font>**<font style="color:#01B2BC;">要这样修改，方便日后追溯</font>

<font style="color:#01B2BC;">当你执行 </font>`<font style="color:#01B2BC;">git commit -m "你的消息"</font>`<font style="color:#01B2BC;"> 时：</font>

1. **<font style="color:#01B2BC;">提交信息被保存在 Git 的版本数据库中</font>**<font style="color:#01B2BC;">，作为这次提交的元数据</font>
2. **<font style="color:#01B2BC;">它不会修改任何你的项目文件内容</font>**
3. <font style="color:#01B2BC;">它就像是给这次提交贴的一个"标签"或"备注"</font>

:::color2
Git跟踪管理的是修改，而非文件

:::

<font style="color:#000000;">工作区中有一个隐藏的目录.git,即git的版本库</font>

### （2）工作区
在电脑里能看到的目录，比如我的`learngit`文件夹就是一个工作区

### （3）暂存区
版本库内存有称为stage（或index)的暂存区

版本库包含以下内容

![画板](https://cdn.nlark.com/yuque/0/2025/jpeg/61384029/1760352597398-7b0d2d22-c7a1-49d2-9057-c0937a2e3e5b.jpeg)



把文件添加进git分为两步

第一步是用`git add`把文件添加进去，实际上就是把文件修改添加到暂存区

第二步是用`git commit`提交更改，实际上就是把暂存区的所有内容提交到当前分支

`**<font style="color:#000000;background-color:#FBDE28;">git add</font>**`**<font style="color:#000000;background-color:#FBDE28;">命令实际上就是把要提交的所有修改放到暂存区（Stage），然后，执行</font>**`**<font style="color:#000000;background-color:#FBDE28;">git commit</font>**`**<font style="color:#000000;background-color:#FBDE28;">就可以一次性把暂存区的所有修改提交到分支。</font>**

## 3.命令
#### git-add-选择性地准备要保存的更改
#### git commit -m<>-将准备好的更改永久记录到版本历史
#### git status-随时掌握工作区的状态
#### git diff-查看具体修改内容
![](https://cdn.nlark.com/yuque/0/2025/png/61384029/1760317923739-188b921e-e0a4-47aa-b2da-3e67155b69f1.png)

🤔**tips**

**<font style="color:#D22D8D;">(1)命令在版本库目录下进行</font>**

**<font style="color:#D22D8D;">(2)commit<空格>-m</font>**

**<font style="color:#D22D8D;">(3)git add后要指定文件</font>**

#### git-log:查看修改历史
显示从最近到最远的提交日志![](https://cdn.nlark.com/yuque/0/2025/png/61384029/1760318431080-f3c649e0-8b15-4c4c-821c-122b6d6ba40c.png)

#### git-log加上`--pretty=oneline`参数:简化git-log的输出内容
```plain
$ git log --pretty=oneline
1094adb7b9b3807259d8cb349e7df1d4d6477073 (HEAD -> master) append GPL
e475afc93c209a690c39c13a46716e8fa000c366 add distributed
eaadf4e385e865d25c48e7ca9c8395c3f7dfaef0 wrote a readme file
```

<font style="color:#D22D8D;">你看到的一大串类似</font>`<font style="color:#D22D8D;">1094adb...</font>`<font style="color:#D22D8D;">的是</font>`<font style="color:#D22D8D;">commit id</font>`<font style="color:#D22D8D;">（版本号）</font>

#### 版本回退相关的命令
在Git中，用`HEAD`表示当前版本，上一个版本就是`HEAD^`，上上一个版本就是`HEAD^^`，当然往上100个版本写100个`^`比较容易数不过来，所以写成`HEAD~100`

##### git reset --hard HEAD^-版本回退
```plain
$ git reset --hard HEAD^
HEAD is now at e475afc add distributed
```

`--hard`会回退到上个版本的已提交状态

`--soft`会回退到上个版本的未提交状态

`--mixed`会回退到上个版本已添加但未提交的状态

![](https://cdn.nlark.com/yuque/0/2025/png/61384029/1760354417561-b55d0796-0ba2-46c6-95bf-ae0a6cbf2cee.png)

##### git reset --hard <版本号>-指定回到未来的某个版本
版本号只需要输入前几位，e.g.1094a

:::color2
### 实质
Git的版本回退速度非常快，因为Git在内部有个指向当前版本的`HEAD`指针，当你回退版本的时候，Git仅仅是把HEAD从指向回退的版本

:::

🤔想恢复到新版本怎么办？找不到新版本的`commit id`怎么办？

##### git reflog-记录每一次命令
可查询版本号

```plain
$ git reflog
e475afc HEAD@{1}: reset: moving to HEAD^
1094adb (HEAD -> master) HEAD@{2}: commit: append GPL
e475afc HEAD@{3}: commit: add distributed
eaadf4e HEAD@{4}: commit (initial): wrote a readme file
```

:::warning
概念：修改

什么是修改？比如你新增了一行，这就是一个修改，删除了一行，也是一个修改，更改了某些字符，也是一个修改，删了一些又加了一些，也是一个修改，甚至创建一个新文件，也算一个修改。

**git管理的就是修改，而非文件**

:::

#### `git checkout -- file`-丢弃工作区的修改：
命令`git checkout -- readme.txt`意思就是，把`readme.txt`文件在工作区的修改全部撤销，这里有两种情况：

一种是`readme.txt`自修改后还没有被放到暂存区，现在，撤销修改就回到和版本库一模一样的状态；

一种是`readme.txt`已经添加到暂存区后，又作了修改，现在，撤销修改就回到添加到暂存区后的状态。

总之，就是让这个文件回到最近一次`git commit`或`git add`时的状态。

🤔<font style="color:#D22D8D;">直接手动删除不就行了，因为没有留下任何修改历史啊，为什么要命令行?</font>

<font style="color:#1DC0C9;">核心原因：Git 知道“正确”的状态是什么</font>

<font style="color:#1DC0C9;">当你手动操作时，你依赖的是</font>**<font style="color:#1DC0C9;">你的记忆</font>**<font style="color:#1DC0C9;">和</font>**<font style="color:#1DC0C9;">你的操作准确性</font>**<font style="color:#1DC0C9;">。而当你使用 </font>`<font style="color:#1DC0C9;">git checkout -- file</font>`<font style="color:#1DC0C9;"> 时，你依赖的是 </font>**<font style="color:#1DC0C9;">Git 仓库里记录的准确历史</font>**<font style="color:#1DC0C9;">。</font>

<font style="color:#1DC0C9;">例子：</font>

<font style="color:#1DC0C9;">假设你打开了一个文件 </font>`<font style="color:#1DC0C9;">report.txt</font>`<font style="color:#1DC0C9;">，并做了 50 处散落各处的修改。一小时后，你发现这些修改全是徒劳，需要全部废弃。</font>

+ **<font style="color:#1DC0C9;">手动方式</font>**<font style="color:#1DC0C9;">：你不得不打开原始文件的备份（如果你有的话），或者凭借记忆，一行一行地去核对，撤销那 50 处修改。这个过程不仅痛苦，而且极易遗漏或出错。</font>

**<font style="color:#1DC0C9;">Git 方式</font>**<font style="color:#1DC0C9;">：你只需要执行：</font>

+ <font style="color:#1DC0C9;">bash</font>

<font style="color:#1DC0C9;">git checkout -- report.txt</font>

+ <font style="color:#1DC0C9;">在不到一秒钟的时间内，</font>`<font style="color:#1DC0C9;">report.txt</font>`<font style="color:#1DC0C9;"> 就变回了你开始修改前的完美状态。Git 自动帮你完成了所有“找不同”和“回退”的工作。</font>

#### `git reset HEAD <file>`-把暂存区的修改撤销掉，重新放回工作区
假设你不但改错了东西，还从暂存区提交到了版本库，怎么办呢？<font style="color:#D22D8D;">版本回退</font>

⚠️前提是没有推送到远程库

总结：

场景1：当你改乱了工作区某个文件的内容，想直接丢弃工作区的修改时，用命令`git checkout -- file`

场景2：当你不但改乱了工作区某个文件的内容，还添加到了暂存区时，想丢弃修改，分两步，第一步用命令`git reset HEAD <file>`，就回到了场景1，第二步按场景1操作。

场景3：已经提交了不合适的修改到版本库时，想要撤销本次提交，参考[版本回退](https://liaoxuefeng.com/books/git/time-travel/reset/index.html)一节，不过前提是没有推送到远程库

#### rm-删除文件
```plain
$ rm test.txt
```

轻松地把误删的文件恢复到最新版本：

```plain
$ git checkout -- test.txt
```

命令`git rm`用于删除一个文件。如果一个文件已经被提交到版本库，那么你永远不用担心误删

#### 远程仓库相关命令
##### git clone-初次下载/建立<font style="color:#DF2A3F;">联系(本地库与远程库）</font>
**<font style="color:rgb(15, 17, 21);">作用</font>**<font style="color:rgb(15, 17, 21);">：将远程仓库</font>**<font style="color:rgb(15, 17, 21);">完整地复制</font>**<font style="color:rgb(15, 17, 21);">到你的本地，并自动建立关联</font>

具体操作

```plain
git clone https://github.com/username/repository.git
```

执行后会发生什么：

在你的当前目录创建项目文件夹

在这个文件夹里初始化一个完整的 .git 本地仓库

将远程仓库的所有代码、所有分支历史、所有提交记录都下载下来

自动将远程仓库命名为 origin（这是默认名称）

**<font style="color:rgb(15, 17, 21);">比喻</font>**<font style="color:rgb(15, 17, 21);">：就像你去图书馆借一本完整的书回家研读。</font>

#### <font style="color:rgb(15, 17, 21);">git pull-获取更新</font>
#### 2. `git pull` - 获取更新
**作用**：从远程仓库**下载最新更改**并**合并**到你的当前分支。

**使用场景**：

+ 你的队友推送了新代码，你想要获取这些更新。
+ 你在多台设备上工作，在另一台设备上推送后，在当前设备上需要更新。

**具体操作**：

bash

```plain
git pull origin main
# 或者更简单（如果已经设置上游分支）
git pull
```

**执行后会发生什么**：

1. `fetch`：从 `origin` 下载 `main` 分支的最新提交
2. `merge`：尝试将这些更改合并到你当前所在的本地分支

**比喻**：就像你发现那本书有了新章节，你去图书馆只借回新增的章节，然后把这些新内容插入到你自己的书中。

#### 3. `git push` - 上传分享
**作用**：将你的本地提交**上传**到远程仓库。

**使用场景**：

+ 你完成了一些工作，进行了几次 `git commit`，现在想要分享给团队。
+ 你想要备份你的代码到远程仓库。

**具体操作**：

bash

```plain
git push origin main
# 或者设置上游分支后简化
git push -u origin main  # 第一次推送时设置上游
git push                 # 之后就可以简写了
```

**执行后会发生什么**：

1. 将你本地 `main` 分支上**新增的提交**上传到 GitHub
2. 更新远程 `main` 分支的指针指向最新的提交

**比喻**：就像你写完了一篇论文，把它发布到共享平台上让大家都能看到。



## 4.分支管理
在同一个代码仓库中，创建、使用、合并和删除不同“分支”的策略和流程

您可以把它想象成一棵树：

+ **主树干（Main/Master Branch）**：代表稳定、可随时发布的代码。
+ **树枝（Feature/Bugfix Branches）**：从主树干分出来，用于开发新功能或修复bug，而不会影响主树干的稳定性。开发完成后，这些树枝再被合并回主树干。

#### 核心 Git 分支管理命令
以下是一些最常用的 Git 命令：

bash

```plain
# 查看所有分支（当前分支前有 * 号）
git branch

# 查看所有分支（包括远程分支）
git branch -a

# 创建并切换到新分支
git checkout -b feature-xxx
# 或者使用更现代的命令
git switch -c feature-xxx

# 切换到已有分支
git checkout main
git switch main

# 将指定分支合并到当前分支（例如，将 feature-xxx 合并到 main）
git merge feature-xxx

# 删除已合并的分支
git branch -d feature-xxx

# 强制删除未合并的分支
git branch -D feature-xxx

# 推送本地分支到远程仓库
git push -u origin feature-xxx
```

---

## 5.git fetch和git pull的区别
简单来说，`**git fetch**`** 是「下载」操作，而 **`**git pull**`** 是「下载并合并」操作。**

核心概念比喻

**想象你在图书馆里看一本共享的笔记（远程仓库 Remote Repository），你自己也有一本副本（本地仓库 Local Repository）。**

+ `**git fetch**`**：你抬起头，看看图书馆那本共享笔记有没有新的内容更新。你****只是知道了有哪些更新****，但并没有把这些新内容抄到你自己的笔记本上。**
    - **动作****：检查更新。**
    - **结果****：你知道别人写了什么，但你的本地副本没变。**
+ `**git pull**`**：你不仅看到了共享笔记有更新，还****立刻把这些新内容抄到了你自己的笔记本上****，和你的内容合并在一起。**
    - **动作****：检查更新 + 合并到本地。**
    - **结果：你的本地副本已经包含了最新的所有内容。**

## 6.远程仓库管理：git remote
`git remote` 是一个用于管理、查看和操作你与远程仓库连接的工具。它本身不传输文件，而是负责记录和维护远程仓库的地址和别名

### 常用 `git remote` 命令详解
#### 1. 查看远程仓库信息
bash

```plain
# 查看所有已配置的远程仓库的简称（别名）
git remote

# 查看所有远程仓库的简称和对应的 URL（更详细）
git remote -v
# 示例输出：
# origin  https://github.com/your-username/your-repo.git (fetch)
# origin  https://github.com/your-username/your-repo.git (push)

# 查看某个远程仓库的详细信息，包括其 URL 和跟踪分支
git remote show origin
```

#### 2. 添加远程仓库
当你克隆一个仓库时，Git 会自动为你添加一个名为 `origin` 的远程仓库。但如果你想添加另一个远程仓库（例如，同事的仓库或一个官方上游仓库），就需要手动添加。

bash

```plain
# 添加一个新的远程仓库，并为其指定一个别名
git remote add <alias> <url>

# 示例：添加一个名为 "upstream" 的远程仓库（常用于 Fork 的工作流）
git remote add upstream https://github.com/original-author/project.git

# 示例：添加一个同事的仓库
git remote add teammate https://github.com/teammate/project.git
```

## 8.Rebasing工作流
一种旨在创造更清晰、线性的项目提交历史的 Git 工作流

核心思想：重新定义起点

想象提交历史是一条时间线。

+ **合并**：像是把两条绳子打成一个结。
+ **变基**：像是把你自己的这条绳子拆开，然后接到另一条更新、更长的绳子末端。它**改变了你提交的根基**。

**官方解释**：变基将当前分支的一系列提交“复制”下来，然后在目标分支（通常是更新的主分支）的最新提交之上，按顺序重新应用一遍

## 9.Pull Request(PR)提交流程
PR（在 GitLab 中称为 Merge Request，MR）的本质是：**你向项目维护者发起一个请求，请求他们“拉取”你的代码变更并合并到主分支中。**



