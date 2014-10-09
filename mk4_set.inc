;Файл содержит данные о общих настойках ресурсов контроллеров МК-4хх

	NOLIST

	ifndef	libdir
	#define	libdir	c:\library\
	endif

On	equ	1
Off	equ	0

New_V	equ	0
Old_V	equ	1

Lo	equ	0
Hi	equ	1

b	equ	BANKED
a	equ	ACCESS

	#define	Zero	Status,Z,a
	#define	Carry	Status,C,a

Ok=H'00'
Err_Adr		equ	H'02'
Err_Data	equ	H'03'
Err_Device	equ	H'04'
Err_Unkfunk	equ	H'01'
Err_Busy	equ	H'06'
Err_NoAck	equ	H'07'
Busy		equ	H'06'
	
Adr_Atr_UsApp		equ	H'10'

	LIST
