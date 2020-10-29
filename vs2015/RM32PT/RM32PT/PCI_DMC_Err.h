#ifndef _PCI_DMC_Err_H
#define _PCI_DMC_Err_H

//Readme_Step_3

//General
#define ERR_SameCardNumber			901		//�d������(�Ҧ��b�d�d������ۦP)
#define ERR_CardType				902		//���b�d���䴩��API
#define ERR_CantFindDLL				903		//��API�P�������DLL�s������(�S��DLL�άODLL�禡�w���S�����禡)
#define ERR_SerchErrorCode			904		//��API�����~�ݨϥ�_DMC_01_get_cardtype_errorcode�Ө��o
#define ERR_NoCardFound				905		//�䤣�즹�b�d
#define ERR_DLLinUse				910		//�X�֪�DLL���Q�ϥΤ�
#define ERR_CantFindAB01			911		//�䤣��A01DLL
#define ERR_CantFindF01				912		//�䤣��F01DLL
#define ERR_CantFindDMCDLL			913		//���A01�BF01DLL

//PCI_DMC_A01 / PCI_DMC_B01  
#define ERR_NoError					0		//�S���D
#define ERR_B02_NO_ERROR			0           // <-- Replace with original error code#0
#define ERR_A02_NO_ERROR			0
#define ERR_FeedRate_Entry_Dec		1		//FeedRate overwrite �i�J��t�q,�����O���A�ܤƳt��,���U�ӫ��O�N�|�s���t���ܤ�
#define ERR_CardNoError				3		//�d�����~�нT�{�d���W��DIP Switch�վ㪺���X
#define ERR_bootmodeErr				5		//�L�k�Ұ�DSP�Ʀ�{��
#define ERR_downloadcode			6		//DSP Program Memory R/W Error
#define ERR_downloadinit			7		//DSP Data Memory R/W Error
#define ERR_PCI_boot_first			8		//�ϥΦ�API�ݥ��Ұ�DSP�Ʀ�{��  I16 PASCAL _DMC_01_pci_initial(U16 CardNo)
#define ERR_FeedRate_updata			9		//FeedRate overwrite ���ȬۦP 
#define ERR_DSP_inside_calcu		10		//DSP memory float error
#define ERR_AxisNoError				11		//�b�ƥعL�j
#define ERR_IPO_First				12		//�ݭn��IPO�Ҧ�
#define ERR_Target_reach			13		//Mode 1 �B���,��Target��F
#define ERR_Servo_on_first			14		//�ݭn��servo on 
#define ERR_MPG_Mode				15		//�b����Ҧ��U�L�k�M����m
#define ERR_PDO_TG					16		//�ϥ�PDO�Ҧ��U���O���Ҳ�,�L�k�^�Ǧ���
#define ERR_ConfigFileOpenError		17		//�إ�Debug Information�ɮ׿��~
#define ERR_Ctrl_value				18		//�ϥα�����O���~
#define ERR_Security_Fifo			19		//�ϥ�Security Fpga write Error
#define ERR_Security_Fifo_busy     	20		//�ϥ�Security Fpga busy
#define ERR_SpeedLimitError			21		//�]�w�t�פj��̤j�t��
#define ERR_Security_Page			22		//�ϥ�Security page �ݭn�p��16
#define ERR_Slave_Security_op		23		//�ϥ�Security slave_operate ���O�L��
#define ERR_channel_no				24		//channel no ���~
#define ERR_start_ring_first		25		//�ϥΦ�API�ݥ��Ұ�DMCNet  I16 PASCAL _DMC_01_start_ring(U16 CardNo, U8 RingNo)
#define ERR_NodeIDError				26		//�L��NodeID
#define ERR_MailBoxErr				27		//���O�L�k�U�F, DSP Busy
#define ERR_SdoData					28		//SDO Data�e�X���L�^��,SDO Data Send Request ,But Without ACK
#define ERR_IOCTL					29		//�@�~�t�εL�k�B�z��IRP
#define ERR_SdoSvonFirst			30		//�ϥ�SDO�ާ@�b����,�ݥ�Servo On
#define ERR_SlotIDError				31		//GA�L��Slot���X
#define ERR_PDO_First				32		//�ϥ�PDO���O�ݥ��N�b�নPDO�Ҧ�
#define ERR_Protocal_build			33		//Protocal,�q��|���إ�
#define ERR_Maching_TimeOut			34		//�Ҳհt��time Out
#define ERR_Maching_NG				35		//�Ҳհt��NG
#define ERR_Group_Num				36		//�]�w�s�ճ̤j�Ȭ�6��
#define ERR_Master_Alarm			37		//�G�ٵo��(�q�T���},Driver Alm)
#define ERR_Alarm_reset				38
#define ERR_Master_Security_Wr		40		//�ϥ�Security Master Write���O�L��
#define ERR_Master_Security_Rd		41		//�ϥ�Security Master Read���O�L��
#define ERR_Master_Security_Pw		42		//�ݭn����J���T��password
#define ERR_NonSupport_CardVer		50		//�ϥΥD���d���������~,�гsô�N�z��,�ʶR���T�D���d
#define ERR_Compare_Source			51		//Ver Type : B Compare Source ��ܿ��~
#define ERR_Compare_Direction		52		//Compare����V���~  dir�ݬ�1��0 1:ccw,0:cw
#define ERR_GetDLLPath				60
#define ERR_GetDLLVersion			61
#define ERR_GA_Port					62
#define ERR_04PISTOP_Timeout		70		//04PI Stop Fifo time out 
#define ERR_ServoSTOP_Timeout		71		//Servo Stop Fifo time out
#define ERR_04PISTOP_status			72		//04PI Stop MC_done not to Error
#define ERR_04PIHoming_err			73		//04PI Home status error
#define ERR_04PISdo_trans			74		//04PI sdo send but get data error
#define ERR_Rm_Port					75
//PCI_DMC_A02 / PCI_DMC_B02  
 
