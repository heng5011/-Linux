# 将文件上传到github仓库（本地操作）

### 1、终端运行以下指令：

```
git init
git add README.md
git commit -m"first commit"
git remote add origin git@github.com:××××××/day01.git
git push -u origin master
```

### 2、接下来创建一个文件夹

![DeepinScreenshot_select-area_20190410233151](/home/heng/Desktop/DeepinScreenshot_select-area_20190410233151.png)

把github上面的仓库克隆到本地

```
git clone https://github.com/xxxxx（https://github.com/xxxxx替换成你之前复制的地址）
```

![DeepinScreenshot_select-area_20190410232819](/home/heng/Desktop/DeepinScreenshot_select-area_20190410232819.png)

### 3、把需要上传的文件拷贝到刚下载的新文件夹中

### 4、接下来依次输入以下代码即可完成上传操作：

```
git add  . （注：别忘记后面的 . ，此操作是把Test文件夹下面的文件都添加进来）

git commit -m“提交信息” （注：“提交信息”里面换成你需要，如“first commit”）

git push -u origin master （注：此操作目的是把本地仓库push到github上面，此步骤需要你输入帐号和密码）
```

![DeepinScreenshot_select-area_20190410233334](/home/heng/Desktop/DeepinScreenshot_select-area_20190410233334.png)



![DeepinScreenshot_select-area_20190410233452](/home/heng/Desktop/DeepinScreenshot_select-area_20190410233452.png)

### 5、刷新网站页面就可以看到已经上传的文件

## ssh， github配置

```
cd .ssh
ls
ssh-keygen -t rsa
找到id_rsa.pub复制. 登录github 点击头像 选择settings 进入设置，然后选择ssh GPG keys 按钮 点击ssh添加 粘贴
ssh -T git@github.com

 # GitHub Start 
192.30.253.112 github.com 
192.30.253.119 gist.github.com 
151.101.100.133 assets-cdn.github.com 
151.101.100.133 raw.githubusercontent.com 
151.101.100.133 gist.githubusercontent.com 
151.101.100.133 cloud.githubusercontent.com 
151.101.100.133 camo.githubusercontent.com 
151.101.100.133 avatars0.githubusercontent.com 
151.101.100.133 avatars1.githubusercontent.com 
151.101.100.133 avatars2.githubusercontent.com 
151.101.100.133 avatars3.githubusercontent.com 
151.101.100.133 avatars4.githubusercontent.com 
151.101.100.133 avatars5.githubusercontent.com 
151.101.100.133 avatars6.githubusercontent.com 
151.101.100.133 avatars7.githubusercontent.com 
151.101.100.133 avatars8.githubusercontent.com
 # GitHub End
https://blog.csdn.net/qq_36589706/article/details/80573008
```

