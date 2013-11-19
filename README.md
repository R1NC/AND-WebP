Introduction
==========
Google added WebP support in ICS(Android 4.0).<BR/>
But with this project, you need not to care about the compatibility.<BR/>
It's based on Google's open source project [Chromium](https://git.chromium.org/);<BR/>
To know more about this project, visit [my blog](http://rincliu.com/blog/2013/07/10/androidping-webpde-nativezhi-chi-jian-rong-4-dot-0yi-xia-she-bei/).
Features
==========

```
public static native Bitmap nativeDecodeByteArray(byte[] data, BitmapFactory.Options options);

public static native byte[] nativeEncodeBitmap(Bitmap bitmap, int quality);

public static boolean isWebP(byte[] data);
```

Usage
==========
Just build the cpp files under jni folder with NDK. And then enjoy it!