#define ERR_QEP_INDEX				75		// QEP
#define ERR_GPIO_OUTPUT_SIZE		76		// GPIO
#define ERR_IPCMP_INDEX				77		// IPCMP
#define ERR_IPCMP_MPC_DATA_TYPE		78      // It will never happened (internal use)
#define ERR_TPCMP_FIFO_INDEX		79		// TPCMP
#define ERR_TPCMP_QEP_SOURCE		80
#define ERR_TPCMP_TABLE_NO_DATA		81      // Input table empty
#define ERR_TPCMP_TABLE_OUT_OF_RANGE 82		// Input table size is large than TPCMP max. size
#define ERR_TPCMP_TABLE_OVERFLOW	83      // Input table size is large than TPCMP FIFO remainder size
 
#define ERR_EXTIO_RANGE				84		// EXT. IO
#define ERR_EXTIO_LATCH_TYPE		85           // It will never happened (internal use)
 
#define ERR_LATCH_FIFO_EMPTY		86		// Latch FIFO
#define ERR_LATCH_FIFO_INVALID_DATA	87
/////A02
#define ERR_GPIO_PORTNO				100		//GPIO_OUT/GPIO_IN
#define ERR_JOG_AXISNO				101		//JOG_CTNL
#define ERR_A02_MPG_Enable			102		//A02 ����w�P��,�L�k���ЭP��
#define ERR_A02_JOG_Enable			103		//A02 JOG �w�P��,�L�k���ЭP��


#define ERR_RangeError 				112		//�]�w�b�����X���~  ���Υ[,�]���b���P�O�[�bNodeID
#define ERR_MotionBusy 				114		//Motion ���O���|
#define ERR_SpeedError 				116		//�̤j�t�׳]�m��0 
#define ERR_AccTimeError 			117		//�[��t�ɤj��1000��
#define ERR_PitchZero 				124		//Helix pitch�ѼƵ���0,�L�k�B��



