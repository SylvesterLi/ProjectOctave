## Here is my OpenCV Learning Code

###  Well, I am not so professional in this, but I'd like to share my learning experinence.

maybe someday it goes to work out my questions~

## Update 1

2018/08/25 Now we come a new stage and I should learn more professional knowledge.

What I have learnt from

This tells you how to normally setup 

https://blog.csdn.net/jia20003/article/details/54583431

and when you got some trouble：Pls check your network(My home network trapped me for a long while)

Problems such as

` Download face_landmark_model.dat Failed (or time out) `
` missing ffmpeg `

but the download is real slow.
you could use your mobile and provide hotspot for your PC.(As I done)

if auto-download can't do to help, you could check these issues :

` https://github.com/opencv/opencv_contrib/issues `

At last ,google can be your best driver.

## Update 2

 Finally, got it! After check and check again, it works! 

Below is the code of printing all files' name in current catalog
Just paste it in the PowerShell
Attention : the ` F:\OCV\opencv\newbuild\install\x64\vc15\lib ` is my file directory path

 ``` PowerShell
 
Get-ChildItem F:\OCV\opencv\newbuild\install\x64\vc15\lib | ForEach-Object -Process{
if($_ -is [System.IO.FileInfo])
{
Write-Host($_.name);
}
}

 ```


 ##  Update 3
 
 In the OCV3 Project I don't use src as default input image but use img_1.Which leads me misleading and make some mistakes. In the last days, I should take care of this!!
 

 ## Update 4

 These two days, i just watch corner detection, one of detection methods is Harris , and another is Shi-Tomasi Corner detetion. In my point of view , Good Features To Track (aka Shi-Tomasi) performs better than Harris detection .

But both of them did not mark the top of roof which human could easily recognize.

Pic blow is ` good feature to track ` 

![](picsSource/goodF2Track.png)


and till now, I should have finished custom corner detection, but I think it is unnecessary to learn. When I meet such kind of projects or problems, I would come back have a careful seek.


## Update 5

Comming soon....