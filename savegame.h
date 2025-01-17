#include <stdint.h>

/// Given a map from keys to values, creates a new map from values to keys 
template<typename K, typename V>
static std::map<V, K> reverse_map(const std::map<K, V> &original) {
    std::map<V, K> reversed;
	for (const auto &pair : original)
		reversed[pair.second] = pair.first;
	return reversed;
}

static std::map<std::string, int> terrain_id {
    {"tundra", 0},
    {"desert", 1},
    {"plains", 2},
    {"prairie", 3},
    {"grassland", 4},
    {"savannah", 5},
    {"swamp", 6},
    {"marsh", 7},
};
static std::map<int, std::string> terrain_name = reverse_map(terrain_id);

static std::map<std::string, int> special_id {
    {"arctic", 0},
    {"ocean", 1},
    {"seas", 2},
};
static std::map<int, std::string> special_name = reverse_map(special_id);

static const char *unit_type_list[] {
	/*  0 */ "Colonist",
	/*  1 */ "Soldier",
	/*  2 */ "Pioneer",
	/*  3 */ "Missionary",
	/*  4 */ "Dragoon",
	/*  5 */ "Scout",
	/*  6 */ "Tory regular",
	/*  7 */ "Continental cavalry",
	/*  8 */ "Tory cavalry",
	/*  9 */ "Continental army",
	/* 10 */ "Treasure",
	/* 11 */ "Artillery",
	/* 12 */ "Wagon train",
	/* 13 */ "Caravel",
	/* 14 */ "Merchantman",
	/* 15 */ "Galeon",
	/* 16 */ "Privateer",
	/* 17 */ "Frigate",
	/* 18 */ "Man-O-War",
	/* 19 */ "Brave",
	/* 20 */ "Armed brave",
	/* 21 */ "Mounted brave",
	/* 22 */ "Mounted warrior",
};

static const char *profession_list[] = {
	/*  0 */ "Expert farmer",
	/*  1 */ "Master sugar planter",
	/*  2 */ "Master tobacco planter",
	/*  3 */ "Master cotton planter",
	/*  4 */ "Expert fur trapper",
	/*  5 */ "Expert lumberjack",
	/*  6 */ "Expert ore miner",
	/*  7 */ "Expert silver miner",
	/*  8 */ "Expert fisherman",
	/*  9 */ "Master distiller",
	/* 10 */ "Master tobacconist",
	/* 11 */ "Master weaver",
	/* 12 */ "Master fur trader",
	/* 13 */ "Master carpenter",
	/* 14 */ "Master blacksmith",
	/* 15 */ "Master gunsmith",
	/* 16 */ "Firebrand preacher",
	/* 17 */ "Elder statesman",
	/* 18 */ "*(Student)",
	/* 19 */ "*(Free colonist)",
	/* 20 */ "Hardy pioneer",
	/* 21 */ "Veteran soldier",
	/* 22 */ "Seasoned scout",
	/* 23 */ "Veteran dragoon",
	/* 24 */ "Jesuit missionary",
	/* 25 */ "Indentured servant",
	/* 26 */ "Petty criminal",
	/* 27 */ "Indian convert",
	/* 28 */ "Free colonist ???",
};

static const char *nation_list[] = {
	/*  0 */ "England",
	/*  1 */ "France",
	/*  2 */ "Spain",
	/*  3 */ "Netherlands",
	/*  4 */ "Inca",
	/*  5 */ "Aztec",
	/*  6 */ "Awarak",
	/*  7 */ "Iroquois",
	/*  8 */ "Cherokee",
	/*  9 */ "Apache",
	/* 10 */ "Sioux",
	/* 11 */ "Tupi",
};

/* 0-3 also used as index to player nation */
static const char *player_list[] = {
    nation_list[0],
    nation_list[1],
    nation_list[2],
    nation_list[3],
};

/* 0-7 also used as index to indian nation */
static const char *indian_list[] = {
    nation_list[4],
    nation_list[5],
    nation_list[6],
    nation_list[7],
    nation_list[8],
    nation_list[9],
    nation_list[10],
    nation_list[11],
};

