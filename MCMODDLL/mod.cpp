#include "pch.h"
#include "mod.h"
#include "SymHook.h"
#include<ctype.h>
#include <string>
#include<ctime>
#include<map>
#include <sstream>
#include<vector>
#include "Shell.h"
#include "Cons.h"
#include "Block.h"
#include "Actor.h"
using namespace SymHook;
/**����������������������������������������������������������������������������**
 |              MOD C++�ļ�               |
 **����������������������������������������������������������������������������**
˵����
��cpp�ļ���Ŀ���ǰ���MOD������Ҫ���룬�뽫��Ҫ���ִ���д������ļ��ڣ�
��T����ͷ��ϵ��Hook����ģ����ص�ʱ����ã�ʹ�÷�����ο�MCMrARM��modloader��
��ַ��https://github.com/minecraft-linux/server-modloader/wiki
��ע�⣺ʹ�÷������в�ͬ�����ļ��ĺ��������õ���PDB�������ɵ�C++�������������ַ�����������
���⣬���ļ�������������mod_init��mod_exit���ֱ��ڸ�ģ����ػ��˳�ʱ���á�
��ģ�����ӣ�
THook(void,							// ������������
	MSSYM_XXXXXXXXXXXXXXXXXXXXX,	// ������������Ӧ��C++������λ��SymHook.h��
	__int64 a1, __int64 a2) {		// �������������б�������ڲ���a1��a2��
	std::cout << "Hello world!" << std::endl;
	original(a1, a2);				// ���øú���Hookǰ��ԭʼ����
}
*/
// �˴���ʼ��дMOD����



/***********************************ȫ�ֶ����ȡ & profiling******************************************/
//��ȡȫ��level����











// ���������������Ǳ�Ҫ�ģ������ʹ�ã�Ҳ���Բ�ʹ�á�
void mod_init() {
	// �˴���дģ�����ʱ��Ĳ���
	system("chcp 65001");
	printf("plugin was loaded\n");
}
void mod_exit() {
	// �˴���дģ��ж��ʱ��Ĳ���
}
