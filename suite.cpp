#include <FL/Fl.H>
#include<iostream>
#include <FL/Fl_Button.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Output.H>
#include<FL\Fl_JPEG_Image.H>
#include<FL\Fl_Image.H>
#include <FL/Fl_Box.H>
#include<FL\Fl_Shared_Image.H>
#include<FL\fl_ask.H>
#include <cstdlib>   
#include<string>
#include<Windows.h>
#include<vector>
#include<time.h>
#include<fstream>
#include<cstring>
#include<FL\fl_show_colormap.H>
#include<FL\Fl_Text_Display.H>
#include <FL/Fl_BMP_Image.H>
#include<stdio.h>
#include<FL\Fl_Double_Window.H>
#include<FL\Fl_Scroll.H>

using namespace std;

string name;

void creds(Fl_Widget* o, void* );
void steg_op(Fl_Widget* , void* );
void steg_de(Fl_Widget*, void*);
void steg_win(Fl_Widget* , void*);
void steg(Fl_Widget* , void*);
void bmp_win(Fl_Widget* , void*);
void vigde_win(Fl_Widget*, void*);
void vignere2(Fl_Widget* , void* );
void vig_de(Fl_Widget* , void*);
void vig_e(Fl_Widget* , void*);
void vig_win(Fl_Widget* , void* );
void cd_window(Fl_Widget*, void*);
void copy_cb3(Fl_Widget*, void*);
void copy_cb2(Fl_Widget* , void*);
void ceasar2(Fl_Widget*, void*);
void c_window(Fl_Widget*, void*);
void copy_cb(Fl_Widget*, void*);  
void close_cb(Fl_Widget*, void*);
void make_window(Fl_Widget*, void*);
void menu_window(Fl_Widget*, void*);
void close1(void *);
string encrypt(string);

void fl_color(uchar 	r,
	uchar 	g,
	uchar 	b
);


//#include<bits/stdc++.h>
#include "bitmap_image.hpp"
using namespace std;
struct col
{
	unsigned char red;
	unsigned char green;
	unsigned char blue;
}m;
vector <col> c;
vector <char> s;
void encode(char a, char b, char c)
{
	m.red = a;
	m.green = b;
	m.blue = c;
}
string decode_caller(string x)
{
	//cout << "please enter the name of the file from which you want to retrive the message" << endl;
	cin >> x;
	bitmap_image image((x + ".bmp").c_str());
	x.erase();
	int height = image.height();
	int width = image.width();
	bitmap_image cool(width, height);
	cool.clear();
	for (int j = 0; j<height; j++)
	{
		for (int i = 0; i<width; i++)
		{
			rgb_t colour;
			image.get_pixel(i, j, colour);
			m.red = colour.red;
			m.blue = colour.blue;
			m.green = colour.green;
			cool.set_pixel(i, j, m.red, m.green, m.blue);
			x.push_back(m.red);
			x.push_back(m.green);
			x.push_back(m.blue);

		}
	}
	cool.save_image("x.bmp");
	char message[200];
	for (int i = 0; i<x.size(); i++)
	{
		if (x.at(i) == '#')
			break;
		else
			message[i]= x.at(i);
	}return message;
}
void encode_caller( string ta,string x)
{
	char *exe = &ta[0u];
	//char exe[] = ta.c_str;
	int q = 0;

	char ch;
	//cout << "please enter the required message and terminate it with #" << endl;
	while (exe)
	{
		ch = exe[q];
		if (ch != '#')
			s.push_back(ch);
		else
		{
			s.push_back(ch);
			break;
		}
		
		q++;
	}
	int t = s.size();
	int o = 0;
	cout << "please enter the name of the file on which you want to hide the message" << endl;
	cin >> x;
	if (!x.size() % 3)
		x += '#';
	if (!x.size() % 3)
		x += '#';
	bitmap_image image((x + ".bmp").c_str());
	int height = image.height();
	int width = image.width();
	bitmap_image cool(width, height);
	for (int j = 0; j<height; j++)
	{
		for (int i = 0; i<width; (i++))
		{
			if (o<t)
			{
				rgb_t colour;
				image.get_pixel(i, j, colour);
				encode(s.at(o), s.at(o + 1), s.at(o + 2));
				cool.set_pixel(i, j, m.red, m.green, m.blue);
				o += 3;

			}
			else
			{
				rgb_t colour;
				image.get_pixel(i, j, colour);
				cool.set_pixel(i, j, colour);
			}

		}
	}
	cool.save_image("cool1.bmp");
}