static std::map<const char*, int> cargo_id {
    {"food",      0},
    {"sugar",     1},
    {"tobacco",   2},
    {"cotton",    3},
    {"furs",      4},
    {"lumber",    5},
    {"ore",       6},
    {"silver",    7},
    {"horses",    8},
    {"rum",       9},
    {"cigars",   10},
    {"cloth",    11},
    {"coats",    12},
    {"goods",    13},
    {"tools",    14},
    {"muskets",  15},
    {"none",    255},
};
static std::map<int, const char*> cargo_name = reverse_map(cargo_id);

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

static const char *tech_list[] = {
	"Semi-Nomadic",
	"Agrarian",
	"Advanced",
	"Civilized",
};

static std::map<const char*, int> order_id {
    {"none",      0},
    {"sentry",    1},
    {"trading",   2},
    {"goto",      3},

    {"fortified", 5},
    {"fortify",   6},

    {"plow",      8},
    {"road",      9},

    {"unknownb",  11},
    {"unknownc",  12},
};
static std::map<int, const char*> order_name = reverse_map(order_id);

struct savegame {
    
	struct head {
		char sig_colonize[9];
		uint8_t unknown00[ 3];
		uint16_t map_size_x;
		uint16_t map_size_y;
		struct tut1 {
			uint8_t nr13  : 1;
			uint8_t nr14  : 1;
			uint8_t unknown01 : 1;
			uint8_t nr15  : 1;
			uint8_t nr16  : 1;
			uint8_t nr17  : 1;
			uint8_t unknown02  : 1;
			uint8_t nr19  : 1;
		} __attribute__ ((packed)) tut1;

		uint8_t unknown03;

		struct game_options {
			uint16_t unused01           : 7;
			uint16_t tutorial_hints     : 1;
			uint16_t water_color_cycling: 1;
			uint16_t combat_analysis    : 1;
			uint16_t autosave           : 1;
			uint16_t end_of_turn        : 1;
			uint16_t fast_piece_slide   : 1;
			uint16_t unused02           : 1;
			uint16_t show_foreign_moves : 1;
			uint16_t show_indian_moves  : 1;
		} __attribute__ ((packed)) game_options;

		struct colony_report_options {
			uint16_t labels_on_cargo_and_terrain        : 1;
			uint16_t labels_on_buildings                : 1;
			uint16_t report_new_cargos_available        : 1;
			uint16_t report_inefficient_government      : 1;
			uint16_t report_tools_needed_for_production : 1;
			uint16_t report_raw_materials_shortages     : 1;
			uint16_t report_food_shortages              : 1;
			uint16_t report_when_colonists_trained      : 1;
			uint16_t report_sons_of_liberty_membership  : 1;
			uint16_t report_rebel_majorities            : 1;
			uint16_t unused03                           : 6;
		} __attribute__ ((packed)) colony_report_options;

		struct tut2 {
			uint8_t howtowin         : 1;
			uint8_t background_music : 1;
			uint8_t event_music      : 1;
			uint8_t sound_effects    : 1;
			uint8_t nr1 : 1; // shown immediately on game-start
			uint8_t unused04 : 1; // probably not used, also triggers event_discovery_of_the_new_world
			uint8_t nr3 : 1;
			uint8_t nr4 : 1;
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

		uint8_t unknown39[2];
		uint16_t year;
		uint16_t autumn; //boolean, true if autumn
		uint16_t turn;
		uint8_t unknown40[2];
		uint16_t active_unit;
		uint8_t unknown41[6];
		uint16_t tribe_count;
		uint16_t unit_count;
		uint16_t colony_count;
		uint8_t unknown42[6];
		uint8_t difficulty; enum { DISCOVERER = 0, EXPLORER = 1, CONQUISTADOR = 2, GOVERNOR = 3, VICEROY = 4 }; //36
		uint8_t unknown43[2];
		int8_t founding_father[25];
		uint8_t unknown44[6];
		int16_t nation_relation[4];
		uint8_t unknown45[10];
		uint16_t expeditionary_force[4];
		uint16_t backup_force[ 4]; // backup force, once you produce enough bells.
		uint8_t unknown46[32]; // count down ?
		struct event { //these are events that trigger the "woodframe"
			uint16_t discovery_of_the_new_world     : 1;
			uint16_t building_a_colony              : 1;
			uint16_t meeting_the_natives            : 1;
			uint16_t the_aztec_empire               : 1;
			uint16_t the_inca_nation                : 1;
			uint16_t discovery_of_the_pacific_ocean : 1;
			uint16_t entering_indian_village        : 1;
			uint16_t the_fountain_of_youth          : 1;
			uint16_t cargo_from_the_new_world       : 1;
			uint16_t meeting_fellow_europeans       : 1;
			uint16_t colony_burning                 : 1;
			uint16_t colony_destroyed               : 1;
			uint16_t indian_raid                    : 1;
			uint16_t woodcut14                      : 1;
			uint16_t woodcut15                      : 1;
			uint16_t woodcut16                      : 1;
		} __attribute__ ((packed)) event;
		uint8_t unknown05[2];
	} __attribute__ ((packed)) head;