#define ERR_BufferFull 				127		//�B�ʫ��OBuffer�v��
#define ERR_PathError				128		//�B�ʫ��O���~
#define	ERR_NoSupportMode   		130		//���䴩�t���ܤ�
#define	ERR_FeedHold_support		132		//Feedhold Stop �Ұ�,�L�k�����s���O 
#define	ERR_SDStop_On				133		//�����t���O, �L�k�����s���O
#define	ERR_VelChange_supper		134		//�Ҧ�1.Feedhold,2.�P�ʫ��O3.��t���O,�L�k����t���ܤƥ\��
#define	ERR_Command_set				135		//�L�k�s�����FeedHold���\��
#define	ERR_sdo_message_choke		136		//Sdo���O�^�Ǧ��~,���ˬd�����u���u�O�_OK
#define	ERR_VelChange_buff_feedhold	137		//Feed Hold  �\�ॲ�����P�� ,�L�k�t���ܤ�
#define	ERR_VelChange_sync_move		138		//�ثe�b�d���b���ݦP�ʫ��O,�L�k�t���ܤ�
#define	ERR_VelChange_SD_On			139		//�ثe�b�d���b�����t���O,�L�k�t���ܤ�
#define	ERR_P_Change_Mode			140		//��b�I���I�Ҧ� �[�t�q,�t�׵���0,�D��b�I���I�Ҧ�
#define	ERR_BufferLength			141		//��Ҧ��b _Path_p_change,_Path_velocity_change_onfly, _Path_Start_Move_2seg�� Buffer Length �ݭn��0
#define	ERR_2segMove_Dist			142		//�Z���ݭn�P�V
#define	ERR_CenterMatch				143		//�g�L�ϦV�B���߭n�@�P
#define	ERR_EndMatch				144		//�g�L�ϦV�B���߭n�@�P
#define	ERR_AngleCalcu				145		//�g�L�p�⨤�׿��~
#define	ERR_RedCalcu				146		//�g�L�b�|���~
#define	ERR_GearSetting				147		//Gear�����l�Τ�����0
#define	ERR_CamTable				148		// Table Setting First Arrary Point Error�]�wtable�����t��table[-1]�S���o�س]�w
#define	ERR_AxesNum					149		// �h�b�]�w�ȥ����n��b�H�W
#define	ERR_SpiralPos				150		// �̲צ�m�|��F���۶��
#define	ERR_SpeedMode_Slave			151		// �b�t�׳s��ɨϥΪ�Slave�b,�L�k����Motion���O
#define	ERR_SpeedMode_SlaveSet		152		// �]�w�b�����������b�b���e�b��
#define	ERR_VelChange_high 			153		// �]�w�ȳt�ק��ܹL�j�άO����sec�L��
#define	ERR_Backlash_step 			154		// accstep+contstep+decstep�ݤp��100
#define	ERR_Backlash_status			155		//�]�w��motion done���ݬ�0�Bbuffer length���ݬ�0	
#define	ERR_DistOver				156		//��JDist�W�LTotalDist

#define		ERR_PVTDataError				160	//PVT motion ��J��Data���~
#define		ERR_PVTModeError				161	//���䴩PVT�Ҧ�
#define		ERR_PVTChannel					162	//channel ���ݤp��䴩PVT���b�� 
#define     ERR_TM_DATA_Axis				163	//Table Motion ��ƶb�ƶW�L�̤j�� 
#define		ERR_TM_CYCLE_DATA				164	//Table Motion �`�����Ƥ�����1�ɡA�_�l�I�M���I���P
#define     ERR_TM_DATA_SIZE				165	//��ƭӼƶW�L�W��
#define     ERR_AMFNum						166	//�o�i�W�L2�D�Τp��1�D
#define		ERR_TM_INACTIVE					167	//Table Motion �Ұʤ�
#define		ERR_TM_BUFFER_FULL				168	//�����s�W��Ʒ|�W�LBuffer�j�p

