package com.example.myapplication;

import androidx.appcompat.app.AppCompatActivity;

import android.app.Activity;
import android.os.Bundle;
import android.view.View;
import android.view.inputmethod.InputMethodManager;
import android.widget.AdapterView;
import android.widget.ArrayAdapter;
import android.widget.EditText;
import android.widget.ListView;

import java.util.ArrayList;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        animals.add("Кошки");
        animals.add("Собаки");
        animals.add("Хомяки");
        animals.add("Еноты");
        animals.add("Черепахи");

        // Закрепление имени за элементом
        animList = (ListView) findViewById(R.id.animList);
// Вызов конструктора для создания адаптера
        adapter = new ArrayAdapter<String>(this,
                android.R.layout.simple_list_item_multiple_choice, animals);
// Закрепление адаптера за элементом ListView
        animList.setAdapter(adapter);

        animList.setOnItemClickListener(new AdapterView.OnItemClickListener(){
            @Override
            public void onItemClick(AdapterView<?>parent,View v,int position, long id)
            {
// Сохранить нажатый элемент
                String anim = adapter.getItem(position);
                if(animList.isItemChecked(position)==true){
                    selectedAnimal.add(anim);
                }
                else{
                    selectedAnimal.remove(anim);
                }
            }
        });



        View view = this.getCurrentFocus();
        if (view != null) {
            InputMethodManager imm = (InputMethodManager) getSystemService(Activity.INPUT_METHOD_SERVICE);
            imm.hideSoftInputFromWindow(view.getWindowToken(), 0);
        }
    }

    public void OnClickAdd(View view) {
        EditText eText = (EditText) findViewById(R.id.eText);
        String anim = eText.getText().toString();
        if(!anim.isEmpty() && animals.contains(anim)==false) {
            adapter.add(anim);
            eText.setText("");
            adapter.notifyDataSetChanged();
        }
    }

    public void OnClickDel(View view) {
// Получить и удалить отмеченные строки
        for(int i=0; i< selectedAnimal.size();i++){
            adapter.remove(selectedAnimal.get(i));
        }
// Сбросить все установленные отметки
        animList.clearChoices();
// Очистить массив выбранных строк
        selectedAnimal.clear();

        adapter.notifyDataSetChanged();
    }


    ArrayList<String> animals = new ArrayList();// Массив строк
    ArrayList<String> selectedAnimal = new ArrayList();// Выбранные строки
    ArrayAdapter<String> adapter;// Адаптер для связи массива с ListView
    ListView animList;		// Имя элементы ListView


}
