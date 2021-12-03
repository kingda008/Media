package com.baoge.media;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;

import com.baoge.baselib.ToastUtil;
import com.baoge.media.databinding.ActivityMainBinding;

public class MainActivity extends AppCompatActivity implements View.OnClickListener {

    // Used to load the 'media' library on application startup.
    static {
        System.loadLibrary("media");
    }

    private ActivityMainBinding binding;
    private String txtContent = "";
    TextView tv;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        binding = ActivityMainBinding.inflate(getLayoutInflater());
        setContentView(binding.getRoot());

        // Example of a call to a native method
        tv = binding.sampleText;
        tv.setText(stringFromJNI());

        initView();
    }

    private void initView() {
        ((Button) binding.btnNativeInvokeJava).setOnClickListener(this);
    }

    /**
     * A native method that is implemented by the 'media' native library,
     * which is packaged with this application.
     */
    public native String stringFromJNI();


    public native String func1();

    public static native String func2();

    public void callBack(int code){
        ToastUtil.show("回调返回值："+code);
    }

    @Override
    public void onClick(View v) {
        switch (v.getId()) {
            case R.id.btn_native_invoke_java: {
                String reslut = func1();
                tv.setText(txtContent + "  " + reslut);
            }
            break;
        }
    }
}