class encrypt
{
public:
	string a;
	string b;
	int s;

	void get_encrypt()
	{
		cout << "enter a";
		cout << "enter b";
		cout << "enter s";
		cin >> a;
		cin >> b;
		cin >> s;

	}
	string XOR_encrypt()
	{
		int k = 0;
		for (int i = 0; i<a.length(); i++)
		{
			a[i] = a[i] ^ b[0];
			//k=(++k<b.length()?k:0);
		}
		return a;
	}

	string ceaser_encrypt()
	{

		for (int i = 0; i<a.length(); i++)
		{

			if (isupper(a[i]))
				a[i] = char(int(a[i] + s - 65) % 26 + 65);


			else
				a[i] = char(int(a[i] + s - 97) % 26 + 97);

		}

		return a;
	}
	string vignere_encrypt()
	{
		string m;

		for (int i = 0, j = 0; i < a.length(); ++i)
		{
			char c = a[i];

			if (c >= 'a' && c <= 'z')
				c += 'A' - 'a';
			else if (c < 'A' || c > 'Z')
				continue;

			m += (c + b[j] - 2 * 'A') % 26 + 'A';
			j = (j + 1) % b.length();
		}

		return m;
	}

}grt;

class decrypt
{
public:
	string a;
	string b;
	int s;


	void get_decrypt()
	{
		cout << "enter a";
		cout << "enter b";
		cout << "enter s";
		cin >> a;
		cin >> b;
		cin >> s;

	}
	string XOR_decrypt()
	{
		int k = 0;
		for (int i = 0; i<a.length(); i++)
		{
			a[i] = a[i] ^ b[k];

		}
		return a;
	}

	string ceaser_decrypt()
	{
		for (int i = 0; i<a.length(); i++)
		{

			if (isupper(a[i]))
				a[i] = char(int(a[i] - s - 65) % 26 + 65);


			else
				a[i] = char(int(a[i] - s - 97) % 26 + 97);

		}
		return a;
	}
	string vignere_decrypt()
	{
		string out;

		for (int i = 0, j = 0; i < a.length(); ++i)
		{
			char c = a[i];

			if (c >= 'a' && c <= 'z')
				c += 'A' - 'a';
			else if (c < 'A' || c > 'Z')
				continue;

			out += (c - b[j] + 26) % 26 + 'A';
			j = (j + 1) % b.length();
		}

		return out;
	}

}gtr;


int main() {
	
	Fl_Window* pwin = new Fl_Window(1280, 720, "pic");
	pwin->begin();
	Fl_JPEG_Image* im = new Fl_JPEG_Image("cavaman1.jpg");
	double w = im->w();
	double h = im->h();
	double d = im->d();
	Fl_Box*       box = new Fl_Box(10, 10, 1280 - 20, 720 - 20);
	box->image(im);
	pwin->add(box);
	Fl_Button*  cloose = new Fl_Button(1000, 600, 100, 30, "START");
	cloose->callback(menu_window, pwin);
	pwin->show();
	return Fl::run();
}


void creds(Fl_Widget* o, void* v) 
{
	Fl_Double_Window* pwin = new Fl_Double_Window(1280, 720, "pic");
	pwin->begin();
	Fl_JPEG_Image* im = new Fl_JPEG_Image("credits.jpg");
	double w = im->w();
	double h = im->h();
	double d = im->d();
	Fl_Box*       box = new Fl_Box(0, 0, im->w(), im->h());
	box->image(im);
	pwin->add(box);
	pwin->end();
	pwin->show();
	
}




