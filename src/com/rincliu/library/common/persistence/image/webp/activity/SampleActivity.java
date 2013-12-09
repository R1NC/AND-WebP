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
package com.rincliu.library.common.persistence.image.webp.activity;

import java.io.ByteArrayOutputStream;
import java.io.File;
import java.io.FileOutputStream;
import java.io.InputStream;

import com.rincliu.library.common.persistence.image.webp.WebPFactory;
import com.rincliu.library.R;

import android.app.Activity;
import android.content.Intent;
import android.database.Cursor;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.net.Uri;
import android.os.Bundle;
import android.os.Environment;
import android.os.Handler;
import android.os.Message;
import android.provider.MediaStore;
import android.view.View;
import android.view.Window;
import android.widget.ImageView;
import android.widget.Toast;

public class SampleActivity extends Activity implements View.OnClickListener
{
    private ImageView iv = null;

    private File file = null;

    private String filePath = null;

    private boolean isEncoding = false;

    private final int MSG_SELECT_IMG = 1;

    private final int MSG_CAPTURE_IMG = 2;

    private final int MSG_SHOW_BITMAP = 3;

    private final int MSG_ERROR = 4;

    private byte[] streamToBytes(InputStream is)
    {
        ByteArrayOutputStream os = new ByteArrayOutputStream(1024);
        byte[] buffer = new byte[1024];
        int len;
        try
        {
            while ((len = is.read(buffer)) >= 0)
            {
                os.write(buffer, 0, len);
            }
        }
        catch (Exception e)
        {
            e.printStackTrace();
            handler.sendEmptyMessage(MSG_ERROR);
        }
        return os.toByteArray();
    }

    @Override
    public void onCreate(Bundle savedInstanceState)
    {
        super.onCreate(savedInstanceState);
        requestWindowFeature(Window.FEATURE_INDETERMINATE_PROGRESS);
        setContentView(R.layout.main);
        setTitle(R.string.app_name);
        iv = (ImageView) findViewById(R.id.iv);
        findViewById(R.id.btn1).setOnClickListener(this);
        findViewById(R.id.btn2).setOnClickListener(this);
        findViewById(R.id.btn3).setOnClickListener(this);
    }

    @Override
    protected void onActivityResult(int requestCode, int resultCode, Intent intent)
    {
        super.onActivityResult(requestCode, resultCode, intent);
        filePath = null;
        switch (requestCode)
        {
            case MSG_SELECT_IMG:
                if (resultCode == RESULT_OK)
                {
                    Uri selectedImage = intent.getData();
                    String[] filePathColumn = {MediaStore.Images.Media.DATA};
                    Cursor cursor = getContentResolver().query(selectedImage, filePathColumn, null, null, null);
                    cursor.moveToFirst();
                    int columnIndex = cursor.getColumnIndex(filePathColumn[0]);
                    filePath = cursor.getString(columnIndex);
                    cursor.close();
                }
                break;
            case MSG_CAPTURE_IMG:
                if (resultCode == RESULT_OK)
                {
                    filePath = file.getAbsolutePath();
                    file = null;
                }
                break;
        }
        if (filePath != null)
        {
            if (isEncoding)
            {
                Toast.makeText(this, "Please wait last encoding!", Toast.LENGTH_SHORT).show();
            }
            else
            {
                setTitle("Encoding...");
                setProgressBarIndeterminateVisibility(true);
                new Thread()
                {
                    @Override
                    public void run()
                    {
                        isEncoding = true;
                        Bitmap selectedBitmap = BitmapFactory.decodeFile(filePath);
                        byte[] webpImageData = WebPFactory.nativeEncodeBitmap(selectedBitmap, 100);
                        try
                        {
                            FileOutputStream dumpStream = new FileOutputStream(new File(
                                    Environment.getExternalStorageDirectory(), "dump.webp"));
                            dumpStream.write(webpImageData);
                            dumpStream.close();
                        }
                        catch (Exception e)
                        {
                            e.printStackTrace();
                            handler.sendEmptyMessage(MSG_ERROR);
                        }
                        Bitmap webpBitmap = WebPFactory.nativeDecodeByteArray(webpImageData, null);
                        Message msg = new Message();
                        msg.what = MSG_SHOW_BITMAP;
                        msg.obj = webpBitmap;
                        handler.sendMessage(msg);
                        isEncoding = false;
                    }
                }.start();
            }
        }
    }

    @Override
    public void onClick(View arg0)
    {
        switch (arg0.getId())
        {
            case R.id.btn1:
                InputStream rawImageStream = getResources().openRawResource(R.raw.image);
                byte[] data = streamToBytes(rawImageStream);
                System.out.println("isWebP: " + WebPFactory.isWebP(data));
                final Bitmap webpBitmap = WebPFactory.nativeDecodeByteArray(data, null);
                iv.setImageBitmap(webpBitmap);
                break;
            case R.id.btn2:
                Intent intent2 = new Intent();
                intent2.setType("image/*");
                intent2.setAction(Intent.ACTION_GET_CONTENT);
                startActivityForResult(Intent.createChooser(intent2, "Select:"), MSG_SELECT_IMG);
                break;
            case R.id.btn3:
                Intent intent3 = new Intent(android.provider.MediaStore.ACTION_IMAGE_CAPTURE);
                file = new File(Environment.getExternalStorageDirectory(), "camera.jpg");
                intent3.putExtra(MediaStore.EXTRA_OUTPUT, Uri.fromFile(file));
                startActivityForResult(intent3, MSG_CAPTURE_IMG);
                break;
        }
    }

    private Handler handler = new Handler()
    {
        @Override
        public void handleMessage(Message msg)
        {
            switch (msg.what)
            {
                case MSG_SHOW_BITMAP:
                    setProgressBarIndeterminateVisibility(false);
                    setTitle(R.string.app_name);
                    iv.setImageBitmap((Bitmap) msg.obj);
                    break;
                case MSG_ERROR:
                    setProgressBarIndeterminateVisibility(false);
                    setTitle("Exception occured!");
                    break;
            }
        }
    };
}