#define		ERR_ECAM_DATA_NUM				169	//ECAM��ƭӼƿ��~
#define     ERR_ECAM_LENGTH					170	//ECAM�ɵ{(L) <= 0
#define		ERR_ECAM_INDEX					171	//ECAM�_�lIndex���~
#define     ERR_DISENGAGE					172  //ECAM�����ɾ��]�m���~
#define		ERR_VELOCITY_PERCENT			173	//ECAM�t�׫ت�A�ϰ�ʤ�����~	
#define     ERR_CONSTRUCT_MODE				174	//ECAM�t�׫ت�A�Ҧ����(�D 0 or 1 or 2)
#define		ERR_DISENGAGE_PARA				175	//ECAM�����Ѽƥ��]�m
#define		ERR_CUTLENGTH					176	//ECAM�۰ʭ��Ť����]�m���~(�Ӫ��Τӵu)
#define		ERR_REGION						177	//ECAM�۰ʭ��Űϰ�]�m���~(�Ѿl�����ݰϨ��� > S-Curve ����)
#define		ERR_VELOCITY_SCURVE				178	//ECAM�t�׫ت�AS-Curve �ϰ�]�m���~(�W�L����Ϥj�p)
#define		ERR_GEARNUM						179	//ECAM�����ƥؿ��~(���p���I�άO��0)
#define		ERR_KnifeNUm					180	//ECAM�M��ƥ� < 1
#define		ERR_MASTER_SOURCE				181	//ECAM�D�b�ӷ��]�m���~
#define		ERR_HOLDING_AREA				182	//ECAM���ݰϨ��פӤj

#define		ERR_TP_CIRCLE_DATA				190	//3�I����A��ƿ�J���~(�T�I�@�u)	
#define		ERR_AMF_ENABLE					193	//AMF�w�Ұ�	
#define		ERR_AMF_Time					194	//�o�i�ɶ��W�X�d��	
#define		ERR_SPEED_RATIO					195	//Table Motion �w���ܪ��t�צʤ���Ӥj	
#define		ERR_MOTION_DONE					196	//�wMotion Done�A����b�[�J���
#define		ERR_TM_SD_STOP					197	//Table Motion SD STOP ��
#define		ERR_TM_FEEDRATE_OVERWRITE		198  //Table Motion FeedRate Overwrite �� 
#define		ERR_IO_NUMBER					199	//�W�L�̤jIO�ƶq
#define		ERR_PROFILE_MODE_ENABLE			200	//TableMotion �t�׳W���Ҧ��w�Ұ�
#define		ERR_NOT_TM_CYCLE_MODE			201 //���OTableMotion Cycle
#define		ERR_NONE_ANALYSIS				202	//Profile mode �|�����R
#define		ERR_OVER_TABLE_NUM				203	//�W�L��Table�ƥ�


//20160121 PCI_DMC.dll ERR Code 200����600��
#define Compare_Cards_Not_Equal						601		//��ﵲ�G�w�b�d��T(�d���B�ƶq)����
#define Compare_Nodes_Not_Equal						602		//��ﵲ�G�w������T(�ƶq)����
#define Compare_Node_ID_Not_Equal					603		//��ﵲ�G�w������T(����)����
#define Compare_Node_Device_Type_Not_Equal			604		//��ﵲ�G�w�Ҳո�T(�ҲղĤG����)����
#define Compare_Node_Identity_Object_Not_Equal		605		//��ﵲ�G�w�Ҳո�T(�ҲղĤ@����)����
#define Compare_File_Path_NULL						606		//�ɮ׸��|���~
#define Compare_File_Open_Fail						607		//�ɮ׶}�ҥ���(�нT�w���|��J���T)
#define Compare_File_Not_Exist						608		//�ɮפ��s�b

//PCI_DMC_F01

