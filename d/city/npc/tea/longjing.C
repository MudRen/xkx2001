//Cracked by Roath
// xQin 6/00

inherit ITEM;
inherit F_LIQUID;

void create()
{
        set_name("��������", ({ "longjing","cha" }));
        set_weight(1000);
        if( clonep() )
            set_default_object(__FILE__);
        else {
        set("long",
"����һ����ɫ��������ζ���������������С��ƽ�ѿ���͡���˫Ʒ��֮�ơ�\n");
                set("unit", "��");
                set("value", 25);
                set("max_liquid", 10);
        }
        set("liquid", ([
            "name" : "��������",
            "remaining" : 8,
                "type" : "water"
        ]) );
        set("liquid_type", "water");
        setup();
}
