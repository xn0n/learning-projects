package com.example.kamen;

import static com.example.kamen.R.id.reset;

import androidx.appcompat.app.AppCompatActivity;

import android.annotation.SuppressLint;
import android.os.Bundle;
import android.os.CountDownTimer;
import android.view.View;
import android.widget.Button;
import android.widget.ImageView;

import java.util.Random;

public class MainActivity extends AppCompatActivity implements View.OnClickListener { // Ошибка 1: Не указано, что MainActivity должно реализовывать интерфейс View.OnClickListener


    @Override
    protected void onCreate(Bundle savedInstanceState) {

        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
// Закрепление имен за элементами управления
        imgPlayer = findViewById(R.id.imgPlayer); // Ошибка 2: Переменные imgPlayer, imgComp, st, sc, pap, reset не объявлены
        imgComp = findViewById(R.id.imgComp);
        st = findViewById(R.id.st);
        sc = findViewById(R.id.sc);
        pap = findViewById(R.id.pap);
        reset = findViewById(R.id.reset);
        scorePlay = 3; // Ошибка 3: Переменные scoreComp, scorePlay и res не были инициализированы
        scoreComp = 0;
        res = 0;

        sc.setOnClickListener(this); // Ошибка 4: Неправильно установлен OnClickListener
        st.setOnClickListener(this);
        pap.setOnClickListener(this);
        reset.setOnClickListener(this);


    }

    // Глобальные объявления
    Button st, sc, pap, reset;// Кнопки
    ImageView imgPlayer;// Изображение для Usera
    ImageView imgComp;// Изображение для Computera
    // Массив изображений для Computera
    int[] compImg = {R.drawable.stor, R.drawable.scissr, R.drawable.paper, R.drawable.empty};
    Integer scoreComp, scorePlay, res;// Выборы игроков и результат


    @SuppressLint("NonConstantResourceId")
    public void onClick(View view) { // Ошибка 5: Метод onClick(View view) не был реализован
        int num = 0;// Значение num - выигрыш для Usera
        if (view.getId() == R.id.st) { // Камень
            imgPlayer.setImageResource(R.drawable.stol);
            num = playing(1);// Вызов хода компьютера
            if (num == 1) res = 3;   // Ничья
            else if (num == 2) res = 1;   // Comp выбрал ножницы
            else res = 2;            // Comp выбрал бумагу
        } else if (view.getId() == R.id.sc) { // Ножницы
            imgPlayer.setImageResource(R.drawable.scissl);
            num = playing(2);
            if (num == 2) res = 3;// Ничья
            else if (num == 1) res = 2;// Comp выбрал камень
            else res = 1;         // Comp выбрал бумагу
        } else if (view.getId() == R.id.pap) { // Бумага
            imgPlayer.setImageResource(R.drawable.papel);
            num = playing(3);
            if (num == 3) res = 3; // Ничья
            else if (num == 2) res = 2; // Comp выбрал ножницы
            else res = 1;          // Comp выбрал камень
        } else if (view.getId() == R.id.reset) { // Возврат в исходное положение
            imgPlayer.setImageResource(R.drawable.empty);
            scorePlay = 3;
            imgComp.setImageResource(compImg[3]);
        }


        showVisual(res);// Показать итог кона
    }

    private void showVisual(Integer res) {

    }

    public int playing(Integer scorePlay) {// scorePlay выбор игрока
        Random ran = new Random();// Числа отсчитываются от нуля
        scoreComp = ran.nextInt(3) + 1;// Чтобы счет от 1
        //  if (!scorePlay.equals(scoreComp)) {
        switch (scoreComp) {
            case 1: // Вернуть камень
                imgComp.setImageResource(R.drawable.stor);
                break;
            case 2: // Вернуть ножницы
                imgComp.setImageResource(R.drawable.scissr);
                break;
            case 3: // Вернуть бумагу
                imgComp.setImageResource(R.drawable.paper);
                break;
//        }
            //   }
//    else scoreComp =scorePlay;// Ничья ‘эта проверка в другом месте
            return scoreComp;
        }
        private void showVisual ( int num){
            // Задержка времени 1-я цифра время задержки (ms), 2-я такт
            new CountDownTimer(3000, 1000) {
                public void onFinish() {
                    switch (num) {
                        case 1: // Выиграл игрок
                            imgPlayer.setImageResource(R.drawable.win);
                            imgComp.setImageResource(R.drawable.loss);
                            break;
                        case 2: // Выиграл компьютер
                            imgPlayer.setImageResource(R.drawable.loss);
                            imgComp.setImageResource(R.drawable.win);
                            break;
                        case 3: // Ничья
                            imgPlayer.setImageResource(R.drawable.confusion);
                            imgComp.setImageResource(R.drawable.confusion);
                            break;
                    }
                }

                // Метод для отсчета тактов (не используется)
                public void onTick(long millisUntilFinished) {
                }
            }.start();
        }
    }
}