	struct player {
		char name[24];
		char country_name[24];
		uint8_t unknown06;
		uint8_t control; enum { PLAYER = 0, AI = 1, WITHDRAWN = 2, };
		uint8_t founded_colonies; // founded colonies, probably used pick next colony name
		uint8_t diplomacy; // ?
	} __attribute__ ((packed)) player[4];

	struct other {
		uint8_t unknown07[24];
	} __attribute__ ((packed)) other;

	struct colony {
		uint8_t x;
		uint8_t y;
		char name[24];
		uint8_t nation_id;
		uint8_t unknown08[ 4];
		uint8_t population;
		uint8_t occupation[32];
		uint8_t profession[32];
		struct duration {
		    uint8_t high : 4; // second one is first in byte
		    uint8_t low : 4;
        } __attribute__ ((packed)) duration[16];

		int8_t tiles[ 8]; //represents tiles around the colony. idx to citizen.

		uint8_t unknown10[12];

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
			uint16_t unused05 : 6;
		} __attribute__ ((packed)) buildings;

		struct custom_house {
			uint16_t food : 1;
			uint16_t sugar : 1;
			uint16_t tobacco : 1;
			uint16_t cotton : 1;
			uint16_t furs : 1;
			uint16_t lumber : 1;
			uint16_t ore : 1;
			uint16_t silver : 1;
			uint16_t horses : 1;
			uint16_t rum : 1;
			uint16_t cigars : 1;
			uint16_t cloth : 1;
			uint16_t coats : 1;
			uint16_t trade_goods : 1;
			uint16_t tools : 1;
			uint16_t muskets : 1;
		} __attribute__ ((packed)) custom_house;

		uint8_t unknown11[6];
		uint16_t hammers;
		uint8_t building_in_production;
		uint8_t unknown12[ 5];
		uint16_t stock[16];
		uint8_t unknown13[ 8];
		uint32_t rebel_dividend;
		uint32_t rebel_divisor;
	} __attribute__ ((packed)) *colony;

	struct unit {
		uint8_t x;
		uint8_t y;
		uint8_t type;
		uint8_t nation_id : 4; /* likely to be owner of unit, eng, fra, spa, dut, indian tribes, etc. */
		uint8_t unused06 : 4;
		uint8_t unknown15;
		uint8_t moves; /* moves spent? or accumulated moves (3 between land, 1 on roads, etc.) */
		uint8_t unknown16[2];
		uint8_t orders;
		uint8_t goto_x;
		uint8_t goto_y;
		uint8_t unknown18;
		uint8_t holds_occupied;
		uint8_t cargo_item_0 : 4;
		uint8_t cargo_item_1 : 4;
		uint8_t cargo_item_2 : 4;
		uint8_t cargo_item_3 : 4;
		uint8_t cargo_item_4 : 4;
		uint8_t cargo_item_5 : 4;
		uint8_t cargo_hold[6];
		uint8_t turns_worked;
		uint8_t profession;
		struct transport_chain {
			int16_t next_unit_idx;
			int16_t prev_unit_idx; // index to unit being transported? (treasure)
		} __attribute__ ((packed)) transport_chain;
	} __attribute__ ((packed)) *unit;

