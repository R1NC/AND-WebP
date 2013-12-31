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
#include "com_rincliu_library_common_persistence_image_webp.h"

#include <jni.h>

#include <assert.h>
#include <android/log.h>

const char* const LOG_TAG = "com_rincliu_library_common_persistence_image.webp:native";

namespace jrefs {

namespace java {
namespace lang {

jclass_NullPointerException::jclass_NullPointerException(JNIEnv* jniEnv)
{
	jclassRef = jniEnv->FindClass("java/lang/NullPointerException");
	assert(jclassRef == 0);
}
jclass_NullPointerException* NullPointerException = 0;

jclass_IllegalArgumentException::jclass_IllegalArgumentException(JNIEnv* jniEnv)
{
	jclassRef = jniEnv->FindClass("java/lang/IllegalArgumentException");
	assert(jclassRef == 0);
}
jclass_IllegalArgumentException* IllegalArgumentException = 0;

jclass_RuntimeException::jclass_RuntimeException(JNIEnv* jniEnv)
{
	jclassRef = jniEnv->FindClass("java/lang/RuntimeException");
	assert(jclassRef == 0);
}
jclass_RuntimeException* RuntimeException = 0;

} // namespace lang
} // namespace java

namespace android {
namespace graphics {

jclass_Bitmap* Bitmap = 0;
jclass_Bitmap::jclass_Bitmap(JNIEnv* jniEnv)
	: Config(jniEnv)
{
	jclassRef = jniEnv->FindClass("android/graphics/Bitmap");
	assert(jclassRef == 0);

	createBitmap = jniEnv->GetStaticMethodID(jclassRef,
		"createBitmap",
		"(IILandroid/graphics/Bitmap$Config;)Landroid/graphics/Bitmap;");
	assert(createBitmap);
}
jclass_Bitmap::jclass_Config::jclass_Config(JNIEnv* jniEnv)
{
	jclassRef = jniEnv->FindClass("android/graphics/Bitmap$Config");
	assert(jclassRef == 0);

	ARGB_8888 = jniEnv->GetStaticFieldID(jclassRef,
		"ARGB_8888",
		"Landroid/graphics/Bitmap$Config;");
	assert(ARGB_8888);
}

jclass_BitmapFactory* BitmapFactory = 0;
jclass_BitmapFactory::jclass_BitmapFactory(JNIEnv* jniEnv)
	: Options(jniEnv)
{
}
jclass_BitmapFactory::jclass_Options::jclass_Options(JNIEnv* jniEnv)
{
	jclassRef = jniEnv->FindClass("android/graphics/BitmapFactory$Options");
	assert(jclassRef == 0);
	
	inJustDecodeBounds = jniEnv->GetFieldID(jclassRef,
		"inJustDecodeBounds",
		"Z");
	assert(inJustDecodeBounds);

	outHeight = jniEnv->GetFieldID(jclassRef,
		"outHeight",
		"I");
	assert(outHeight);

	outWidth = jniEnv->GetFieldID(jclassRef,
		"outWidth",
		"I");
	assert(outWidth);
}

} // namespace graphics
} // namespace android
} // namespace jrefs

#ifdef __cplusplus
extern "C" {
#endif

JNIEXPORT jint JNICALL JNI_OnLoad
  (JavaVM *vm, void *reserved)
{
	JNIEnv *jniEnv = 0;
	if(vm->GetEnv((void **)&jniEnv, JNI_VERSION_1_6))
		return JNI_ERR; /* JNI version not supported */
	
	// Load Java classes
	jrefs::java::lang::IllegalArgumentException = new jrefs::java::lang::jclass_IllegalArgumentException(jniEnv);
	jrefs::java::lang::NullPointerException = new jrefs::java::lang::jclass_NullPointerException(jniEnv);
	jrefs::java::lang::RuntimeException = new jrefs::java::lang::jclass_RuntimeException(jniEnv);
	jrefs::android::graphics::Bitmap = new jrefs::android::graphics::jclass_Bitmap(jniEnv);
	jrefs::android::graphics::BitmapFactory = new jrefs::android::graphics::jclass_BitmapFactory(jniEnv);

	__android_log_print(ANDROID_LOG_INFO, LOG_TAG, "JNI_OnLoad completed");

	return JNI_VERSION_1_6;
}

#ifdef __cplusplus
}
#endif
