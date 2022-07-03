/*
 \file		coordinate.c
 \author	MOHAMMAD HABIB SHAH ERSHAD BIN MOHD AZRUL SHAZRIL
 \date		2/7/2022
 \brief		Robot will move based on coordinate input
*/
#inc

#include <ev3.h>
#include <string.h>
#include <stdio.h>

void init(){

	InitEV3(); //Declare library function
	setAllSensorMode(GYRO_ANG,NO_SEN,NO_SEN,NO_SEN); //set what input corresponds to what sensor
}


void turn(int angle){
	angle = 2.55 * angle;

		if(angle > 0 ){
			RotateMotorEx(OUT_BC, 50, angle, 200 , true, true);
		}
		else if(angle <= 0 ){
				RotateMotorEx(OUT_BC, -50, angle, 200 , true, true);
			}
	Off(OUT_BC); //Turns of the motors
}

void gostraight(int distance)
{
	if(distance >= 0){
	int md1 = (distance/17.28)*360;
	RotateMotor(OUT_BC, 100, md1);
	Off(OUT_BC);}
	else if (distance < 0)
	{
		distance = -distance;
		int md2 = (distance/17.28)*360;
			RotateMotor(OUT_BC, -100, md2);
			Off(OUT_BC);
	}
}


void followline(int xx, int yy)
{
	if(xx == 1 && yy == 0)
	{
		turn(90);
		gostraight(30);
	}
	else if(xx == 2 && yy == 0)
	{
		turn(90);
		gostraight(60);
	}
	else if(xx == 3 && yy == 0)
		{
		turn(90);
		gostraight(90);
		}
	else if(xx == 4 && yy == 0)
		{
		turn(90);
		gostraight(120);
		}
	else if(xx == 0 && yy == 1)
		{
		gostraight(30);
		}
	else if(xx == 1 && yy == 1)
		{
		gostraight(30);
		turn(90);
		gostraight(30);
		}
	else if(xx == 2 && yy == 1)
		{
		gostraight(30);
		turn(90);
		gostraight(60);
		}
	else if(xx == 3 && yy == 1)
		{
		gostraight(30);
		turn(90);
		gostraight(90);
		}
	else if(xx == 4 && yy == 1)
		{
		gostraight(30);
		turn(90);
		gostraight(120);
		}
	else if(xx == 0 && yy == 2)
		{
		gostraight(60);
		}
	else if(xx == 1 && yy == 2)
		{
		gostraight(60);
		turn(90);
		gostraight(30);
		}
	else if(xx == 2 && yy == 2)
		{
		gostraight(60);
		turn(90);
		gostraight(60);
		}
	else if(xx == 3 && yy == 2)
		{
		gostraight(60);
		turn(90);
		gostraight(90);
		}
	else if(xx == 4 && yy == 2)
		{
		gostraight(60);
		turn(90);
		gostraight(120);
		}
	else if(xx == 0 && yy == 3)
		{
		gostraight(90);
		}
	else if(xx == 1 && yy == 3)
		{
		gostraight(90);
		turn(90);
		gostraight(30);
		}
	else if(xx == 2 && yy == 3)
		{
		gostraight(90);
		turn(90);
		gostraight(60);
		}
	else if(xx == 3 && yy == 3)
		{
		gostraight(90);
		turn(90);
		gostraight(90);
		}
	else if(xx == 4 && yy == 3)
		{
		gostraight(90);
		turn(90);
		gostraight(120);
		}
}

void phytogoras(int xxx, int yyy)
{
	if(xxx == 1 && yyy == 0)
		{
		turn(90);
		gostraight(30);
		}
		else if(xxx == 2 && yyy == 0)
		{
			turn(90);
			gostraight(60);
		}
		else if(xxx == 3 && yyy == 0)
			{
			turn(90);
			gostraight(90);
			}
		else if(xxx == 4 && yyy == 0)
			{
			turn(90);
			gostraight(120);
			}
		else if(xxx == 0 && yyy == 1)
			{
			gostraight(30);
			}
		else if(xxx == 1 && yyy == 1)
			{
			turn(45);
			gostraight(42);
			}
		else if(xxx == 2 && yyy == 1)
			{
			turn(63);
			gostraight(67);
			}
		else if(xxx == 3 && yyy == 1)
			{
			turn(71);
			gostraight(95);
			}
		else if(xxx == 4 && yyy == 1)
			{
			turn(75);
			gostraight(124);
			}
		else if(xxx == 0 && yyy == 2)
			{
			gostraight(60);
			}
		else if(xxx == 1 && yyy == 2)
			{
			turn(26);
			gostraight(67);
			}
		else if(xxx == 2 && yyy == 2)
			{
				turn(45);
				gostraight(85);
			}
		else if(xxx == 3 && yyy == 2)
			{
			turn(56);
			gostraight(108);
			}
		else if(xxx == 4 && yyy == 2)
			{
			turn(63);
			gostraight(134);
			}
		else if(xxx == 0 && yyy == 3)
			{
			gostraight(90);
			}
		else if(xxx == 1 && yyy == 3)
			{
			turn(18);
			gostraight(95);
			}
		else if(xxx == 2 && yyy == 3)
			{
			turn(33);
			gostraight(108);
			}
		else if(xxx == 3 && yyy == 3)
			{
			turn(45);
			gostraight(127);
			}
		else if(xxx == 4 && yyy == 3)
			{
			turn(53);
			gostraight(150);
			}
}