void menu_window(Fl_Widget* o, void* v)
{
	close1(v);
	Fl_Window* win1 = new Fl_Window(1280, 720, "menu");
	win1->color(fl_rgb_color(30, 30, 30));
	win1->label("security suite");
	Fl_Output *out = new Fl_Output(740, 70,0 , 0, "Security Suite");
	out->labelsize(34);
	out->labelcolor(fl_rgb_color(255,140,3));
	out->labelfont(FL_HELVETICA);
	Fl_Output *outt = new Fl_Output(800, 72, 0, 0, "BETA");
	outt->labelsize(20);
	outt->labelcolor(fl_rgb_color(255, 140, 3));
	outt->labelfont(FL_HELVETICA);
	Fl_Button*  xor = new Fl_Button(580, 200, 140, 30, "XOR Encryption");
	xor->labelcolor(fl_rgb_color(255, 140, 3));
	xor->color(fl_rgb_color(62, 62, 66));
	xor->callback(make_window,win1);
	Fl_Button* ceasar = new Fl_Button(580, 350, 140, 30, "Ceasar Encryption");
	ceasar->labelcolor(fl_rgb_color(255, 140, 3));
	ceasar->color(fl_rgb_color(62, 62, 66));
	ceasar->callback(ceasar2,win1);
	Fl_Button* V1 = new Fl_Button(580, 400, 140, 30, "Vignere Encryption");
	V1->labelcolor(fl_rgb_color(255, 140, 3));
	V1->color(fl_rgb_color(62, 62, 66));
	V1->callback(vignere2,win1);
	Fl_Button* bmp = new Fl_Button(580, 275, 140, 30, "Steganography");
	bmp->labelcolor(fl_rgb_color(255, 140, 3));
	bmp->color(fl_rgb_color(62, 62, 66));
	bmp->callback(steg_op,win1);
	Fl_Button* close = new Fl_Button(580, 600, 70, 30, "&Quit");
	close->callback(close_cb);
	close->color(fl_rgb_color(62, 62, 66));
	close->labelcolor(fl_rgb_color(255, 140, 3));
	Fl_Button* cred = new Fl_Button(580, 500, 140, 30, "Credits");
	cred->callback(creds);
	cred->color(fl_rgb_color(62, 62, 66));
	cred->labelcolor(fl_rgb_color(255, 140, 3));
	win1->show();
}

void make_window(Fl_Widget* o, void* v ) {
	close1(v);
	Fl_Window* win = new Fl_Window(1280, 720, "SECURITY SUITE");
	win->color(fl_rgb_color(30,30,30));
	win->begin();
	Fl_Button*  copy = new Fl_Button(550, 300, 180, 30, "ENCRYPT/DECRYPT");
	copy->color(fl_rgb_color(62, 62, 66));
	copy->labelcolor(fl_rgb_color(255, 140, 3));
	Fl_Button* close = new Fl_Button(580, 600, 70, 30, "&QUIT");
	close->color(fl_rgb_color(62, 62, 66));
	close->labelcolor(fl_rgb_color(255, 140, 3));
	Fl_Input*  inp = new Fl_Input(250, 150, 200, 30, "Enter Text");
	inp->align(FL_ALIGN_TOP | FL_ALIGN_CENTER);
	inp->color(fl_rgb_color(62, 62, 66));
	inp->labelcolor(fl_rgb_color(255, 140, 3));
	Fl_Output* out = new Fl_Output(500, 400, 250, 100, "Output");
	out->align(FL_ALIGN_TOP | FL_ALIGN_CENTER);
	out->color(fl_rgb_color(62, 62, 66));
	out->labelcolor(fl_rgb_color(255, 140, 3));
	Fl_Input*  inp2 = new Fl_Input(800, 150, 140, 30, "Enter Key ");
	inp2->align(FL_ALIGN_TOP | FL_ALIGN_CENTER);
	inp2->color(fl_rgb_color(62, 62, 66));
	inp2->labelcolor(fl_rgb_color(255, 140, 3));
	Fl_Output *out1 = new Fl_Output(740, 70, 0, 0, "XOR Encryption");
	out1->labelsize(34);
	out1->labelcolor(fl_rgb_color(255, 140, 3));
	out1->labelfont(FL_HELVETICA);
	Fl_Button*  xor = new Fl_Button(1050, 30, 140, 30, "Main Menu");
	xor->labelcolor(fl_rgb_color(255, 140, 3));
	xor->color(fl_rgb_color(62, 62, 66));
	xor->callback(menu_window, win);
	win->show();
	win->end();
	copy->callback(copy_cb);
	close->callback(close_cb);
	
	
}
void ceasar2(Fl_Widget* o, void* v)
{
	close1(v);
	Fl_Window* win = new Fl_Window(1280, 720, "Security Suite");
	win->color(fl_rgb_color(30, 30, 30));
	Fl_Output *out1 = new Fl_Output(740, 70, 0, 0, "Ceasar Encryption");
	out1->labelsize(34);
	out1->labelcolor(fl_rgb_color(255, 140, 3));
	out1->labelfont(FL_HELVETICA);
	Fl_Button*  copy = new Fl_Button(550, 300, 180, 30, "ENCRYPT");
	copy->color(fl_rgb_color(62, 62, 66));
	copy->labelcolor(fl_rgb_color(255, 140, 3));
	Fl_Button*  copy2 = new Fl_Button(550, 400, 180, 30, "DECRYPT");
	copy2->color(fl_rgb_color(62, 62, 66));
	copy2->labelcolor(fl_rgb_color(255, 140, 3));
	Fl_Button*  xor = new Fl_Button(1050, 30, 140, 30, "Main Menu");
	xor->labelcolor(fl_rgb_color(255, 140, 3));
	xor->color(fl_rgb_color(62, 62, 66));
	xor->callback(menu_window, win);
	win->show();
	copy->callback(c_window);
	copy2->callback(cd_window);
}

