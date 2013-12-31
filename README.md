Introduction
==========
Google's origin Android API doesn't support WebP until ICS(Android 4.0).<BR/>
This project is a native(C++) implementation based on Google's open source project [Chromium](https://git.chromium.org/). So you need not to care about the compatibility.
Features
==========

```
public static native Bitmap nativeDecodeByteArray(byte[] data, BitmapFactory.Options options);

public static native byte[] nativeEncodeBitmap(Bitmap bitmap, int quality);

public static boolean isWebP(byte[] data);
```

Usage
==========
Just build the cpp files under jni folder with NDK. And then enjoy it!<BR/>
NOTE: If you’ve updated your Android SDK to the latest version, [a JNI error](http://stackoverflow.com/questions/14765776/jni-error-app-bug-accessed-stale-local-reference-0xbc00021-index-8-in-a-tabl) may occur.
Then you should set targetSdkVersion to 13 to avoid it.