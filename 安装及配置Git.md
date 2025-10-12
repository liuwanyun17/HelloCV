<font style="background-color:#FBDE28;">配置姓名，邮箱：</font>

1.检测git安装成功：

![](https://cdn.nlark.com/yuque/0/2025/png/61384029/1759877468595-17e604bf-f4a4-4e13-ae2d-c3c1c03529c6.png)

2.配置git：姓名及邮箱

```plain
# 配置你的用户名
git config --global user.name "你的用户名"

# 配置你的邮箱
git config --global user.email "你的邮箱地址"
```

![](https://cdn.nlark.com/yuque/0/2025/png/61384029/1759877517330-41537aa7-ff49-40df-a38d-b11718eddba7.png)

3.检测配置：

```plain
# 查看所有配置
git config --list

# 或查看特定配置
git config user.name
git config user.email
```

![](https://cdn.nlark.com/yuque/0/2025/png/61384029/1759877572289-be42363f-79d8-4e2c-9230-5df173bac9ff.png)![](https://cdn.nlark.com/yuque/0/2025/png/61384029/1759877572482-a6cd08dd-68b8-44c9-ada0-d36887b8a22a.png)

4.【问题】

输入错误：![](https://cdn.nlark.com/yuque/0/2025/jpeg/61384029/1760233614649-51111d16-b2d2-40b0-8b64-60a116c8e961.jpeg)

user.name 和姓名之间缺少了一个空格，git 对命令的格式要求比较严格，参数之间都需要用空格分隔。

---

<font style="background-color:#FBDE28;">配置SSH密钥：</font>

SSH 密钥是一种更安全、更方便的身份验证方式，用来替代每次输入用户名密码。

SSH 密钥就像一把数字钥匙，包含两个部分：

**私钥**：保存在你自己的电脑上（绝不分享）

**公钥**：上传到 GitHub、Gitee 等代码平台

**为什么需要 SSH 密钥？**

**不用 SSH 密钥：**

每次推送代码都要输入用户名密码

安全性相对较低

**使用 SSH 密钥：**

一次配置，永久使用

更安全，无需记忆密码

适合自动化流程



配置：

```plain
# 生成 SSH 密钥
ssh-keygen -t ed25519 -C "你的QQ邮箱@qq.com"
```

![](https://cdn.nlark.com/yuque/0/2025/png/61384029/1760234624570-b2f33b5f-8c90-4d28-8622-9b14993b7aa9.png)![](https://cdn.nlark.com/yuque/0/2025/png/61384029/1760234624598-ec6b1568-7fb6-4d30-b242-2df73f04c8c5.png)

（输入问题）😇



查看生成的密钥：

```plain
cat ~/.ssh/id_ed25519.pub
```

将公钥添加到 GitHub：

复制公钥内容（以 ssh-ed25519 AAA... 开头）

登录 GitHub → Settings → SSH and GPG keys

点击 "New SSH key"

粘贴公钥内容

![](https://cdn.nlark.com/yuque/0/2025/png/61384029/1760234601261-cf90062a-6d1c-4b05-ad0b-802674f302fe.png)

测试 SSH 连接：

```plain
ssh -T git@github.com
```

![](https://cdn.nlark.com/yuque/0/2025/png/61384029/1760234632290-f2f56773-8159-4ea2-8984-737e504a4464.png)

【问题】 SSH 连接超时问题，通常是因为网络环境无法直接连接到 GitHub 的 SSH 端口（22端口）。在国内的网络环境下很常见。