void c_window(Fl_Widget* o, void* v) {
	
	Fl_Window* win = new Fl_Window(1280, 720, "SECURITY SUITE");
	win->color(fl_rgb_color(30, 30, 30));
	win->begin();
	
	Fl_Button*  copy = new Fl_Button(550, 350, 180, 30, "ENCRYPT");
	copy->color(fl_rgb_color(62, 62, 66));
	copy->labelcolor(fl_rgb_color(255, 140, 3));
	Fl_Button* close = new Fl_Button(580, 600, 70, 30, "&QUIT");
	close->color(fl_rgb_color(62, 62, 66));
	close->labelcolor(fl_rgb_color(255, 140, 3));
	Fl_Input*  inp = new Fl_Input(550, 150, 200, 30, "Enter Text");
	inp->align(FL_ALIGN_TOP | FL_ALIGN_CENTER);
	inp->color(fl_rgb_color(62, 62, 66));
	inp->labelcolor(fl_rgb_color(255, 140, 3));
	Fl_Output* out = new Fl_Output(520, 450, 250, 100, "Output");
	out->align(FL_ALIGN_TOP | FL_ALIGN_CENTER);
	out->color(fl_rgb_color(62, 62, 66));
	out->labelcolor(fl_rgb_color(255, 140, 3));
	Fl_Input*  inp2 = new Fl_Input(550, 250, 200, 30, "Enter Key");
	inp2->align(FL_ALIGN_TOP | FL_ALIGN_CENTER);
	inp2->color(fl_rgb_color(62, 62, 66));
	inp2->labelcolor(fl_rgb_color(255, 140, 3));
	copy->callback(copy_cb2);
	close->callback(close_cb);
	Fl_Output *out1 = new Fl_Output(780, 70, 0, 0, "Ceasar Encryption");
	out1->labelsize(34);
	out1->labelcolor(fl_rgb_color(255, 140, 3));
	out1->labelfont(FL_HELVETICA);
	
	win->show();

}


void vignere2(Fl_Widget* o, void* v)
{
	close1(v);
	Fl_Window* win = new Fl_Window(1280, 720, "Security Suite");
	win->color(fl_rgb_color(30, 30, 30));
	Fl_Output *out1 = new Fl_Output(740, 70, 0, 0, "Vignere Encryption");
	out1->labelsize(34);
	out1->labelcolor(fl_rgb_color(255, 140, 3));
	out1->labelfont(FL_HELVETICA);
	Fl_Button*  copy = new Fl_Button(550, 300, 180, 30, "ENCRYPT");
	copy->color(fl_rgb_color(62, 62, 66));
	copy->labelcolor(fl_rgb_color(255, 140, 3));
	Fl_Button*  copy2 = new Fl_Button(550, 400, 180, 30, "DECRYPT");
	copy2->color(fl_rgb_color(62, 62, 66));
	copy2->labelcolor(fl_rgb_color(255, 140, 3));
	Fl_Button*  xor = new Fl_Button(1050, 30, 140, 30, "Main Menu");
	xor->labelcolor(fl_rgb_color(255, 140, 3));
	xor->color(fl_rgb_color(62, 62, 66));
	xor->callback(menu_window, win);
	win->show();
	copy->callback(vig_win);
	copy2->callback(vigde_win);
}


