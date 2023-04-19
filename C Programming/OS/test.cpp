#define N 100
typedef int semaphore;
semaphore empty = N;
semaphore full = 0;
semaphore mutex = 1;


void producer()
{
	int item;
	while(true)
	{
		item = produve_item();

		down(&empty);
		down(&mutex);
		insert_item(item);
		up(&mutex);
		up(&full);
	}
}
void producer()
{
	int item;
	while(true)
	{
		down(&full);
		down(&mutex);
		item = remove_item();
		up(&mutex);
		up(&empty);
		consume_item(item);
	}
}