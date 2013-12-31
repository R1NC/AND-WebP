/**
 * Copyright (c) 2013-2014, Rinc Liu (http://rincliu.com).
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#include <jni.h>
/* Header for class android_backport_webp_WebPFactory */

#ifndef _Included_com_rincliu_library_common_persistence_image_webp_WebPFactory
#define _Included_com_rincliu_library_common_persistence_image_webp_WebPFactory
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     android_backport_webp_WebPFactory
 * Method:    nativeDecodeByteArray
 * Signature: ([BLandroid/graphics/BitmapFactory/Options;)Landroid/graphics/Bitmap;
 */
JNIEXPORT jobject JNICALL Java_com_rincliu_library_common_persistence_image_webp_WebPFactory_nativeDecodeByteArray
  (JNIEnv *, jclass, jbyteArray, jobject);

/*
 * Class:     android_backport_webp_WebPFactory
 * Method:    nativeEncodeBitmap
 * Signature: (Landroid/graphics/Bitmap;I)[B
 */
JNIEXPORT jbyteArray JNICALL Java_com_rincliu_library_common_persistence_image_webp_WebPFactory_nativeEncodeBitmap
  (JNIEnv *, jclass, jobject, jint quality);

#ifdef __cplusplus
}
#endif
#endif
