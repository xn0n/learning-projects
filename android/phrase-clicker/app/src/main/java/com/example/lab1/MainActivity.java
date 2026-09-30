package com.example.lab1;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;
import android.widget.Toast;

import java.util.concurrent.TimeUnit;

public class MainActivity extends AppCompatActivity {

    Button bt;
    TextView txtA, txtV;

    String[] phrase = {"кто", "", "и", "шутя", "и", "скоро", "пожелаетъ", "пи",
            "узнать", "число", "ужъ", "знает", ""};

    int n = -1, k;
    boolean fl = true;
    String st, stn, str = "";

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        txtA = findViewById(R.id.txtA);
        txtV = findViewById(R.id.txtV);
        bt = findViewById(R.id.bt);
        txtV.setText("Цифры числа пи");
        bt.setOnClickListener(new View.OnClickListener() {
            public void onClick(View v) {
                if (n >= 11) {
                    String s = "Больше цифр не знаю";
                    Toast toast = Toast.makeText(MainActivity.this, s, Toast.LENGTH_LONG);
                    toast.show();
                    try {
                        TimeUnit.SECONDS.sleep(2L);
                    } catch (InterruptedException e) {
                        throw new RuntimeException(e);
                    }
                } else {
                    n++;
                    st = phrase[n];
                    if (n == 1) stn = ",";
                    else {
                        k = st.length();
                        stn = String.valueOf(k);
                    }
                    str = str + stn;
                    txtV.setText(str);
                }
            }
        });
    }
}