void steg_op(Fl_Widget* o, void* v)
{
	close1(v);
	Fl_Window* win = new Fl_Window(1280, 720, "Security Suite");
	ShellExecuteA(NULL, "open", "steg.exe", NULL, NULL, SW_SHOWDEFAULT);
	Fl_Button*  xor = new Fl_Button(1050, 30, 140, 30, "Main Menu");
	xor->labelcolor(fl_rgb_color(255, 140, 3));
	xor->color(fl_rgb_color(62, 62, 66));
	xor->callback(menu_window, win);
	win->show();
}

void vig_win(Fl_Widget* o, void* v) {

	Fl_Window* win = new Fl_Window(1280, 720, "SECURITY SUITE");
	win->color(fl_rgb_color(30, 30, 30));
	win->begin();

	Fl_Button*  copy = new Fl_Button(230, 350, 180, 30, "ENCRYPT");
	copy->color(fl_rgb_color(62, 62, 66));
	copy->labelcolor(fl_rgb_color(255, 140, 3));
	Fl_Button* close = new Fl_Button(580, 600, 70, 30, "&QUIT");
	close->color(fl_rgb_color(62, 62, 66));
	close->labelcolor(fl_rgb_color(255, 140, 3));
	Fl_Input*  inp = new Fl_Input(550, 150, 200, 30, "Enter Text");
	inp->align(FL_ALIGN_TOP | FL_ALIGN_CENTER);
	inp->color(fl_rgb_color(62, 62, 66));
	inp->labelcolor(fl_rgb_color(255, 140, 3));
	Fl_Output* out = new Fl_Output(520, 450, 250, 100, "Output");
	out->align(FL_ALIGN_TOP | FL_ALIGN_CENTER);
	out->color(fl_rgb_color(62, 62, 66));
	out->labelcolor(fl_rgb_color(255, 140, 3));
	Fl_Input*  inp2 = new Fl_Input(550, 250, 200, 30, "Enter Key");
	inp2->align(FL_ALIGN_TOP | FL_ALIGN_CENTER);
	inp2->color(fl_rgb_color(62, 62, 66));
	inp2->labelcolor(fl_rgb_color(255, 140, 3));
	copy->callback(vig_e);
	close->callback(close_cb);
	Fl_Output *out1 = new Fl_Output(780, 70, 0, 0, "Vignere Encryption");
	out1->labelsize(34);
	out1->labelcolor(fl_rgb_color(255, 140, 3));
	out1->labelfont(FL_HELVETICA);
	
	win->show();

}


void vigde_win(Fl_Widget* o, void* v) {

	Fl_Window* win = new Fl_Window(1280, 720, "SECURITY SUITE");
	win->color(fl_rgb_color(30, 30, 30));
	win->begin();
	Fl_Button*  copyd = new Fl_Button(800, 350, 180, 30, "DECRYPT");
	copyd->color(fl_rgb_color(62, 62, 66));
	copyd->labelcolor(fl_rgb_color(255, 140, 3));
	Fl_Button* close = new Fl_Button(580, 600, 70, 30, "&QUIT");
	close->color(fl_rgb_color(62, 62, 66));
	close->labelcolor(fl_rgb_color(255, 140, 3));
	Fl_Input*  inp = new Fl_Input(550, 150, 200, 30, "Enter Text");
	inp->align(FL_ALIGN_TOP | FL_ALIGN_CENTER);
	inp->color(fl_rgb_color(62, 62, 66));
	inp->labelcolor(fl_rgb_color(255, 140, 3));
	Fl_Output* out = new Fl_Output(520, 450, 250, 100, "Output");
	out->align(FL_ALIGN_TOP | FL_ALIGN_CENTER);
	out->color(fl_rgb_color(62, 62, 66));
	out->labelcolor(fl_rgb_color(255, 140, 3));
	Fl_Input*  inp2 = new Fl_Input(550, 250, 200, 30, "Enter Key");
	inp2->align(FL_ALIGN_TOP | FL_ALIGN_CENTER);
	inp2->color(fl_rgb_color(62, 62, 66));
	inp2->labelcolor(fl_rgb_color(255, 140, 3));
	copyd->callback(vig_de);
	close->callback(close_cb);
	Fl_Output *out1 = new Fl_Output(780, 70, 0, 0, "Vignere Encryption");
	out1->labelsize(34);
	out1->labelcolor(fl_rgb_color(255, 140, 3));
	out1->labelfont(FL_HELVETICA);
	
	win->show();

}

