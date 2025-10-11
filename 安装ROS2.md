操作系统： Ubuntu 22.04 LTS

目标ROS2版本： Humble Hawksbill

使用工具： 小鱼一键安装工具



<font style="background-color:#FBDE28;">准备工作</font>：

1.系统要求： 确保系统为Ubuntu 22.04

2.网络连接： 保持稳定网络

3.权限： 需要具有sudo权限的用户。



<font style="background-color:#FBDE28;">安装</font>：

1.更新

```plain
sodu apt update
```

【注】输入密码时，密码不显示，直接回车；

          <font style="color:#DF2A3F;">sudo：</font>以管理员权限执行后面的命令；

          <font style="color:#DF2A3F;"> apt</font>：ubuntu中用于管理软件的工具，“应用商店”

          <font style="color:#DF2A3F;"> update</font>：不是更新软件本身，而是刷新“软件源列表”获取一份当前所有可用软件及其最新版               本号的清单

            理解：去超市购物前，先打开手机 App 查看一下超市今天有哪些商品在售，以及它们的价格，             但并不真正购买。

2.一键安装指令，使用 wget 下载并直接通过 bash 运行

[链接](http://fishros.com/)

```plain
wget http://fishros.com/install -O fishros && bash fishros
```

 【注】<font style="color:#DF2A3F;">wget</font>：下载

          <font style="color:#DF2A3F;"> &&</font>：连接

![](https://cdn.nlark.com/yuque/0/2025/jpeg/61384029/1760192290183-5d64a381-f16d-4feb-a395-e8ecf1962d06.jpeg)![](https://cdn.nlark.com/yuque/0/2025/jpeg/61384029/1760192237231-86173c79-579a-45bc-bfea-703d8ad61d36.jpeg)



<font style="background-color:#FBDE28;">测试：</font>

```plain
ros2
```

-->出现提示

```plain
whereis ros2
```

![](https://cdn.nlark.com/yuque/0/2025/jpeg/61384029/1760192317425-82ef91c9-78e6-4c52-b5b0-26b07ad571f7.jpeg)

