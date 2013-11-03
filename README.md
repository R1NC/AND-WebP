<h2>简介：</h2>
WebP是Google提出的一种替换png和bmp的图片格式，根据<a target="_blank" href="http://commondatastorage.googleapis.com/io-2013/presentations/234%20-%20io-webp.pdf">Google IO 2013上的介绍</a>，JPEG/PNG转换为WebP格式后，大小平均可以减少30%，而页面加载速度可以减少三分之一。<BR/>
但遗憾的是，Android 4.0才开始支持WebP。
本项目基于<a target="_blank" href="https://git.chromium.org/gitweb/?p=webm/libwebp.git;a=summary">Chromium</a>项目，是Android平台下Webp格式图片编码解码的native解决方案，兼容4.0以下系统；使用前需要用NDK编译jni目录下的cpp。<BR/>