void cd_window(Fl_Widget* o, void* v) 
{

	Fl_Window* win = new Fl_Window(1280, 720, "SECURITY SUITE");
	win->color(fl_rgb_color(30, 30, 30));
	win->begin();
	Fl_Button*  copy = new Fl_Button(550, 350, 180, 30, "DECRYPT");
	copy->color(fl_rgb_color(62, 62, 66));
	copy->labelcolor(fl_rgb_color(255, 140, 3));
	Fl_Button* close = new Fl_Button(580, 600, 70, 30, "&QUIT");
	close->color(fl_rgb_color(62, 62, 66));
	close->labelcolor(fl_rgb_color(255, 140, 3));
	Fl_Input*  inp = new Fl_Input(550, 150, 200, 30, "Enter Text");
	inp->align(FL_ALIGN_TOP | FL_ALIGN_CENTER);
	inp->color(fl_rgb_color(62, 62, 66));
	inp->labelcolor(fl_rgb_color(255, 140, 3));
	Fl_Output* out = new Fl_Output(520, 450, 250, 100, "Output");
	out->align(FL_ALIGN_TOP | FL_ALIGN_CENTER);
	out->color(fl_rgb_color(62, 62, 66));
	out->labelcolor(fl_rgb_color(255, 140, 3));
	Fl_Input*  inp2 = new Fl_Input(550, 250, 200, 30, "Enter Key");
	inp2->align(FL_ALIGN_TOP | FL_ALIGN_CENTER);
	inp2->color(fl_rgb_color(62, 62, 66));
	inp2->labelcolor(fl_rgb_color(255, 140, 3));
	copy->callback(copy_cb3);
	close->callback(close_cb);
	Fl_Output *out1 = new Fl_Output(780, 70, 0, 0, "Ceasar Decryption");
	out1->labelsize(34);
	out1->labelcolor(fl_rgb_color(255, 140, 3));
	out1->labelfont(FL_HELVETICA);
	win->show();

}


