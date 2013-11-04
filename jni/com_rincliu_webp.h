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
#ifndef _com_rincliu_webp
#define _com_rincliu_webp

#include <jni.h>

// Logger tag
extern const char* const LOG_TAG;

// Declarations of class-refs, method-refs and field-refs
namespace jrefs {

namespace java {
namespace lang {

struct jclass_NullPointerException {
	jclass_NullPointerException(JNIEnv* jniEnv);

	// http://developer.android.com/reference/java/lang/NullPointerException.html
	jclass jclassRef;
};
extern jclass_NullPointerException* NullPointerException;

struct jclass_IllegalArgumentException {
	jclass_IllegalArgumentException(JNIEnv* jniEnv);

	// http://developer.android.com/reference/java/lang/IllegalArgumentException.html
	jclass jclassRef;
};
extern jclass_IllegalArgumentException* IllegalArgumentException;

struct jclass_RuntimeException {
	jclass_RuntimeException(JNIEnv* jniEnv);

	// http://developer.android.com/reference/java/lang/RuntimeException.html
	jclass jclassRef;
};
extern jclass_RuntimeException* RuntimeException;

} // namespace lang
} // namespace java

namespace android {
namespace graphics {

struct jclass_Bitmap {
	jclass_Bitmap(JNIEnv* jniEnv);

	// http://developer.android.com/reference/android/graphics/Bitmap.html
	jclass jclassRef;

	// http://developer.android.com/reference/android/graphics/Bitmap.html#createBitmap(int, int, android.graphics.Bitmap.Config)
	jmethodID createBitmap;

	struct jclass_Config {
		jclass_Config(JNIEnv* jniEnv);

		// http://developer.android.com/reference/android/graphics/Bitmap.Config.html
		jclass jclassRef;

		jfieldID ARGB_8888;
	} Config;

}; // struct jclass_Bitmap
extern jclass_Bitmap* Bitmap;

struct jclass_BitmapFactory {
	jclass_BitmapFactory(JNIEnv* jniEnv);

	struct jclass_Options {
		jclass_Options(JNIEnv* jniEnv);

		// http://developer.android.com/reference/android/graphics/BitmapFactory.Options.html
		jclass jclassRef;

		// boolean http://developer.android.com/reference/android/graphics/BitmapFactory.Options.html#inJustDecodeBounds
		jfieldID inJustDecodeBounds;

		// int http://developer.android.com/reference/android/graphics/BitmapFactory.Options.html#outHeight
		jfieldID outHeight;

		// int http://developer.android.com/reference/android/graphics/BitmapFactory.Options.html#outWidth
		jfieldID outWidth;
	} Options;
};
extern jclass_BitmapFactory* BitmapFactory;

} // namespace graphics
} // namespace android
} // namespace jrefs

#endif
