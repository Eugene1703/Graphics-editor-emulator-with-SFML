#include "pch.h"
#include "parser.h"
parser my_parser(720, 1280);
TEST(TestCmd, clear_1) 
{
  string str = "0 ff ff ff";
  my_parser.parse(const_cast<char*>(str.c_str()));
  ASSERT_EQ(my_parser.my_answer.comm_id, CLEAR_DISPLAY);
  ASSERT_TRUE(my_parser.my_answer.check);
  ASSERT_EQ(my_parser.my_answer.R, 255);
  ASSERT_EQ(my_parser.my_answer.G, 255);
  ASSERT_EQ(my_parser.my_answer.B, 255);
}
TEST(TestCmd, clear_2)
{
	string str = "0 ffff ff";
	my_parser.parse(const_cast<char*>(str.c_str()));
	ASSERT_EQ(my_parser.my_answer.comm_id, CLEAR_DISPLAY);
	ASSERT_TRUE(my_parser.my_answer.check);
	ASSERT_EQ(my_parser.my_answer.R, 255);
	ASSERT_EQ(my_parser.my_answer.G, 255);
	ASSERT_EQ(my_parser.my_answer.B, 255);
}
TEST(TestCmd, draw_pixel)
{
	string str = "1 50 50 00 00 ff";
	my_parser.parse(const_cast<char*>(str.c_str()));
	ASSERT_EQ(my_parser.my_answer.comm_id, DRAW_PIXEL);
	ASSERT_TRUE(my_parser.my_answer.check);
	ASSERT_EQ(my_parser.my_answer.x0, 50);
	ASSERT_EQ(my_parser.my_answer.y0, 50);
	ASSERT_EQ(my_parser.my_answer.R, 0);
	ASSERT_EQ(my_parser.my_answer.G, 0);
	ASSERT_EQ(my_parser.my_answer.B, 255);
}
TEST(TestCmd, draw_pixel_2)
{
	string str = "1 5050 00 00 ff";
	my_parser.parse(const_cast<char*>(str.c_str()));
	ASSERT_EQ(my_parser.my_answer.comm_id, DRAW_PIXEL);
	ASSERT_TRUE(my_parser.my_answer.check);
	ASSERT_EQ(my_parser.my_answer.x0, 50);
	ASSERT_EQ(my_parser.my_answer.y0, 50);
	ASSERT_EQ(my_parser.my_answer.R, 0);
	ASSERT_EQ(my_parser.my_answer.G, 0);
	ASSERT_EQ(my_parser.my_answer.B, 255);
}
TEST(TestCmd, draw_line)
{
	string str = "2 50 50 50 50 ff 00 ff";
	my_parser.parse(const_cast<char*>(str.c_str()));
	ASSERT_EQ(my_parser.my_answer.comm_id, DRAW_LINE );
	ASSERT_TRUE(my_parser.my_answer.check);
	ASSERT_EQ(my_parser.my_answer.x0, 50);
	ASSERT_EQ(my_parser.my_answer.y0, 50);
	ASSERT_EQ(my_parser.my_answer.x1, 50);
	ASSERT_EQ(my_parser.my_answer.y1, 50);
	ASSERT_EQ(my_parser.my_answer.R, 255);
	ASSERT_EQ(my_parser.my_answer.G, 0);
	ASSERT_EQ(my_parser.my_answer.B, 255);
}
TEST(TestCmd, draw_line_2)
{
	string str = "2 50 50 5 50 50 ff 00 ff";
	my_parser.parse(const_cast<char*>(str.c_str()));
	ASSERT_EQ(my_parser.my_answer.comm_id, DRAW_LINE);
	ASSERT_TRUE(my_parser.my_answer.check);
	ASSERT_EQ(my_parser.my_answer.x0, 50);
	ASSERT_EQ(my_parser.my_answer.y0, 50);
	ASSERT_EQ(my_parser.my_answer.x1, 50);
	ASSERT_EQ(my_parser.my_answer.y1, 50);
	ASSERT_EQ(my_parser.my_answer.R, 255);
	ASSERT_EQ(my_parser.my_answer.G, 0);
	ASSERT_EQ(my_parser.my_answer.B, 255);
}
TEST(TestCmd, draw_rect)
{
	string str = "3 50 50 50 50 00 00 00";
	my_parser.parse(const_cast<char*>(str.c_str()));
	ASSERT_EQ(my_parser.my_answer.comm_id, DRAW_RECTANGLE);
	ASSERT_TRUE(my_parser.my_answer.check);
	ASSERT_EQ(my_parser.my_answer.x0, 50);
	ASSERT_EQ(my_parser.my_answer.y0, 50);
	ASSERT_EQ(my_parser.my_answer.h, 50);
	ASSERT_EQ(my_parser.my_answer.w, 50);
	ASSERT_EQ(my_parser.my_answer.R, 0);
	ASSERT_EQ(my_parser.my_answer.G, 0);
	ASSERT_EQ(my_parser.my_answer.B, 0);
}
TEST(TestCmd, draw_rect_2)
{
	string str = "3 50 50 50 00 00 00";
	my_parser.parse(const_cast<char*>(str.c_str()));
	ASSERT_EQ(my_parser.my_answer.comm_id, DRAW_RECTANGLE);
	ASSERT_TRUE(my_parser.my_answer.check);
	ASSERT_EQ(my_parser.my_answer.x0, 50);
	ASSERT_EQ(my_parser.my_answer.y0, 50);
	ASSERT_EQ(my_parser.my_answer.h, 50);
	ASSERT_EQ(my_parser.my_answer.w, 50);
	ASSERT_EQ(my_parser.my_answer.R, 0);
	ASSERT_EQ(my_parser.my_answer.G, 0);
	ASSERT_EQ(my_parser.my_answer.B, 0);
}
TEST(TestCmd, draw_fill)
{
	string str = "4 50 50 50 50 00 00 00";
	my_parser.parse(const_cast<char*>(str.c_str()));
	ASSERT_EQ(my_parser.my_answer.comm_id, DRAW_FILL_RECTANGLE);
	ASSERT_TRUE(my_parser.my_answer.check);
	ASSERT_EQ(my_parser.my_answer.x0, 50);
	ASSERT_EQ(my_parser.my_answer.y0, 50);
	ASSERT_EQ(my_parser.my_answer.h, 50);
	ASSERT_EQ(my_parser.my_answer.w, 50);
	ASSERT_EQ(my_parser.my_answer.R, 0);
	ASSERT_EQ(my_parser.my_answer.G, 0);
	ASSERT_EQ(my_parser.my_answer.B, 0);
}
TEST(TestCmd, draw_fill_2)
{
	string str = "4 50 50 50 50 00 00 00";
	my_parser.parse(const_cast<char*>(str.c_str()));
	ASSERT_EQ(my_parser.my_answer.comm_id, DRAW_FILL_RECTANGLE);
	ASSERT_TRUE(my_parser.my_answer.check);
	ASSERT_EQ(my_parser.my_answer.x0, 50);
	ASSERT_EQ(my_parser.my_answer.y0, 50);
	ASSERT_EQ(my_parser.my_answer.h, 50);
	ASSERT_EQ(my_parser.my_answer.w, 50);
	ASSERT_EQ(my_parser.my_answer.R, 0);
	ASSERT_EQ(my_parser.my_answer.G, 0);
	ASSERT_EQ(my_parser.my_answer.B, 0);
}
TEST(TestCmd, draw_ellipse)
{
	string str = "5 50 50 20 30 00 00 00";
	my_parser.parse(const_cast<char*>(str.c_str()));
	ASSERT_EQ(my_parser.my_answer.comm_id, DRAW_ELLIPSE);
	ASSERT_TRUE(my_parser.my_answer.check);
	ASSERT_EQ(my_parser.my_answer.x0, 50);
	ASSERT_EQ(my_parser.my_answer.y0, 50);
	ASSERT_EQ(my_parser.my_answer.radius_x, 20);
	ASSERT_EQ(my_parser.my_answer.radius_y, 30);
	ASSERT_EQ(my_parser.my_answer.R, 0);
	ASSERT_EQ(my_parser.my_answer.G, 0);
	ASSERT_EQ(my_parser.my_answer.B, 0);
}
TEST(TestCmd, draw_ellipse_2)
{
	string str = "5 50 50 20 30 fff 00 00";
	my_parser.parse(const_cast<char*>(str.c_str()));
	ASSERT_EQ(my_parser.my_answer.comm_id, DRAW_ELLIPSE);
	ASSERT_TRUE(my_parser.my_answer.check);
	ASSERT_EQ(my_parser.my_answer.x0, 50);
	ASSERT_EQ(my_parser.my_answer.y0, 50);
	ASSERT_EQ(my_parser.my_answer.radius_x, 20);
	ASSERT_EQ(my_parser.my_answer.radius_y, 30);
	ASSERT_EQ(my_parser.my_answer.R, 0);
	ASSERT_EQ(my_parser.my_answer.G, 0);
	ASSERT_EQ(my_parser.my_answer.B, 0);
}
TEST(TestCmd, draw_fill_ellipse)
{
	string str = "6 50 50 20 30 ff 00 00";
	my_parser.parse(const_cast<char*>(str.c_str()));
	ASSERT_EQ(my_parser.my_answer.comm_id, DRAW_FILL_ELLIPSE);
	ASSERT_TRUE(my_parser.my_answer.check);
	ASSERT_EQ(my_parser.my_answer.x0, 50);
	ASSERT_EQ(my_parser.my_answer.y0, 50);
	ASSERT_EQ(my_parser.my_answer.radius_x, 20);
	ASSERT_EQ(my_parser.my_answer.radius_y, 30);
	ASSERT_EQ(my_parser.my_answer.R, 255);
	ASSERT_EQ(my_parser.my_answer.G, 0);
	ASSERT_EQ(my_parser.my_answer.B, 0);
}
TEST(TestCmd, draw_fill_ellipse_2)
{
	string str = "6 50 50 20 30 ff 00 00";
	my_parser.parse(const_cast<char*>(str.c_str()));
	ASSERT_EQ(my_parser.my_answer.comm_id, DRAW_FILL_ELLIPSE);
	ASSERT_TRUE(my_parser.my_answer.check);
	ASSERT_EQ(my_parser.my_answer.x0, 50);
	ASSERT_EQ(my_parser.my_answer.y0, 50);
	ASSERT_EQ(my_parser.my_answer.radius_x, 20);
	ASSERT_EQ(my_parser.my_answer.radius_y, 30);
	ASSERT_EQ(my_parser.my_answer.R, 0);
	ASSERT_EQ(my_parser.my_answer.G, 0);
	ASSERT_EQ(my_parser.my_answer.B, 0);
}
TEST(TestCmd, draw_circle)
{
	string str = "7 50 50 20 00 ff 00";
	my_parser.parse(const_cast<char*>(str.c_str()));
	ASSERT_EQ(my_parser.my_answer.comm_id, DRAW_CIRCLE);
	ASSERT_TRUE(my_parser.my_answer.check);
	ASSERT_EQ(my_parser.my_answer.x0, 50);
	ASSERT_EQ(my_parser.my_answer.y0, 50);
	ASSERT_EQ(my_parser.my_answer.radius, 20);
	ASSERT_EQ(my_parser.my_answer.R, 0);
	ASSERT_EQ(my_parser.my_answer.G, 255);
	ASSERT_EQ(my_parser.my_answer.B, 0);
}
TEST(TestCmd, draw_circle_2)
{
	string str = "750 50 20 00 ff 00";
	my_parser.parse(const_cast<char*>(str.c_str()));
	ASSERT_EQ(my_parser.my_answer.comm_id, DRAW_CIRCLE);
	ASSERT_TRUE(my_parser.my_answer.check);
	ASSERT_EQ(my_parser.my_answer.x0, 50);
	ASSERT_EQ(my_parser.my_answer.y0, 50);
	ASSERT_EQ(my_parser.my_answer.radius, 20);
	ASSERT_EQ(my_parser.my_answer.R, 0);
	ASSERT_EQ(my_parser.my_answer.G, 255);
	ASSERT_EQ(my_parser.my_answer.B, 0);
}
TEST(TestCmd, draw_fill_circle)
{
	string str = "8 50 50 20 00 ff 00";
	my_parser.parse(const_cast<char*>(str.c_str()));
	ASSERT_EQ(my_parser.my_answer.comm_id,DRAW_FILL_CIRCLE);
	ASSERT_TRUE(my_parser.my_answer.check);
	ASSERT_EQ(my_parser.my_answer.x0, 50);
	ASSERT_EQ(my_parser.my_answer.y0, 50);
	ASSERT_EQ(my_parser.my_answer.radius, 20);
	ASSERT_EQ(my_parser.my_answer.R, 0);
	ASSERT_EQ(my_parser.my_answer.G, 255);
	ASSERT_EQ(my_parser.my_answer.B, 0);
}
TEST(TestCmd, draw_fill_circle_2)
{
	string str = "8 50 50 2000 ff 00";
	my_parser.parse(const_cast<char*>(str.c_str()));
	ASSERT_EQ(my_parser.my_answer.comm_id, DRAW_FILL_CIRCLE);
	ASSERT_TRUE(my_parser.my_answer.check);
	ASSERT_EQ(my_parser.my_answer.x0, 50);
	ASSERT_EQ(my_parser.my_answer.y0, 50);
	ASSERT_EQ(my_parser.my_answer.radius, 20);
	ASSERT_EQ(my_parser.my_answer.R, 0);
	ASSERT_EQ(my_parser.my_answer.G, 255);
	ASSERT_EQ(my_parser.my_answer.B, 0);
}
TEST(TestCmd, draw_round_rect)
{
	string str = "9 50 50 50 50 10 00 ff 00";
	my_parser.parse(const_cast<char*>(str.c_str()));
	ASSERT_EQ(my_parser.my_answer.comm_id, DRAW_ROUNDED_RECTANGLE);
	ASSERT_TRUE(my_parser.my_answer.check);
	ASSERT_EQ(my_parser.my_answer.x0, 50);
	ASSERT_EQ(my_parser.my_answer.y0, 50);
	ASSERT_EQ(my_parser.my_answer.h, 50);
	ASSERT_EQ(my_parser.my_answer.w, 50);
	ASSERT_EQ(my_parser.my_answer.radius, 10);
	ASSERT_EQ(my_parser.my_answer.R, 0);
	ASSERT_EQ(my_parser.my_answer.G, 255);
	ASSERT_EQ(my_parser.my_answer.B, 0);
}
TEST(TestCmd, draw_round_rect_2)
{
	string str = "A 50 5050 50 10 00 ff 00";
	my_parser.parse(const_cast<char*>(str.c_str()));
	ASSERT_EQ(my_parser.my_answer.comm_id, DRAW_ROUNDED_RECTANGLE);
	ASSERT_TRUE(my_parser.my_answer.check);
	ASSERT_EQ(my_parser.my_answer.x0, 50);
	ASSERT_EQ(my_parser.my_answer.y0, 50);
	ASSERT_EQ(my_parser.my_answer.h, 50);
	ASSERT_EQ(my_parser.my_answer.w, 50);
	ASSERT_EQ(my_parser.my_answer.radius, 10);
	ASSERT_EQ(my_parser.my_answer.R, 0);
	ASSERT_EQ(my_parser.my_answer.G, 255);
	ASSERT_EQ(my_parser.my_answer.B, 0);
}
TEST(TestCmd, draw_fill_round_rect)
{
	string str = "A 50 50 50 50 10 00 ff 00";
	my_parser.parse(const_cast<char*>(str.c_str()));
	ASSERT_EQ(my_parser.my_answer.comm_id, DRAW_FILL_ROUNDED_RECTANGLE);
	ASSERT_TRUE(my_parser.my_answer.check);
	ASSERT_EQ(my_parser.my_answer.x0, 50);
	ASSERT_EQ(my_parser.my_answer.y0, 50);
	ASSERT_EQ(my_parser.my_answer.h, 50);
	ASSERT_EQ(my_parser.my_answer.w, 50);
	ASSERT_EQ(my_parser.my_answer.radius, 10);
	ASSERT_EQ(my_parser.my_answer.R, 0);
	ASSERT_EQ(my_parser.my_answer.G, 255);
	ASSERT_EQ(my_parser.my_answer.B, 0);
}
TEST(TestCmd, draw_fill_round_rect_2)
{
	string str = "A50 50 50 50 10 00 ff 00";
	my_parser.parse(const_cast<char*>(str.c_str()));
	ASSERT_EQ(my_parser.my_answer.comm_id, DRAW_FILL_ROUNDED_RECTANGLE);
	ASSERT_TRUE(my_parser.my_answer.check);
	ASSERT_EQ(my_parser.my_answer.x0, 50);
	ASSERT_EQ(my_parser.my_answer.y0, 50);
	ASSERT_EQ(my_parser.my_answer.h, 50);
	ASSERT_EQ(my_parser.my_answer.w, 50);
	ASSERT_EQ(my_parser.my_answer.radius, 10);
	ASSERT_EQ(my_parser.my_answer.R, 0);
	ASSERT_EQ(my_parser.my_answer.G, 255);
	ASSERT_EQ(my_parser.my_answer.B, 0);
}
TEST(TestCmd, draw_text)
{
	string str = "B 100 100 ff 00 ff 16 5 hello";
	my_parser.parse(const_cast<char*>(str.c_str()));
	ASSERT_EQ(my_parser.my_answer.comm_id, DRAW_TEXT);
	ASSERT_TRUE(my_parser.my_answer.check);
	ASSERT_EQ(my_parser.my_answer.x0, 100);
	ASSERT_EQ(my_parser.my_answer.y0, 100);
	ASSERT_EQ(my_parser.my_answer.R, 255);
	ASSERT_EQ(my_parser.my_answer.G, 0);
	ASSERT_EQ(my_parser.my_answer.B, 255);
	ASSERT_EQ(my_parser.my_answer.font, 16);
	ASSERT_EQ(my_parser.my_answer.length, 5);
	ASSERT_EQ(my_parser.my_answer.text, " hello");
}
TEST(TestCmd, draw_text_2)
{
	string str = "B 100 100 ff 00 ff 16 5hello";
	my_parser.parse(const_cast<char*>(str.c_str()));
	ASSERT_EQ(my_parser.my_answer.comm_id, DRAW_TEXT);
	ASSERT_TRUE(my_parser.my_answer.check);
	ASSERT_EQ(my_parser.my_answer.x0, 100);
	ASSERT_EQ(my_parser.my_answer.y0, 100);
	ASSERT_EQ(my_parser.my_answer.R, 255);
	ASSERT_EQ(my_parser.my_answer.G, 0);
	ASSERT_EQ(my_parser.my_answer.B, 255);
	ASSERT_EQ(my_parser.my_answer.font, 16);
	ASSERT_EQ(my_parser.my_answer.length, 5);
	ASSERT_EQ(my_parser.my_answer.text, " hello");
}
TEST(TestCmd, draw_image)
{
	string str = "C 100 100 200 200";
	my_parser.parse(const_cast<char*>(str.c_str()));
	ASSERT_EQ(my_parser.my_answer.comm_id, DRAW_IMAGE);
	ASSERT_TRUE(my_parser.my_answer.check);
	ASSERT_EQ(my_parser.my_answer.x0, 100);
	ASSERT_EQ(my_parser.my_answer.y0, 100);
	ASSERT_EQ(my_parser.my_answer.h, 200);
	ASSERT_EQ(my_parser.my_answer.w, 200);
}
TEST(TestCmd, draw_image_2)
{
	string str = "C 100 100 200200";
	my_parser.parse(const_cast<char*>(str.c_str()));
	ASSERT_EQ(my_parser.my_answer.comm_id, DRAW_IMAGE);
	ASSERT_TRUE(my_parser.my_answer.check);
	ASSERT_EQ(my_parser.my_answer.x0, 100);
	ASSERT_EQ(my_parser.my_answer.y0, 100);
	ASSERT_EQ(my_parser.my_answer.h, 200);
	ASSERT_EQ(my_parser.my_answer.w, 200);
}
TEST(TestCmd, set_orient)
{
	string str = "D 2";
	my_parser.parse(const_cast<char*>(str.c_str()));
	ASSERT_EQ(my_parser.my_answer.comm_id, SET_ORIENTATION);
	ASSERT_TRUE(my_parser.my_answer.check);
	ASSERT_EQ(my_parser.my_answer.orientation, 2);
}
TEST(TestCmd, set_orient_2)
{
	string str = "D 200";
	my_parser.parse(const_cast<char*>(str.c_str()));
	ASSERT_EQ(my_parser.my_answer.comm_id, SET_ORIENTATION);
	ASSERT_TRUE(my_parser.my_answer.check);
	ASSERT_EQ(my_parser.my_answer.orientation, 2);
}
TEST(TestCmd, Get_Width)
{
	string str = "E";
	my_parser.parse(const_cast<char*>(str.c_str()));
	ASSERT_EQ(my_parser.my_answer.comm_id, GET_WIDTH);
	ASSERT_EQ(my_parser.my_answer.width, 1280);
	ASSERT_TRUE(my_parser.my_answer.check);
}
TEST(TestCmd, Get_Width_2)
{
	string str = "Eee";
	my_parser.parse(const_cast<char*>(str.c_str()));
	ASSERT_EQ(my_parser.my_answer.comm_id, GET_WIDTH);
	ASSERT_EQ(my_parser.my_answer.width, 1280);
	ASSERT_TRUE(my_parser.my_answer.check);
}
TEST(TestCmd, Get_Height)
{
	string str = "F";
	my_parser.parse(const_cast<char*>(str.c_str()));
	ASSERT_EQ(my_parser.my_answer.comm_id, GET_HEIGHT);
	ASSERT_EQ(my_parser.my_answer.height, 720);
}
TEST(TestCmd, Get_Height_2)
{
	string str = "Fffff";
	my_parser.parse(const_cast<char*>(str.c_str()));
	ASSERT_EQ(my_parser.my_answer.comm_id, GET_HEIGHT);
	ASSERT_EQ(my_parser.my_answer.height, 720);
}
int main(int argc, char** argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}