void copy_cb(Fl_Widget* o, void*)
{
	string name1;
	Fl_Button* b = (Fl_Button*)o;
	Fl_Input* iw = (Fl_Input*)b->parent()->child(2);
	Fl_Output* ow = (Fl_Output*)b->parent()->child(3);
	Fl_Input*  iCC = (Fl_Input*)b->parent()->child(4);
	
	grt.a = iw->value();
	grt.b = iCC->value();
	
	name1 = grt.XOR_encrypt();
	ow->value(name1.c_str());
}


 void copy_cb2(Fl_Widget* o, void* )
 {
	 string name2;
	 Fl_Button* b = (Fl_Button*)o;
	 Fl_Input* iw = (Fl_Input*)b->parent()->child(2);
	 Fl_Output* ow = (Fl_Output*)b->parent()->child(3);
	 Fl_Input*  iCC = (Fl_Input*)b->parent()->child(4);
	 grt.a = iw->value();
	 grt.b  = iCC->value();
	 grt.s = 1;
	 name2 = grt.ceaser_encrypt();
	 ow->value(name2.c_str());
}

 void copy_cb3(Fl_Widget* o, void*)
 {
	 string name2;
	 Fl_Button* b = (Fl_Button*)o;
	 Fl_Input* iw = (Fl_Input*)b->parent()->child(2);
	 Fl_Output* ow = (Fl_Output*)b->parent()->child(3);
	 Fl_Input*  iCC = (Fl_Input*)b->parent()->child(4);
	 gtr.a = iw->value();
	 gtr.b = iCC->value();
	 gtr.s = 1;
	 name2 = gtr.ceaser_decrypt();
	 ow->value(name2.c_str());
 }

 void vig_e(Fl_Widget* o, void*)
 {
	 string name2;
	 Fl_Button* b = (Fl_Button*)o;
	 Fl_Input* iw = (Fl_Input*)b->parent()->child(2);
	 Fl_Output* ow = (Fl_Output*)b->parent()->child(3);
	 Fl_Input*  iCC = (Fl_Input*)b->parent()->child(4);
	 grt.a = iw->value();
	 grt.b = iCC->value();
	 grt.s = 1;
	 name2 = grt.vignere_encrypt();
	 ow->value(name2.c_str());
 }

 void vig_de(Fl_Widget* o, void*)
 {
	 string name2;
	 Fl_Button* b = (Fl_Button*)o;
	 Fl_Input* iw = (Fl_Input*)b->parent()->child(2);
	 Fl_Output* ow = (Fl_Output*)b->parent()->child(3);
	 Fl_Input*  iCC = (Fl_Input*)b->parent()->child(4);
	 gtr.a = iw->value();
	 gtr.b = iCC->value();
	 gtr.s = 1;
	 name2 = gtr.vignere_decrypt();
	 ow->value(name2.c_str());
 }

 void bmp_win(Fl_Widget* o, void*)
 {
	 string a, b;
	 Fl_Window* win = new Fl_Window(1280, 720, "SECURITY SUITE");
	 win->color(fl_rgb_color(30, 30, 30));
	 win->begin();
	 Fl_Button*  stag = new Fl_Button(550, 350, 180, 30, "Encrypt");
	 stag->color(fl_rgb_color(62, 62, 66));
	 stag->labelcolor(fl_rgb_color(255, 140, 3));
	 Fl_Input*  inp = new Fl_Input(550, 150, 200, 30, "Enter Text");
	 inp->align(FL_ALIGN_TOP | FL_ALIGN_CENTER);
	 inp->color(fl_rgb_color(62, 62, 66));
	 inp->labelcolor(fl_rgb_color(255, 140, 3));
	 Fl_Input*  inp2 = new Fl_Input(550, 250, 200, 30, "Enter Key");
	 inp2->align(FL_ALIGN_TOP | FL_ALIGN_CENTER);
	 inp2->color(fl_rgb_color(62, 62, 66));
	 inp2->labelcolor(fl_rgb_color(255, 140, 3));
	 Fl_Output *out1 = new Fl_Output(780, 70, 0, 0, "Steganography Encryption");
	 out1->labelsize(34);
	 out1->labelcolor(fl_rgb_color(255, 140, 3));
	 out1->labelfont(FL_HELVETICA);
	 win->show();
	 stag->callback(steg);
	
 }
 void steg(Fl_Widget* o, void*)
 {
	 string aa,ba;
	 Fl_Button* b = (Fl_Button*)o;
	 Fl_Input* iw = (Fl_Input*)b->parent()->child(1);
	 Fl_Input*  iCC = (Fl_Input*)b->parent()->child(2);

	 aa = iw->value();
	 ba = iCC->value();
	 encode_caller(aa, ba);

 }

 void steg_win(Fl_Widget* o, void*)
 {
	 string a;
	 Fl_Window* win = new Fl_Window(1280, 720, "SECURITY SUITE");
	 win->color(fl_rgb_color(30, 30, 30));
	 win->begin();
	 Fl_Button*  stag = new Fl_Button(550, 350, 180, 30, "Decrypt");
	 stag->color(fl_rgb_color(62, 62, 66));
	 stag->labelcolor(fl_rgb_color(255, 140, 3));
	 Fl_Input*  inp = new Fl_Input(550, 150, 200, 30, "Enter Text");
	 inp->align(FL_ALIGN_TOP | FL_ALIGN_CENTER);
	 inp->color(fl_rgb_color(62, 62, 66));
	 inp->labelcolor(fl_rgb_color(255, 140, 3));
	 Fl_Output* out = new Fl_Output(500, 400, 250, 100, "Output");
	 out->align(FL_ALIGN_TOP | FL_ALIGN_CENTER);
	 out->color(fl_rgb_color(62, 62, 66));
	 out->labelcolor(fl_rgb_color(255, 140, 3));
	 Fl_Output *out1 = new Fl_Output(810, 70, 0, 0, "Steganography Decryption");
	 out1->labelsize(34);
	 out1->labelcolor(fl_rgb_color(255, 140, 3));
	 out1->labelfont(FL_HELVETICA);
	 win->show();
	 stag->callback(steg_de);

 }

 void steg_de(Fl_Widget* o, void*)
 {
	 string a,c;
	 Fl_Button* b = (Fl_Button*)o;
	 Fl_Input* iw = (Fl_Input*)b->parent()->child(1);
	 Fl_Output* ow = (Fl_Output*)b->parent()->child(2);

	 a = iw->value();
	 c= decode_caller(a);
	 ow->value(c.c_str());


 }

 void close1(void * v)
 {
	 Fl_Window* b = (Fl_Window*)v;
	 b->hide();
 }

void close_cb(Fl_Widget* o, void*) {

	exit(0);
}
