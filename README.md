# binary_lib
binary library/reading files
	//Своя кодировка
	class NUMBER_SYSTEM
	{
		public:

			string chars = "0123456789ABCDEF";
			int len = 16;
			int bitsy = 4;

	};

	int BinToDec(string bin); //Перевод из двоичной системы счисления в десятичную

	string DecToBin(int dec); //Перевод из десятичной системы счисления в двоичную

	string GetBinChar(char c); //Получить кодировку символа в двоичном коде

	string GetBinText(string inputtxt); //Получить кодировку всех символов в тексте в двоичном коде

	string GetBinFile(string path); //Получить кодировку всех символов в тексте в двоичном коде (из файла)

	string SetBinFile(string bin, string path); //Создать бинарный файл

	string SetBinString(string bin); //преобразовать двоичный код в символы

	string CreateNSBin(string input, NUMBER_SYSTEM ns); //создать двоичный код со своей кодировкой

	string GetNSBin(string input, NUMBER_SYSTEM ns); //Получить свой текст с собственной кодировкой
	
	map<string, string> ReadConf(string input); //Прочитать простейший conf текст
	/*
	Пример:
	string conf = "speed = 10; width = 92; name = Dog;"
	map<string, string>animal;
	animal = bin_vailib::ReadConf(conf);
	cout << "speed: " << animal["speed"];
	*/
