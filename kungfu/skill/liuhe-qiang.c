//Cracked by Roath
// liuhe-qiang.c ����ǹ
//kane

inherit SKILL;

mapping *action = ({
([	"action" : "$N�����ֱ�������$w��ǰһ�ͣ����������ȥ�����ߣ�����һ�С����ı�������ֱ��$n��$l",
	"force" : 230,
      "parry" : 10,
	"damage" : 30,
	"lvl" : 0,
	"skill_name" : "���ı���",
	"damage_type" : "����"
]),
([	"action" : "$N����$w����һѹ��һ�С��������롹����ʽһ��������ת��$n��$l",
	"force" : 130,
      "parry" : 10,
	"damage" : 40,
	"lvl" : 8,
	"skill_name" : "��������",
	"damage_type" : "����"
]),
([	"action" : "$N˫�����࣬һ�С���è���󡹣���$n�Ĺ��Ʒ������ţ�˳��һǹ����$n��$l",
	"force" : 140,
      "parry" : 15,
	"damage" : 45,
	"lvl" : 16,
	"skill_name" : "��è����",
	"damage_type" : "����"
]),
([	"action" : "$N����һ��$w��һ�С�ʨ��ҡͷ�����������һ��ǹ��������ʵʵ����$n��$l",
	"force" : 220,
      "parry" : 5,
	"damage" : 65,
	"lvl" : 24,
	"skill_name" : "ʨ��ҡͷ",
	"damage_type" : "����"
]),
([	"action" : "$N����$wһ����һ�С�������������$w��ͬ����һ�㷭��Ť����ֱ����$n��$l",
	"force" : 280,
      "parry" : 10,
	"damage" : 50,
	"lvl" : 33,
	"skill_name" : "��������",
	"damage_type" : "����"
]),
([	"action" : "$N����$wһ����ʹ��һ�С�����һ���㡹��$wͦ�ñ�ֱ��Ѹ�����׵ش���$n��$l",
	"force" : 310,
      "parry" : 15,
	"damage" : 70,
	"lvl" : 42,
	"skill_name" : "����һ����",
	"damage_type" : "����"
]),
});


int valid_enable(string usage) { return usage == "halberd" || usage == "pike" || usage == "parry"; }

int valid_learn(object me)
{
	if ((int)me->query("max_neili") < 50)
		return notify_fail("�������������\n");
/*
	if ((int)me->query_skill("hunyuan-yiqi", 1) < 10)
		return notify_fail("��Ļ�Ԫһ�������̫ǳ��\n");
*/
	return 1;
}

string query_skill_name(int level)
{
        int i;
        for(i = sizeof(action)-1; i >= 0; i--)
                if(level >= action[i]["lvl"])
                        return action[i]["skill_name"];
}

mapping query_action(object me, object weapon)
{
	int i, level;
	level   = (int) me->query_skill("liuhe-qiang",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "pike")
		return notify_fail("��ʹ�õ��������ԡ�\n");
	if ((int)me->query("jingli") < 50)
		return notify_fail("��ľ�������������ǹ��\n");
	me->receive_damage("jingli", 25);
	return 1;
}