int main(void)
{
	init();

	int x=0;
	int number=0;
	int y=0;
	char x1[20],y1[20];



while(1){


	TermPrintln("RIGHT FOLLOW LINE");
	TermPrintln("LEFT FOR PHYTOGORAS");
	TermPrintln("EXIT FOR EXIT");

	if(ButtonIsUp(BTNRIGHT) == 0)
	{
		LcdClean();
		while(true)
		{
			sprintf(x1, "%d", x);
			sprintf(y1, "%d", y);

			TermPrintln("Position x    : %s",x1);
			TermPrintln("Position y    : %s",y1);

			if(ButtonIsUp(BTNUP) == 0)
				{
					if(number == 0)
					{
						x++;
								while(ButtonIsUp(BTNUP) == 0)
								{
									x = x;
								}
					}
					else if(number == 1)
					{
						y++;
								while(ButtonIsUp(BTNUP) == 0)
								{
									y=y;
								}
					}

				}
			else if(ButtonIsUp(BTNDOWN) == 0)
					{
					if(number == 0)
							{
								x--;
										while(ButtonIsUp(BTNDOWN) == 0)
										{
											x = x;
										}
							}
							else if(number == 1)
							{
								y--;
										while(ButtonIsUp(BTNDOWN) == 0)
										{
											y=y;
										}
							}
					}
			if(ButtonIsUp(BTNCENTER) == 0)
				{
					followline(x,y);
					x=0;
					number=0;
					y=0;
					break;
				}

			if(ButtonIsUp(BTNRIGHT) == 0)
				{
					number++;
					if(number >1)
					{
						number = 1;
					}
					while(ButtonIsUp(BTNRIGHT) == 0)
					{
						number = number;
					}
				}
				else if(ButtonIsUp(BTNLEFT) == 0)
				{
					number--;
					if(number < 0)
							{
								number = 0;
							}
					while(ButtonIsUp(BTNLEFT) == 0)
					{
						number = number;
					}
				}
			LcdClean();
		}
	}

	else if(ButtonIsUp(BTNLEFT) == 0)
	{
		LcdClean();
				while(true)
				{
					sprintf(x1, "%d", x);
					sprintf(y1, "%d", y);

					TermPrintln("Position x    : %s",x1);
					TermPrintln("Position y    : %s",y1);

					if(ButtonIsUp(BTNUP) == 0)
						{
							if(number == 0)
							{
								x++;
										while(ButtonIsUp(BTNUP) == 0)
										{
											x = x;
										}
							}
							else if(number == 1)
							{
								y++;
										while(ButtonIsUp(BTNUP) == 0)
										{
											y=y;
										}
							}

						}
					else if(ButtonIsUp(BTNDOWN) == 0)
							{
							if(number == 0)
									{
										x--;
												while(ButtonIsUp(BTNDOWN) == 0)
												{
													x = x;
												}
									}
									else if(number == 1)
									{
										y--;
												while(ButtonIsUp(BTNDOWN) == 0)
												{
													y=y;
												}
									}
							}
					if(ButtonIsUp(BTNCENTER) == 0)
						{
							phytogoras(x,y);
							x=0;
							number=0;
							y=0;
							break;
						}

					if(ButtonIsUp(BTNRIGHT) == 0)
						{
							number++;
							if(number >1)
							{
								number = 1;
							}
							while(ButtonIsUp(BTNRIGHT) == 0)
							{
								number = number;
							}
						}
						else if(ButtonIsUp(BTNLEFT) == 0)
						{
							number--;
							if(number < 0)
									{
										number = 0;
									}
							while(ButtonIsUp(BTNLEFT) == 0)
							{
								number = number;
							}
						}
					LcdClean();
				}

	}

	else if(ButtonIsUp(BTNEXIT) == 0)
	{
		break;
	}
	LcdClean();
}
	return 0;
}





