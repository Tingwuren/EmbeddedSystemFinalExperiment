#include "user_selection.h"

void user_selection(Snake* snake)
{
	uint8_t select_key;
	int flag = 0;
	extern uint8_t gImage_info[];
	int action = 0;
	
	while(!action)
	{
		
		if(flag == 0) // ��Ӧ��һ���û�����
		{
			select_key = KEY_Scan(0);
			switch(select_key)
			{
				case 6:
					LCD_Fill(130, 135, 230, 185, Yellow);
					LCD_ShowString(150, 150, "��ģʽ", Red, Yellow);
					flag = 6;
					break;
				case 5:
					LCD_Fill(250, 135, 350, 185, Yellow);
					LCD_ShowString(270, 150, "����ģʽ", Red, Yellow);
					flag = 5;
					break;
				case 4:
					LCD_Fill(130, 205, 230, 255, Yellow);
					LCD_ShowString(150, 220, "����ģʽ", Red, Yellow);
					flag = 4;
					break;
				case 3:
					LCD_Fill(250, 205, 350, 255, Yellow);
					LCD_ShowString(270, 220, "��Ϸ˵��", Red, Yellow);
					flag = 3;
					break;
				case 0:
					break;
			}
		}
		if(flag == 6) // ���û���һ�ΰ���K6
		{
			select_key = KEY_Scan(0);
			switch(select_key)
			{
				case 6:
					flag = 0;
					action = 6;
					break;
				case 5:
					LCD_Fill(130, 135, 230, 185, White);
					LCD_ShowString(150, 150, "��ģʽ", Red, White);
					LCD_Fill(250, 135, 350, 185, Yellow);
					LCD_ShowString(270, 150, "����ģʽ", Red, Yellow);
					flag = 5;
					break;
				case 4:
					LCD_Fill(130, 135, 230, 185, White);
					LCD_ShowString(150, 150, "��ģʽ", Red, White);
					LCD_Fill(130, 205, 230, 255, Yellow);
					LCD_ShowString(150, 220, "����ģʽ", Red, Yellow);
					flag = 4;
					break;
				case 3:
					LCD_Fill(130, 135, 230, 185, White);
					LCD_ShowString(150, 150, "��ģʽ", Red, White);
					LCD_Fill(250, 205, 350, 255, Yellow);
					LCD_ShowString(270, 220, "��Ϸ˵��", Red, Yellow);
					flag = 3;
					break;
				case 0:
					break;
			}
		}
		if(flag == 5) // ���û���һ�ΰ���K5
		{
			select_key = KEY_Scan(0);
			switch(select_key)
			{
				case 6:
					LCD_Fill(250, 135, 350, 185, White);
					LCD_ShowString(270, 150, "����ģʽ", Red, White);
					LCD_Fill(130, 135, 230, 185, Yellow);
					LCD_ShowString(150, 150, "��ģʽ", Red, Yellow);
					flag = 6;
					break;
				case 5:
					flag = 0;
					action = 5;
					break;
				case 4:
					LCD_Fill(250, 135, 350, 185, White);
					LCD_ShowString(270, 150, "����ģʽ", Red, White);
					LCD_Fill(130, 205, 230, 255, Yellow);
					LCD_ShowString(150, 220, "����ģʽ", Red, Yellow);
					flag = 4;
					break;
				case 3:
					LCD_Fill(250, 135, 350, 185, White);
					LCD_ShowString(270, 150, "����ģʽ", Red, White);
					LCD_Fill(250, 205, 350, 255, Yellow);
					LCD_ShowString(270, 220, "��Ϸ˵��", Red, Yellow);
					flag = 3;
					break;
				case 0:
					break;
			}
		}
		if(flag == 4) // ���û���һ�ΰ���K4
		{
			select_key = KEY_Scan(0);
			switch(select_key)
			{
				case 6:
					LCD_Fill(130, 205, 230, 255, White);
					LCD_ShowString(150, 220, "����ģʽ", Red, White);
					LCD_Fill(130, 135, 230, 185, Yellow);
					LCD_ShowString(150, 150, "��ģʽ", Red, Yellow);
					flag = 6;
					break;
				case 5:
					LCD_Fill(130, 205, 230, 255, White);
					LCD_ShowString(150, 220, "����ģʽ", Red, White);
					LCD_Fill(250, 135, 350, 185, Yellow);
					LCD_ShowString(270, 150, "����ģʽ", Red, Yellow);
					flag = 5;
					break;
				case 4:
					flag = 0;
					action = 4;
					break;
				case 3:
					LCD_Fill(130, 205, 230, 255, White);
					LCD_ShowString(150, 220, "����ģʽ", Red, White);
					LCD_Fill(250, 205, 350, 255, Yellow);
					LCD_ShowString(270, 220, "��Ϸ˵��", Red, Yellow);
					flag = 3;
					break;
				case 0:
					break;
			}
		}
		if(flag == 3) // ���û���һ�ΰ���K3
		{
			select_key = KEY_Scan(0);
			switch(select_key)
			{
				case 6:
					LCD_Fill(250, 205, 350, 255, White);
					LCD_ShowString(270, 220, "��Ϸ˵��", Red, White);
					LCD_Fill(130, 135, 230, 185, Yellow);
					LCD_ShowString(150, 150, "��ģʽ", Red, Yellow);
					flag = 6;
					break;
				case 5:
					LCD_Fill(250, 205, 350, 255, White);
					LCD_ShowString(270, 220, "��Ϸ˵��", Red, White);
					LCD_Fill(250, 135, 350, 185, Yellow);
					LCD_ShowString(270, 150, "����ģʽ", Red, Yellow);
					flag = 5;
					break;
				case 4:
					LCD_Fill(250, 205, 350, 255, White);
					LCD_ShowString(270, 220, "��Ϸ˵��", Red, White);
					LCD_Fill(130, 205, 230, 255, Yellow);
					LCD_ShowString(150, 220, "����ģʽ", Red, Yellow);
					flag = 4;
					break;
				case 3:
					// action = 3;
					LCD_Fill(0, 0, 480, 272, White);
					LCD_DrawPicture(99,0,381,282, gImage_info); // ����Ϸ˵��ͼƬ���س���
					LCD_ShowString(15, 15, "��Ϸ����", Black, Transparent);
					LCD_ShowString(15, 40, "1. �����˵�ҳ����K6ѡ���ģʽ���ٰ�һ�ο�ʼ��Ϸ��", Blue, Transparent);
					LCD_ShowString(15, 65, "2. �����˵�ҳ����K5ѡ������ģʽ���ٰ�һ�ο�ʼ��Ϸ��", Blue, Transparent);
					LCD_ShowString(15, 90, "3. �����˵�ҳ����K4ѡ�����ģʽ���ٰ�һ�ο�ʼ��Ϸ��", Blue, Transparent);
					LCD_ShowString(15, 115, "4. �����˵�ҳ����K3ѡ����Ϸ˵�����ٰ�һ�δ򿪹���˵�����档", Blue, Transparent);
					LCD_ShowString(15, 140, "5. ��ʼ��Ϸ��K6�����������ƶ���K3�����������ƶ���", Blue, Transparent);
					// Todo:����bug������3����ʾ
					LCD_ShowString(15, 165, "6. ��ʼ��Ϸ��K5�����������ƶ���K4�����������ƶ���", Blue, Transparent);
					// Todo:����bug������4����ʾ
					LCD_ShowString(15, 190, "7. ��ʼ��Ϸ����ÿ��һ��ʳ��͵�һ�֡�", Blue, Transparent);
					LCD_ShowString(15, 215, "8. ��ʼ��Ϸ����ͷ�˶�����Ļʱ����������ҧ������ʱҲ������", Blue, Transparent);
					LCD_ShowString(350, 15, "��K3�������˵�", Red, Transparent);
					// Todo: ����bug��K3����ʾ
					
					while(1)
					{
						select_key = KEY_Scan(0);
						if(select_key == 3)
						{
							break;
						}
					}
					initialize();
					flag = 0;
					break;
				case 0:
					break;
			}
		}
	}
	snake->speed = 0;
	snake->alive = 0;
	
	switch(action)
	{
		case 6:
			// ��ģʽ
			snake->speed = 10;
			snake->alive = 1;
			break;
		case 5:
			// ����ģʽ
			snake->speed = 20;
			snake->alive = 1;
			break;
		case 4:
			// ����ģʽ
			snake->speed = 30;
			snake->alive = 1;
			break;
		case 3:
			break;
	}
	
}
