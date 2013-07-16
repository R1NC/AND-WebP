package com.rincliu.webp;

import android.graphics.Bitmap;
import android.graphics.BitmapFactory;

/**
 * Factory to encode and decode WebP images into Android Bitmap
 * @author Rinc Liu
 */
public final class WebPFactory {
	
	// Load library
	static{
		System.loadLibrary("WebP-Android");
	}

	/**
	 * Decodes byte array to bitmap 
	 * @param data Byte array with WebP bitmap data
	 * @param opts Options to control decoding. Accepts null
	 * @return Decoded bitmap
	 */
	public static native Bitmap nativeDecodeByteArray(byte[] data, BitmapFactory.Options options);
	
	/**
	 * Encodes bitmap into byte array
	 * @param bitmap Bitmap
	 * @param quality Quality, should be between 0 and 100
	 * @return Encoded byte array
	 */
	public static native byte[] nativeEncodeBitmap(Bitmap bitmap, int quality);
	
	/**
	 * 
	 * @param data
	 * @return
	 */
	public static boolean isWebP(byte[] data){
		return data!=null&&data.length>14
				&&data[0]=='R'&&data[1]=='I'&&data[2]=='F'&&data[3]=='F'
				&&data[8]=='W'&&data[9]=='E'&&data[10]=='B'&&data[11]=='P';
	}
}