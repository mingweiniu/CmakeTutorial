# CV_hw1
reconstruct a model  

# Prerequisites
  * CMake (3.5 or latter)  
  * OpenCV (3.1 or latter)  
  
## Command on Windows PowerShell: 
you need add C:\Windows\Microsoft.NET\Framework\\_v4.0.30319_ to $ENV:path  
and also have $ENV:OpenCV_DIR  
PS\\> cd opencv_vs14  
PS\\> .\build.bat

#### Windows opencv installation guide
First, download https://sourceforge.net/projects/opencvlibrary/files/opencv-win/3.2.0/opencv-3.2.0-vc14.exe/  
Second, set your Environment Variable "OpenCV_DIR" , for example , "C:\\package\\opencv\build"  
Third, add dynamic libs to path, for example, "%OpenCV_DIR%/x64/vc14/bin"
Finally, log out user or reboot system  

## Command on  Linux:
[user]$ cd opencv_vs14  
[user]$ bash build.sh
