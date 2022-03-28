#include"LQueue.h"

int main()
{
	Link_Queue queue;
	LQueue* Q = NULL;
	while (true)
	{
		std::string select = queue.menu();
		switch (atoi(select.c_str()))
		{
		case 1:queue.InitLQueue(&Q);
			break;
		case 2:queue.EnLQueue(&Q);
			break;
		case 3:queue.DeLQueue(&Q);
			break;
		case 4:queue.LengthLQueue(Q);
			break;
		case 5:queue.GetHeadLQueue(Q);
			break;
		case 6:queue.TraverseLQueue(Q);
			break;
		case 7:queue.ClearLQueue(&Q);
			break;
		case 8:queue.DestoryLQueue(&Q);
			break;
		case 9:
			std::cout << "\t��л����ʹ�ã��ݰ�~~" << std::endl;
			system("pause");
			return 0;
		default:
			std::cout << "\t����������������룡" << std::endl;
			system("pause");
			system("cls");
			break;
		}
	}
	return 0;
}