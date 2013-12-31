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
package com.rincliu.library.common.persistence.image.webp;

import android.graphics.Bitmap;
import android.graphics.BitmapFactory;

/**
 * Factory to encode and decode WebP images into Android Bitmap
 * 
 * @author Rinc Liu
 */
public final class WebPFactory {

    // Load library
    static {
        System.loadLibrary("WebP-Android");
    }

    /**
     * Decodes byte array to bitmap
     * 
     * @param data Byte array with WebP bitmap data
     * @param opts Options to control decoding. Accepts null
     * @return Decoded bitmap
     */
    public static native Bitmap nativeDecodeByteArray(byte[] data, BitmapFactory.Options options);

    /**
     * Encodes bitmap into byte array
     * 
     * @param bitmap Bitmap
     * @param quality Quality, should be between 0 and 100
     * @return Encoded byte array
     */
    public static native byte[] nativeEncodeBitmap(Bitmap bitmap, int quality);

    /**
     * Verifies bitmap's format
     * 
     * @param data
     * @return
     */
    public static boolean isWebP(byte[] data) {
        return data != null && data.length > 12 && data[0] == 'R' && data[1] == 'I' && data[2] == 'F' && data[3] == 'F'
                && data[8] == 'W' && data[9] == 'E' && data[10] == 'B' && data[11] == 'P';
    }
}
