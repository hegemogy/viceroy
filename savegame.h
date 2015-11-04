#include <stdint.h>

static const char *profession_list[] = {
	"Expert farmer         ", //0x00
	"Master sugar planter  ", //0x01
	"Master tobacco planter", //0x02
	"Master cotton planter ", //0x03
	"Expert fur trapper    ", //0x04
	"Expert lumberjack     ", //0x05
	"Expert ore miner      ", //0x06
	"Expert silver miner   ", //0x07
	"Expert fisherman      ", //0x08
	"Master distiller      ", //0x09
	"Master tobacconist    ", //0x0a
	"Master weaver         ", //0x0b
	"Master fur trader     ", //0x0c
	"Master carpenter      ", //0x0d
	"Master blacksmith     ", //0x0e
	"Master gunsmith       ", //0x0f
	"Firebrand preacher    ", //0x10
	"Elder statesman       ", //0x11
	"prof_unk12            ", //0x12
	"prof_unk13            ", //0x13
	"Hardy pioneer         ", //0x14
	"Veteran soldier       ", //0x15
	"Seasoned scout        ", //0x16
	"prof_unk17            ", //0x17
	"Jesuit missionary     ", //0x18
	"Indentured servant    ", //0x19
	"Petty criminal        ", //0x1a
	"prof_unk1b            ", //0x1b
	"Free colonist         ", //0x1c
};

static const char *nation_list[] = {
	"England    ", //0x00
	"France     ", //0x01
	"Spain      ", //0x02
	"Netherlands", //0x03
	"Inca       ", //0x04
	"Aztec      ", //0x05
	"Awarak     ", //0x06
	"Iroqui     ", //0x07
	"Cherokee   ", //0x08
	"Apache     ", //0x09
	"Sioux      ", //0x0a
	"Tupi       ", //0x0b
};

static const char *cargo_list[] = {
	"Food",
	"Sugar",
	"Tobacco",
	"Cotton",
	"Furs",
	"Lumber",
	"Ore",
	"Silver",
	"Horses",
	"Rum",
	"Cigars",
	"Cloth",
	"Coats",
	"Trade goods",
	"Tools",
	"Muskets",
};

static const char *founding_father_list[] = {
	"Adam Smith",
	"Jakob Fugger",
	"Peter Minuit",
	"Peter Stuyvesant",
	"Jan de Witt",
	"Ferdinand Magellan",
	"Francisco de Coronado",
	"Hernando de Soto",
	"Henry Hudson",
	"Sieur de La Salle",
	"Hernan Cortes",
	"George Washington",
	"Paul Revere",
	"Francis Drake",
	"John Paul Jones",
	"Thomas Jefferson",
	"Pocahontas",
	"Thomas Paine",
	"founding18",
	"Benjamin Franklin",
	"William Brewster",
	"William Penn",
	"Jean de Brebeuf",
	"Juan de Sepulveda",
	"Bartolme de las Casas",
};

static const char *difficulty_list[] = {
	"Discoverer  ",
	"Explorer    ",
	"Conquistador",
	"Governor    ",
	"Viceroy     ",
};

struct savegame {

	struct head {
		char sig_colonize[9];
		uint8_t unk0[ 7];
		struct tut1 {
			uint8_t nr13  : 1;
			uint8_t nr14  : 1;
			uint8_t unk3  : 1;
			uint8_t nr15  : 1;
			uint8_t nr16  : 1;
			uint8_t nr17  : 1;
			uint8_t unk7  : 1;
			uint8_t nr19  : 1;
		} __attribute__ ((packed)) tut1;

		uint8_t unk1[3];

		struct colony_report_options {
			uint16_t labels_on_cargo_and_terrain : 1;
			uint16_t labels_on_buildings : 1;
			uint16_t report_new_cargos_available : 1;
			uint16_t report_inefficient_government : 1;
			uint16_t report_tools_needed_for_production : 1;
			uint16_t report_raw_materials_shortages : 1;
			uint16_t report_food_shortages : 1;
			uint16_t report_when_colonists_trained : 1;
			uint16_t report_sons_of_liberty_membership : 1;
			uint16_t report_rebel_majorities : 1;
			uint16_t unused : 6;
		} __attribute__ ((packed)) colony_report_options;

		struct tut2 {
			uint8_t howtowin : 1;
			uint8_t unk2 : 1;
			uint8_t unk3 : 1;
			uint8_t unk4 : 1;
			uint8_t unk5 : 1;
			uint8_t unk6 : 1;
			uint8_t nr3  : 1;
			uint8_t nr4  : 1;
		} __attribute__ ((packed)) tut2;

		struct tut3     {
			uint8_t nr5   : 1;
			uint8_t nr6   : 1;
			uint8_t nr7   : 1;
			uint8_t nr8   : 1;
			uint8_t nr9   : 1;
			uint8_t nr10  : 1;
			uint8_t nr11  : 1;
			uint8_t nr12  : 1;
		} __attribute__ ((packed)) tut3;

