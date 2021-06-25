### Introduction

Android has no support for WebP codec until ICS(4.0).

This project is a native implementation based on [Chromium](https://git.chromium.org/).

### Features

```java
public static native Bitmap nativeDecodeByteArray(byte[] data, BitmapFactory.Options options);

public static native byte[] nativeEncodeBitmap(Bitmap bitmap, int quality);

public static boolean isWebP(byte[] data);
```
