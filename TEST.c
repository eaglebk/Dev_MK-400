 //********************************************************************************************************
//***************** ������ ��� �������� ���������� ������������ �� ����� �� ****************
//********************************************************************************************************

	#include	<Head_MK44x.h>

//********************************************************************************************************
// ����������


//********************************************************************************************************
// ���������

//********************************************************************************************************
// ���������

//********************************************************************************************************
// ���


void C_PROJECT1()
	{
	struct PortHeader Port1;
	unsigned char	temp,*ptr_byte;

if (open_port1(&Port1))
		{
		//��������� ���������� �������� �����

		//close_port1();
		set_modbus_bit(0x2000,&temp,0x08);
		goto stop_app;
		}

ptr_byte=Port1.PtrPort;
	*ptr_byte++=0x0A;		//����� Slave
	*ptr_byte++=0x03;		//����� �������
	*ptr_byte++=0x00;		//�����
	*ptr_byte++=0x00;
	*ptr_byte++=0x00;		//����������
	*ptr_byte++=0x10;
	Port1.StatusPort = 0x00;	//ModBus-������
	Port1.CountByte = 0x06; //���������� ���� ���
				// ��������
	Port1.TOPort = 100;		//������� ��� ������� �������
	//������ ����������
	if (begin_transaction_port1(&Port1) == (unsigned short) 0xFF)
		{
		//��������� ���������� �������
		//����������
		//close_port1();
		goto stop_app;
		}
	
while ((temp=get_status_transaction_port1(&Port1)) == (unsigned short) 0x06);
	if (temp == 0xFF)
		{
		//��������� ������ �����

		//close_port1();
		goto stop_app;

		}
stop_app:
	close_port1();


	}