		uint8_t  unk2[2];
		uint16_t year;
		uint16_t autumn; //boolean, true if autumn
		uint16_t turn;
		uint8_t  unk3[2];
		uint16_t active_unit;
		uint8_t  unk3a[6];
		uint16_t tribe_count;
		uint16_t unit_count;
		uint16_t colony_count;
		uint8_t  unk4[6];
		uint8_t difficulty; enum { DISCOVERER = 0, EXPLORER = 1, CONQUISTADOR = 2, GOVERNOR = 3, VICEROY = 4 }; //36
		uint8_t  unk5[ 2];
		int8_t founding_father[25];
		uint8_t unk6[6];
		int16_t nation_relation[4];
		uint8_t  unk8[ 2];
		uint8_t  unk9[ 8];
		uint16_t expeditionary_force[4];
		uint8_t  unka[ 8]; //backup force, once you produce enough bells.
		uint16_t count_down[16];
		struct event { //these are events that trigger the "woodframe"
			uint16_t discovery_of_the_new_world     : 1;
			uint16_t building_a_colony              : 1;
			uint16_t meeting_the_natives            : 1;
			uint16_t the_aztec_empire               : 1;
			uint16_t the_inca_nation                : 1;
			uint16_t discovery_of_the_pacific_ocean : 1;
			uint16_t entering_indian_village        : 1;
			uint16_t unk7                           : 1;
			uint16_t cargo_from_the_new_world       : 1;
			uint16_t meeting_fellow_europeans       : 1;
			uint16_t unka                           : 1;
			uint16_t unkb                           : 1;
			uint16_t indian_raid                    : 1;
			uint16_t unkd                           : 1;
			uint16_t unke                           : 1;
			uint16_t unkf                           : 1;
		} __attribute__ ((packed)) event;
		uint8_t unkb[2];
	} __attribute__ ((packed)) head;

	struct player {
		char name[24];
		char country[24];
		uint8_t unk00;
		uint8_t control; enum { PLAYER = 0, AI = 1 };
		uint8_t unk01;
		uint8_t diplomacy;
	} __attribute__ ((packed)) player[4];

	struct other {
		uint8_t unkXX_xx[24];
	} __attribute__ ((packed)) other;

	struct colony {
		uint8_t x, y;
		char name[24];
		uint8_t nation;
		uint8_t unk0[ 4];
		uint8_t population;
		uint8_t unk1[16];
		uint8_t unk2[16];
		uint8_t colonists[32]; //represents profession.
		uint8_t unk6[16];

		uint8_t tiles[ 8]; //represents tiles around the colony. idx to citizen.

		uint8_t unk8[12];
		struct buildings {
			uint32_t stockade : 3;
			uint32_t armory : 3;
			uint32_t docks : 3;
			uint32_t town_hall : 3;
			uint32_t schoolhouse : 3;
			uint32_t warehouse : 2;
			uint32_t stables : 1;
			uint32_t custom_house : 1;
			uint32_t printing_press : 2;
			uint32_t weavers_house : 3;
			uint32_t tobacconists_house : 3;
			uint32_t rum_distillers_house : 3;
			uint32_t capitol : 2; /* not really in use */

			uint16_t fur_traders_house : 3;
			uint16_t carpenters_shop : 2;
			uint16_t church : 2;
			uint16_t blacksmiths_house : 3;
			uint16_t unused : 6;
		} __attribute__ ((packed)) buildings;

		uint8_t unk9[6];
		uint8_t unka[ 2];
		uint16_t hammers;
		uint8_t building_in_production;
		uint8_t unkb[ 5];
		uint16_t stock[16];
		uint8_t unkd[ 8];
		uint32_t rebel_dividend;
		uint32_t rebel_divisor;
	} __attribute__ ((packed)) *colony;