//main
#define ERR_NotCardFound							301		//�L���d���Ω|��Initial
#define ERR_CardInitial								302		//Initial����
#define ERR_MemoryAccess_Failed						303		//�O����Ū�g����
#define ERR_MemoryOutOfRange						304		//�O����ϥζW�LRange
#define	ERR_UartTxIsBusy							305		//Uart Tx is busy
#define	ERR_UartRxError								306		//Uart Rx Ū�����~
#define	ERR_UartRxIsNotReady						307		//Uart Rx �|���ǳƧ���
#define ERR_NotSupportFunc							308		//���䴩��Function
#define ERR_NoNodeFound								309		//�����]�m���~
#define	ERR_APIInputError							310		//API�Ѽƿ�J���~(�W�X���w��)
#define ERR_SDOFailed								311		//SDO�ǰe����
#define ERR_SDOBusy									312		//SDO���L�� / SDO�P�ɦ���ӫ��O�Q�g�J
#define ERR_APITypeErr								313		//���Ҳդ��䴩��API
#define ERR_ScaleFailed								314		//AD�ե�����
#define ERR_F_BufferFull							315		//MailBox_Buffer�w��
#define ERR_ConnectErr								316		//�q�T�s�u���`
#define ERR_MBWordChFailed							317		//MailBox�P�ɦ���ӫ��O�g�J
#define ERR_MailBoxFailed							318		//MailBox�ǰe����
#define ERR_CantResetCard							319		//�L�kResetCard
#define ERR_PDOFailed								320		//PDO���^��
#define ERR_MBCmding								321		//MailBox���b�B�z���O
#define ERR_SVOFF									322		//���ʧ@��Servo On��i����
#define ERR_DriverError								323		//���ʧ@�]DriverErr�L�k����A�Х�����Ralm
#define ERR_ConnReset_Failed						324		//��l�ƭ��m����
#define ERR_F01SlotIDError							325		//���˸m���䴩Slot�ο�J��Slot�s���W�X�d��
#define ERR_UartData_NoMatch						326		//Download CodeŪ��Uart����ƮɡA�^�ǵL�k�ŦX���T��
#define ERR_SVON									327		//���ʧ@��Servo Off��i����
#define ERR_Mpg_Already_On							328		//���b�w�g�P�����BJog��DDA�\��A��l�\��ȮɵL�k�ϥ�
#define ERR_MpgNumber_Over							329		//�����Jog�P��ƶq�w�F�W��(�̤j3��)
#define ERR_Mpg_Data_Failed							330		//�����Jog��ƶǻ�����
#define ERR_DDA_Buffer_Full							331		//DDA Buffer�w��
#define ERR_F_Slave_Security_op						332		//Slave Secutiry�g�J����		
#define ERR_F_Security_Page							333		//Page�W�L�]�m
#define ERR_F_GetDLLPath							334		//�䤣��DLL���|
#define ERR_F_GetDLLVersion							335		//�䤣��DLL�����T��
#define F_Compare_File_Open_Fail					336		//�ɮ׶}�ҥ���(�нT�w���|��J���T)	
#define F_Compare_File_Not_Exist					337		//�ɮפ��s�b
#define F_Compare_Cards_Not_Equal					338		//��ﵲ�G�w�b�d��T(�d���B�ƶq)����
#define F_Compare_File_Path_NULL					339		//�ɮ׸��|���~
#define F_Compare_Node_ID_Not_Equal					340		//��ﵲ�G�w������T(����)����
#define F_Compare_Node_Device_Type_Not_Equal		341		//��ﵲ�G�w�Ҳո�T(�ҲղĤG����)����
#define F_Compare_Node_Identity_Object_Not_Equal	342		//��ﵲ�G�w�Ҳո�T(�ҲղĤ@����)����
#define F_Compare_Nodes_Not_Equal					343		//��ﵲ�G�w������T(�ƶq)����
#define ERR_SecurityNoRet							344		//Security�ǰe���G���^��
#define ERR_SDORetTimeOut							345		//SDO�^�Ǯɶ��L��
#define ERR_Uart_Connect_Fail						346		//Uart�q�T����
#define ERR_CardNum_SetError						347	//�d���]�m���~
#define ERR_Target_Reached							348	//�L���T����
#define ERR_NoF02Found								349	//�䤣��F02�d���Ǹ�
#define ERR_MCHSecurity								350	//F02 Security Error


#define ERR_UseGetError								399		//�t�Ϋ����~, �ݨϥ�_DMC_01_master_alm_codeŪ�����~�X
//sub if main = 99
#define ERR_sub_NoError				0		//���d���ҹ������b�d�S���o�Ϳ��~
#define ERR_sub_CantConnect			1		//DMC�q�T�s���L�k�ͦ�
#define ERR_sub_SDOFailed			2		//SDO�ǰe����
#define ERR_sub_CantReset			3		//�L�k���m�q�T

#endif