	struct nation {
		uint8_t unknown19;
		uint8_t tax_rate;
		uint8_t recruit[3];
		uint8_t unused07;
		uint8_t recruit_count; //recruit penalty 120 + (count * 20) (does not go above 180)
		uint8_t founding_fathers[4];
		uint8_t unknown21;
		uint16_t liberty_bells_total;
		uint16_t liberty_bells_last_turn;
		uint8_t unknown22[2];
		int16_t next_founding_father;
		uint16_t founding_father_count;
		uint16_t unused08; //suspect founding_father_count is 32bit.
		uint8_t villages_burned;
		uint8_t unknown23[5];
		uint16_t artillery_count; //artillery purchased in europe. 500 + (count * 100) price penalty.
		uint16_t boycott_bitmap;
		uint8_t unknown24[8];
		uint32_t gold;
		uint16_t current_crosses;
		uint16_t needed_crosses;
		uint8_t unknown25[6];
		uint8_t relation_by_indian[8]; enum { NOT_MET = 0x00, WAR = 0x20, PEACE = 0x60};
		uint8_t unknown26[12];
		struct trade {
			uint8_t euro_price[16];
			int16_t nr[16];
			int32_t gold[16];
			int32_t tons[16];
			int32_t tons2[16];
		} __attribute__ ((packed)) trade;
	} __attribute__ ((packed)) nation[4];

	struct tribe {
		uint8_t x;
		uint8_t y;
		uint8_t nation_id;
		struct state {
			uint8_t artillery : 1; //artillery has been nearby?
			uint8_t learned   : 1; //visited and learned skill
			uint8_t capital   : 1;
			uint8_t scouted   : 1; //visited by scout
			uint8_t unused09  : 4;
		} __attribute__ ((packed)) state;
		uint8_t population;
		uint8_t mission; //ff if none, 0 1 2 3 = eng fra spa dut
		uint8_t unknown28[2];
		uint8_t last_bought;
		uint8_t last_sold;
        struct alarm {
            uint8_t friction;
            uint8_t attacks;
		} __attribute__ ((packed)) alarm[4];
	} __attribute__ ((packed)) *tribe;

	struct indian {
		uint8_t capitol_x;
		uint8_t capitol_y;
		uint8_t tech;
		uint8_t unknown31[11];
		int16_t tons[16];
		uint8_t unknown32[12];
		uint8_t met_by_player[4];
		uint8_t unknown33[8]; 
        uint16_t alarm_by_player[4];
	} __attribute__ ((packed)) indian[8];

	struct stuff {
		uint8_t unknown34[15];
		uint16_t counter_decreasing_on_new_colony;
		uint8_t unknown35[2];
		uint16_t counter_increasing_on_new_colony;
		uint8_t unknown36[696];
		uint16_t x;
		uint16_t y;
		uint8_t zoom_level;
		uint8_t unknown37;
		uint16_t viewport_x;
		uint16_t viewport_y;
	} __attribute__ ((packed)) stuff;

	// 56*70 visible + border, = 58*72 = 4176
    // 58 x 72 ... (visible 56 x 70)

	struct map {
		union tile {
			uint8_t full;
			struct {
				uint8_t base : 3;
				uint8_t forest : 1;
				uint8_t special : 1;
				uint8_t hills : 1;
				uint8_t river : 1;
				uint8_t major : 1;
			} __attribute__ ((packed));
		} __attribute__ ((packed)) tile[58*72];
		union mask {
			uint8_t full;
			struct {
				uint8_t has_unit : 1;
				uint8_t has_city : 1;
				uint8_t suppress : 1; // hides ocean fish and depletes minerals
				uint8_t road : 1;
				uint8_t purchased : 1; // purchased from natives
				uint8_t pacific : 1;
				uint8_t plowed : 1;
				uint8_t unused : 1;
			} __attribute__ ((packed));
		} __attribute__ ((packed)) mask[58*72];
		union path {
			uint8_t full;
			struct {
				uint8_t region : 4;  // ocean or continent id
				uint8_t visitor : 4; // nation id (0-11), 15=unvisted
			} __attribute__ ((packed));
		} __attribute__ ((packed)) path[58*72];
		union seen {
			uint8_t full;
			struct {
				uint8_t score : 4; // helps AI choose colony sites
				uint8_t english : 1; // visible to english
				uint8_t french : 1; // visible to french
				uint8_t spanish : 1; // visible to spanish
				uint8_t dutch : 1; // visible to dutch
			} __attribute__ ((packed));
		} __attribute__ ((packed)) seen[58*72];
	} __attribute__ ((packed)) map;

	uint8_t unknown38[1502];

} __attribute__ ((packed)) savegame;