	struct unit {
		uint8_t x, y;
		uint8_t mode; enum { COLONIST = 0, SOLDIER = 1, PIONEER = 2, MISSIONARY = 3, DRAGOON = 4, SCOUT = 5, TORY_REGULAR = 6, CONTINENTAL_CAVALRY = 7, TORY_CAVALRY = 8, CONTINENTAL_ARMY = 9, TREASURE = 0x0a, ARTILLERY = 0x0b, WAGON_TRAIN = 0x0c, CARAVEL = 0x0d, MERCHANTMAN = 0x0e, GALEON = 0x0f, PRIVATEER = 0x10, FRIGATE = 0x11, MAN_O_WAR = 0x12, INDIAN = 0x13, MOUNTED_BRAVE = 0x15 };
		uint8_t owner : 4; /* likely to be owner of unit, eng, fra, spa, dut, indian tribes, etc. */
		uint8_t unk04 : 4;
		uint8_t unk05;
		uint8_t moves; /* Accumulated moves (3 between land, 1 on roads, etc.) */
		uint8_t unk06;
		uint8_t unk07;
		uint8_t order; enum { PLOW = 8, ROAD = 9 };
		uint8_t unk09;
		uint8_t unk0a;
		uint8_t unk0b;
		uint8_t unk0c;
		uint8_t unk0d;
		uint8_t unk0e;
		uint8_t unk0f;
		uint8_t unk10;
		uint8_t unk11;
		uint8_t unk12;
		uint8_t unk13;
		uint8_t unk14;
		uint8_t tools;
		uint8_t turns_worked;
		uint8_t profession; enum { EXPERT_FARMER = 0x00, EXPERT_FUR_TRAPPER = 0x04, EXPERT_LUMBERJACK = 0x05, EXPERT_ORE_MINER = 0x06, EXPERT_SILVER_MINER = 0x07, EXPERT_FISHERMAN = 0x08, MASTER_DISTILLER = 0x09, MASTER_TOBACCONIST = 0x0a, MASTER_WEAVER = 0x0b, MASTER_FUR_TRADER = 0x0c, MASTER_CARPENTER = 0x0d, MASTER_BLACKSMITH = 0x0e, MASTER_GUNSMITH = 0x0f, FIREBRAND_PREACHER = 0x10, ELDER_STATESMAN = 0x11, HARDY_PIONEER = 0x14, VETERAN_SOLDIER = 0x15, SEASONED_SCOUT = 0x16, JESUIT_MISSIONARY = 0x18, INDENTURED_SERVANT = 0x19, PETTY_CRIMINAL = 0x1a, FREE_COLONIST = 0x1c  };
		int16_t val1;
		int16_t val2;
	} __attribute__ ((packed)) *unit;

	struct nation {
		uint8_t unk0;
		uint8_t tax_rate;
		uint8_t recruit[3];
		uint8_t unk1;
		uint8_t recruit_count; //recruit penalty 120 + (count * 20) (does not go above 180)
		uint8_t unk2[ 5];
		uint16_t liberty_bells_total;
		uint16_t liberty_bells_last_turn;
		uint8_t unk3[ 2];
		int16_t next_founding_father;
		uint16_t founding_father_count;
		uint16_t ffc_high; //suspect founding_father_count is 32bit.
		uint8_t villages_burned;
		uint8_t unk4[5];
		uint16_t artillery_count; //artillery purchased in europe. 500 + (count * 100) price penalty.
		uint16_t boycott_bitmap;
		uint8_t unk5[ 8];
		uint32_t gold;
		uint16_t crosses;
		int16_t unk6[ 4];
		uint8_t indian_relation[8]; enum { NOT_MET = 0x00, WAR = 0x20, PEACE = 0x60};
		uint8_t unk7[12];
		struct trade {
			uint8_t euro_price[16];
			int16_t nr[16];
			int32_t gold[16];
			int32_t tons[16];
			int32_t tons2[16];
		} __attribute__ ((packed)) trade;
	} __attribute__ ((packed)) nation[4];

	struct tribe {
		uint8_t x, y;
		uint8_t nation;
		struct state {
			uint8_t artillery : 1; //artillery has been nearby?
			uint8_t learned   : 1; //visited and learned skill
			uint8_t capital   : 1;
			uint8_t scouted   : 1; //visited by scout
			uint8_t unk5      : 1;
			uint8_t unk6      : 1;
			uint8_t unk7      : 1;
			uint8_t unk8      : 1;
		} __attribute__ ((packed)) state;
		uint8_t population;
		int8_t mission; //ff if none, 0 1 2 3 = eng fra spa dut
		uint8_t unk1[4];
		uint8_t panic;
		uint8_t unk2[6];
		uint8_t population_loss_in_current_turn; //due to attacks
	} __attribute__ ((packed)) *tribe;

	struct indian_relations {
		uint8_t unk0[58];

		struct meeting {
			uint8_t met;
		} __attribute__ ((packed)) meeting[4];

		uint8_t unk1[8];

		struct aggr {
			uint8_t aggr;
			uint8_t aggr_high;
		} __attribute__ ((packed)) aggr[4];
	} __attribute__ ((packed)) indian_relations[8];

	struct stuff {
		uint8_t unk_big[717];
		uint16_t x;
		uint16_t y;
		uint8_t unk7[2];
		uint16_t viewport_x;
		uint16_t viewport_y;
	} __attribute__ ((packed)) stuff;

	// 56*70 visible + border, = 58*72 = 4176
	struct map { /* 58 x 72 ... (visible 56 x 70) */
		union {
			struct {
				uint8_t tile : 3;
				uint8_t forest : 1;
				uint8_t water : 1;
				uint8_t phys : 3;
			} __attribute__ ((packed));
			uint8_t full;
		} __attribute__ ((packed))  layer[4][58*72];
	} __attribute__ ((packed)) map;

	struct tail {
		uint8_t unk[1502];
	} __attribute__ ((packed)) tail;
} __attribute__ ((packed));