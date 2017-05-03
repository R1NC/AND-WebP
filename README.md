### Introduction

Google's origin Android API doesn't support WebP until ICS(Android 4.0).

This project is a native(C++) implementation based on Google's open source project [Chromium](https://git.chromium.org/). 
So you need not to care about the compatibility.

### Features

```java
public static native Bitmap nativeDecodeByteArray(byte[] data, BitmapFactory.Options options);

public static native byte[] nativeEncodeBitmap(Bitmap bitmap, int quality);

public static boolean isWebP(byte[] data);
```

### Usage

Just build the cpp files under jni folder with NDK. And then enjoy it!
