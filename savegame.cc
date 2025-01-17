#include <assert.h>
#include <ctype.h>
#include <getopt.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <regex>

#include "savegame_api.h"

void print_head(  const struct savegame::head   *head);
void print_player(const struct savegame::player *player,                        int just_this_one = -1);
void print_other( const struct savegame::other  *other);
void print_colony(const struct savegame::colony *colony, uint16_t colony_count, int just_this_one = -1);
void print_unit(  const struct savegame::unit   *unit,   uint16_t unit_count,   int just_this_one = -1);
void print_nation(const struct savegame::nation *nation,                        int just_this_one = -1);
void print_tribe( const struct savegame::tribe  *tribe,  uint16_t tribe_count,  int just_this_one = -1);
void print_indian(const struct savegame::indian *indian,                        int just_this_one = -1);
void print_stuff( const struct savegame::stuff  *stuff);
void print_map(   const struct savegame::map    *map, int x, int y);
void print_tail(  const uint8_t *tail);
void print_bytes( const uint8_t *bytes,int size); 
            
void set_value( struct savegame *sg, std::string input, std::string value, int i, int j);

void dump(void *address, size_t bytes, const char *filename);

void print_help(const char *prog){
	fprintf(stderr, "Usage: %s -f <COLONY0*.SAV> [options|edits]\n", prog);
	fprintf(stderr, "OPTIONs:\n");
	fprintf(stderr, "-h, --help       displays this help message          \n");
	fprintf(stderr, "                                                     \n");
	fprintf(stderr, "-f, --file      savegame file to read in (and edit)  \n");
	fprintf(stderr, "                                                     \n");
	fprintf(stderr, "-H, --head       displays head section of savegame   \n");
	fprintf(stderr, "-T, --tail       displays tail section of savegame   \n");
	fprintf(stderr, "-o, --other      displays other section of savegame  \n");
	fprintf(stderr, "-s, --stuff      displays stuff section of savegame  \n");
	fprintf(stderr, "-m, --map        displays map section of savegame    \n");
	fprintf(stderr, "                                                     \n");
	fprintf(stderr, "-xN / -yN        details this section of the map     \n");
	fprintf(stderr, "                                                     \n");
	fprintf(stderr, "If N is given, displays a single entry in the section\n");
	fprintf(stderr, "-pN, --player=N  displays player section of savegame \n");
	fprintf(stderr, "-uN, --unit=N    displays unit section of savegame   \n");
	fprintf(stderr, "-nN, --nation=N  displays nation section of savegame \n");
	fprintf(stderr, "-iN, --indian=N  displays indian section of savegame \n");
	fprintf(stderr, "-tN, --tribe=N   displays tribe section of savegame  \n");
	fprintf(stderr, "                                                     \n");
	fprintf(stderr, "EDITS are the API key and new value, joined by '='   \n");
	fprintf(stderr, "The modified savegame is written to COLONY10.SAV     \n");
	fprintf(stderr, "                                                     \n");
	fprintf(stderr, "--colony10  performs several example modifications   \n");
}

int main(int argc, char *argv[])
{
	assert(sizeof (struct savegame::head)   == 158);
	assert(sizeof (struct savegame::player) ==  52);
	assert(sizeof (struct savegame::colony) == 202);
	assert(sizeof (struct savegame::unit)   ==  28);
	assert(sizeof (struct savegame::nation) == 316);
	assert(sizeof (struct savegame::tribe)  ==  18);
	assert(sizeof (struct savegame::indian) ==  78);
	assert(sizeof (struct savegame::stuff)  == 727);
	assert(sizeof (struct savegame::map)    == 58*72*4);

	int c, optindex = 0;

	/* Flags
	 *  -1 print all
	 *  0 don't print any
	 *  n print specific entry
	 */
	int opt_head = 0, opt_player = 0, opt_other = 0, opt_colony = 0, opt_unit = 0,
	    opt_nation = 0, opt_tribe = 0, opt_stuff = 0, opt_indian = 0, opt_map = 0,
	    opt_tail = 0, opt_help = 0, opt_colony10 = 0, 
        opt_x = 0, opt_y = 0;
    char *opt_file;

	static struct option long_options[] = {
		{ "head",     no_argument,       NULL,          'H' },
		{ "player",   optional_argument, NULL,          'p' },
		{ "other",    no_argument,       NULL,          'o' },
		{ "colony",   optional_argument, NULL,          'c' },
		{ "unit",     optional_argument, NULL,          'u' },
		{ "nation",   optional_argument, NULL,          'n' },
		{ "tribe",    optional_argument, NULL,          't' },
		{ "indian",   optional_argument, NULL,          'i' },
		{ "stuff",    no_argument,       NULL,          's' },
		{ "map",      no_argument,       NULL,          'm' },
		{ "tail",     no_argument,       NULL,          'T' },
		{ "file",     required_argument, NULL,          'f' },
		{ "x",        required_argument, NULL,          'x' },
		{ "y",        required_argument, NULL,          'y' },
		{ "colony10", no_argument,       &opt_colony10, -1  },
		{ "help",     no_argument,       NULL,          'h' },
		{ NULL,       no_argument, NULL,  0  }
	};

	while ((c = getopt_long(argc, argv, ":Hp::oc::u::n::t::i::smThf:x:y:", long_options, &optindex)) != -1) {
		switch (c) {

			case 0:
				/* If this option set a flag, do nothing else now. */
				if (long_options[optindex].flag != 0)
					break;
				printf("option %s", long_options[optindex].name);
				if (optarg)
					printf(" with arg %s", optarg);
				printf("\n");

			case 'H': opt_head   = -1; break;
			case 'p': opt_player = -1;
				if (optarg && isdigit(optarg[0]) )
					opt_player = atoi(optarg) + 1;
				break;
			case 'o': opt_other  = -1; break;
			case 'c': opt_colony = -1;
				if (optarg && isdigit(optarg[0]) )
					opt_colony = atoi(optarg) + 1;
				break;
			case 'u': opt_unit   = -1;
				if (optarg && isdigit(optarg[0]) )
					opt_unit = atoi(optarg) + 1;
				break;
			case 'n': opt_nation = -1;
				if (optarg && isdigit(optarg[0]) )
					opt_nation = atoi(optarg) + 1;
				break;
			case 't': opt_tribe  = -1;
				if (optarg && isdigit(optarg[0]) )
					opt_tribe = atoi(optarg) + 1;
				break;
			case 'i': opt_indian = -1;
				if (optarg && isdigit(optarg[0]) )
					opt_indian = atoi(optarg) + 1;
				break;
			case 's': opt_stuff  = -1; break;
			case 'm': opt_map    = -1; break;
			case 'T': opt_tail   = -1; break;
			case 'f': 
				opt_file = optarg;
				break;
			case 'y': 
				if (optarg && isdigit(optarg[0]) )
					opt_y = atoi(optarg);
				break;
			case 'x':
				if (optarg && isdigit(optarg[0]) )
					opt_x = atoi(optarg);
				break;

			case '?': /* fall through to 'h'*/
				fprintf(stderr, "Unknown option '%s'\n", argv[optind-1]);
			case 'h':
				print_help(argv[0]);
				exit(EXIT_FAILURE);

			default:
				fprintf(stderr, "case '%c' (0x%02x): ", c, c);
				if (optopt) fprintf(stderr, "optopt: %d ", optopt);
				if (optarg) fprintf(stderr, "optarg: %s ", optarg);
				fprintf(stderr, "\n");
				break;
		}
	}
	
    if (optind > argc) {
		print_help(argv[0]);
		exit(EXIT_FAILURE);
	}

		struct savegame sg;

		FILE *fp = fopen(opt_file, "rb");	

		if (fp == NULL) {
			printf("Could not open file: %s\n", opt_file);
			exit(EXIT_FAILURE);
		}
	
		size_t res = 0;
		res = fread(&sg.head, sizeof (struct savegame::head), 1, fp);
		res = fread(sg.player, sizeof (savegame::player), 1, fp);
		res = fread(&sg.other, sizeof (savegame::other), 1, fp);

		sg.colony = (struct savegame::colony *) malloc(sizeof (struct savegame::colony) * sg.head.colony_count);
		res = fread(sg.colony, sizeof (struct savegame::colony), sg.head.colony_count, fp);
	
		sg.unit   = (struct savegame::unit *)   malloc(sizeof (struct savegame::unit)   * sg.head.unit_count);
		res = fread(sg.unit, sizeof (struct savegame::unit), sg.head.unit_count, fp);
	
		res = fread(sg.nation, sizeof (savegame::nation), 1, fp);
	
		sg.tribe  = (struct savegame::tribe *)  malloc(sizeof (struct savegame::tribe)  * sg.head.tribe_count);
		res = fread(sg.tribe, sizeof (struct savegame::tribe), sg.head.tribe_count, fp);
        
        res = fread(sg.indian, sizeof (savegame::indian), 1, fp);
		res = fread(&sg.stuff, sizeof (struct savegame::stuff), 1, fp);
		res = fread(&sg.map, sizeof (struct savegame::map), 1, fp);
		res = fread(&sg.unknown38, sizeof (savegame::unknown38), 1, fp);
	
		fclose(fp);

//        if (opt_json)
//            print_json(&(sg));
	
		if (opt_head)
			print_head(&(sg.head));
	
		if (opt_player)
			print_player(sg.player, (opt_player == -1) ? opt_player: opt_player - 1);
	
		if (opt_other)
			print_other(&(sg.other));
	
		if (opt_colony)
			print_colony(sg.colony, sg.head.colony_count, (opt_colony == -1) ? opt_colony : opt_colony - 1);
	
		if (opt_unit)
			print_unit(sg.unit, sg.head.unit_count, (opt_unit == -1) ? opt_unit : opt_unit - 1);
	
		if (opt_nation)
			print_nation(sg.nation, (opt_nation == -1) ? opt_nation : opt_nation - 1);
	
		if (opt_tribe)
			print_tribe(sg.tribe, sg.head.tribe_count, (opt_tribe == -1) ? opt_tribe : opt_tribe - 1);
	
		if (opt_indian)
			print_indian(sg.indian, (opt_indian == -1) ? opt_indian : opt_indian - 1);
	
		if (opt_stuff)
			print_stuff(&(sg.stuff));
	
		if (opt_map || opt_x > 0 || opt_y > 0)
			print_map(&(sg.map),opt_x,opt_y);
	
		if (opt_tail)
			print_tail(sg.unknown38);
	
		std::string delimiter = "=";
        for (int edit_index = optind; edit_index < argc; edit_index++) {
            std::string s = argv[edit_index];
			std::string key = s.substr(0, s.find(delimiter));
			std::string value = s.substr(s.find(delimiter)+delimiter.length());

            std::regex str_expr(".*?\\.([0-9]+).*");

            int i = -1;
            std::smatch smi;
            std::regex_match(key,smi,str_expr);
            if (smi.size()>1) {
                i = atoi(smi.str(1).c_str());
                key.replace(smi.position(1),smi.length(1),"i");
            }

            int j = -1;
            std::smatch smj;
            std::regex_match(key,smj,str_expr);
            if (smj.size()>1) {
                j = atoi(smj.str(1).c_str());
                key.replace(smj.position(1),smj.length(1),"j");
            }

            //printf("key=%s value=%s i=%d j=%d\n",key.c_str(),value.c_str(),i,j);
            set_value( &sg, key, value, i, j);
        }

		if (opt_colony10) {

			/* Find our player */
			int player_nation = -1;
			for (int i = 0; i < 4; ++i) {
				if (sg.player[i].control == 0) {
					player_nation = i;
					break;
				}
			}

			sg.nation[player_nation].gold = 4000000;

			for (int i = 0; i < sg.head.colony_count; ++i) {
				if (sg.colony[i].nation_id == player_nation) {

					for (int j = 0; j < 32; ++j) {
						switch (j) {
							case 0:
							case 1:
							case 2:
								sg.colony[i].profession[j] = 0x11; // elder statesman
								sg.colony[i].occupation[j] = 0x11;
								break;
							case 3:
							case 4:
								sg.colony[i].profession[j] = 0x0d; // carpenter
								sg.colony[i].occupation[j] = 0x0d;
								break;
							case 5:
							case 6:
								sg.colony[i].profession[j] = 0x0e; // blacksmith
								sg.colony[i].occupation[j] = 0x0e;
								break;
							case 7:
								sg.colony[i].profession[j] = 0x05; // lumberjack
								sg.colony[i].occupation[j] = 0x05;
								sg.colony[i].tiles[0] = j;
								break;
							case 8:
								sg.colony[i].profession[j] = 0x08; // fisherman
								sg.colony[i].occupation[j] = 0x08;
								sg.colony[i].tiles[1] = j;
								break;
							case 9:
								sg.colony[i].profession[j] = 0x06; // oreminer
								sg.colony[i].occupation[j] = 0x06;
								sg.colony[i].tiles[4] = j;
								break;

							default:
								continue;
						}
					}

					sg.colony[i].population = 10;

					sg.colony[i].buildings.docks = 1;
					sg.colony[i].buildings.custom_house = 1;
					continue;
				}

				// Opposing nations, remove pesky stockades
				sg.colony[i].buildings.stockade = 0;
			}
        }
		
        if ( optind < argc || opt_colony10 ) {
			FILE *fop = fopen("COLONY10.SAV", "wb");
			fwrite(&sg.head, sizeof (struct savegame::head), 1, fop);
			fwrite(&sg.player, sizeof (savegame::player), 1, fop);
			fwrite(&sg.other, sizeof (struct savegame::other), 1, fop);
			fwrite(sg.colony, sizeof (struct savegame::colony), sg.head.colony_count, fop);
			fwrite(sg.unit, sizeof (struct savegame::unit), sg.head.unit_count, fop);
			fwrite(sg.nation, sizeof (savegame::nation), 1, fop);
			fwrite(sg.tribe, sizeof (struct savegame::tribe), sg.head.tribe_count, fop);
			fwrite(sg.indian, sizeof (savegame::indian), 1, fop);
			fwrite(&sg.stuff, sizeof (struct savegame::stuff), 1, fop);
			fwrite(&sg.map, sizeof (struct savegame::map), 1, fop);
			fwrite(&sg.unknown38, sizeof(savegame::unknown38), 1, fop);
			fclose(fop);
		}

		free(sg.colony);
		free(sg.unit);
		free(sg.tribe);
	
	return EXIT_SUCCESS;
}

void print_bytes(const uint8_t *bytes, int size) 
{
    for (int i = 0; i < size; ++i) {
        printf("%02x ", bytes[i]);
    }
}

void print_head(  const struct savegame::head   *head)
{
	printf("-- head --\n");

	printf("Signature: %s: %s\n",
		head->sig_colonize,
		strncmp(head->sig_colonize, "COLONIZE", 9) ? "INVALID" : "OK");

	print_bytes(head->unknown00,sizeof(head->unknown00));
	printf("\n\n");

	printf("Map size: %2d x %2d\n",
		head->map_size_x, head->map_size_y);

	printf("Tutorial 13: %5s\n", head->tut1.nr13 ? "true" : "false");
	printf("Tutorial 14: %5s\n", head->tut1.nr14 ? "true" : "false");
	printf("tut1.x3    : %5s\n", head->tut1.unknown01 ? "true" : "false");
	printf("Tutorial 15: %5s\n", head->tut1.nr15 ? "true" : "false");
	printf("Tutorial 16: %5s\n", head->tut1.nr16 ? "true" : "false");
	printf("Tutorial 17: %5s\n", head->tut1.nr17 ? "true" : "false");
	printf("tut1.x7    : %5s\n", head->tut1.unknown02 ? "true" : "false");
	printf("Tutorial 19: %5s\n", head->tut1.nr19 ? "true" : "false");
	printf("\n");

	printf("%02x ", head->unknown03);
	printf("\n\n");

	printf("Set Game Options:\n");
	printf("  %c Show Indian Moves\n",   head->game_options.show_indian_moves   ? '*' : ' ');
	printf("  %c Show Foreign Moves\n",  head->game_options.show_foreign_moves  ? '*' : ' ');
	printf("  %c Fast Piece Slide\n",    head->game_options.fast_piece_slide    ? '*' : ' ');
	printf("  %c End of Turn\n",         head->game_options.end_of_turn         ? '*' : ' ');
	printf("  %c Autosave\n",            head->game_options.autosave            ? '*' : ' ');
	printf("  %c Combat Analysis\n",     head->game_options.combat_analysis     ? '*' : ' ');
	printf("  %c Water Color Cycling\n", head->game_options.water_color_cycling ? ' ' : '*'); // I don't know why it's inverted
	printf("  %c Tutorial Hints\n",      head->game_options.tutorial_hints      ? '*' : ' ');

	assert(head->game_options.unused01 == 0);
	assert(head->game_options.unused02 == 0);

	printf("Colony report options\n");
	printf("%d - Labels on buildings\n",                head->colony_report_options.labels_on_buildings);
	printf("%d - Labels on cargo and terrain\n",        head->colony_report_options.labels_on_cargo_and_terrain);
	printf("%d - report_when_colonists_trained\n",      head->colony_report_options.report_when_colonists_trained);
	printf("%d - report_food_shortages\n",              head->colony_report_options.report_food_shortages);
	printf("%d - report_raw_materials_shortages\n",     head->colony_report_options.report_raw_materials_shortages);
	printf("%d - report_tools_needed_for_production\n", head->colony_report_options.report_tools_needed_for_production);
	printf("%d - report_inefficient_government\n",      head->colony_report_options.report_inefficient_government);
	printf("%d - report_new_cargos_available\n",        head->colony_report_options.report_new_cargos_available);
	printf("%d - report_sons_of_liberty_membership\n",  head->colony_report_options.report_sons_of_liberty_membership);
	printf("%d - report_rebel_majorities\n",            head->colony_report_options.report_rebel_majorities);
	printf("\n");

	assert(head->colony_report_options.unused03 == 0);

	printf("HowToWin        : %5s\n", head->tut2.howtowin ? "true" : "false");

	printf("Set Sound Options:\n");
	printf("  %c Background Music\n", head->tut2.background_music ? '*' : ' ');
	printf("  %c Event Music\n",      head->tut2.event_music      ? '*' : ' ');
	printf("  %c Sound Effects\n",    head->tut2.sound_effects    ? '*' : ' ');

	printf("Tutorial  1: %5s\n", head->tut2.nr1  ? "true" : "false");
	printf("Tutorial  3: %5s\n", head->tut2.nr3  ? "true" : "false");
	printf("Tutorial  4: %5s\n", head->tut2.nr4  ? "true" : "false");
	printf("Tutorial  5: %5s\n", head->tut3.nr5  ? "true" : "false");
	printf("Tutorial  6: %5s\n", head->tut3.nr6  ? "true" : "false");
	printf("Tutorial  7: %5s\n", head->tut3.nr7  ? "true" : "false");
	printf("Tutorial  8: %5s\n", head->tut3.nr8  ? "true" : "false");
	printf("Tutorial  9: %5s\n", head->tut3.nr9  ? "true" : "false");
	printf("Tutorial 10: %5s\n", head->tut3.nr10 ? "true" : "false");
	printf("Tutorial 11: %5s\n", head->tut3.nr11 ? "true" : "false");
	printf("Tutorial 12: %5s\n", head->tut3.nr12 ? "true" : "false");
	printf("\n");

	assert(head->tut2.unused04 == 0); // I don't think this is used

	print_bytes(head->unknown39,sizeof(head->unknown39));
	printf("\n\n");

	printf("%s %4d, Turn: %2d\n",
		head->autumn ? "Autumn" : "Spring",
		head->year,
		head->turn);
	
    printf("Active unit: %d", head->active_unit);
	
    print_bytes(head->unknown41,sizeof(head->unknown41));
	printf("\n\n");

	assert(head->unit_count <= 300);

	printf("Tribes: %d, Units: %d, Colonies: %d\n",
		head->tribe_count,
		head->unit_count,
		head->colony_count);

    print_bytes(head->unknown42,sizeof(head->unknown42));
	printf("\n\n");
	
    printf("Difficulty: %s\n",
		difficulty_list[head->difficulty]);

    print_bytes(head->unknown43,sizeof(head->unknown43));
	printf("\n\n");

	printf("Founding fathers:\n");
	for (int i = 0; i < 25; ++i) {
		switch (head->founding_father[i]) {
			case -1: printf("( -1)"); break;
			case  0: printf("(Eng)"); break;
			case  1: printf("(Fra)"); break;
			case  2: printf("(Spa)"); break;
			case  3: printf("(Dut)"); break;
			default: printf("(Unk)"); break;
		}
		printf(", %s\n", founding_father_list[i]);
	}
	printf("\n");

    print_bytes(head->unknown44,sizeof(head->unknown44));
	printf("\n");

	for (int i = 0; i < 4; ++i)
		printf("National relation: %3d %s\n", head->nation_relation[i], nation_list[i]);
	printf("\n");
    
    print_bytes(head->unknown45,sizeof(head->unknown45));
	printf("\n");

	for (int i = 0; i < 4; ++i) {
		switch (i) {
			case 0: printf("%d Regulars, ",  head->expeditionary_force[i]); break;
			case 1: printf("%d Cavalry,  ",  head->expeditionary_force[i]); break;
			case 2: printf("%d Man-O-War, ", head->expeditionary_force[i]); break;
			case 3: printf("%d Artillery\n", head->expeditionary_force[i]); break;
		}
	}

	printf("Backup:");
	for (int i = 0; i < 4; ++i) {
		switch (i) {
			case 0: printf("%d Regulars, ",  head->backup_force[i]); break;
			case 1: printf("%d Cavalry,  ",  head->backup_force[i]); break;
			case 2: printf("%d Man-O-War, ", head->backup_force[i]); break;
			case 3: printf("%d Artillery\n", head->backup_force[i]); break;
		}
    }

    print_bytes(head->unknown46,sizeof(head->unknown46));
	printf("\n");

	printf("event_discovery_of_the_new_world     : %5s\n", head->event.discovery_of_the_new_world     ? "true" : "false");
	printf("event_building_a_colony              : %5s\n", head->event.building_a_colony              ? "true" : "false");
	printf("event_meeting_the_natives            : %5s\n", head->event.meeting_the_natives            ? "true" : "false");
	printf("event_the_aztec_empire               : %5s\n", head->event.the_aztec_empire               ? "true" : "false");
	printf("event_the_inca_nation                : %5s\n", head->event.the_inca_nation                ? "true" : "false");
	printf("event_discovery_of_the_pacific_ocean : %5s\n", head->event.discovery_of_the_pacific_ocean ? "true" : "false");
	printf("event_entering_indian_village        : %5s\n", head->event.entering_indian_village        ? "true" : "false");
	printf("event_the_fountain_of_youth          : %5s\n", head->event.the_fountain_of_youth          ? "true" : "false");
	printf("event_cargo_from_the_new_world       : %5s\n", head->event.cargo_from_the_new_world       ? "true" : "false");
	printf("event_meeting_fellow_europeans       : %5s\n", head->event.meeting_fellow_europeans       ? "true" : "false");
	printf("event_colony_burning                 : %5s\n", head->event.colony_burning                 ? "true" : "false");
	printf("event_colony_destroyed               : %5s\n", head->event.colony_destroyed               ? "true" : "false");
	printf("event_indian_raid                    : %5s\n", head->event.indian_raid                    ? "true" : "false");
	printf("event_woodcut14                      : %5s\n", head->event.woodcut14                      ? "true" : "false");
	printf("event_woodcut15                      : %5s\n", head->event.woodcut15                      ? "true" : "false");
	printf("event_woodcut16                      : %5s\n", head->event.woodcut16                      ? "true" : "false");

    print_bytes(head->unknown05,sizeof(head->unknown05));
	printf("\n");
}

void print_player(const struct savegame::player *player, int just_this_one)
{
	printf("-- player --\n");

	int start = (just_this_one == -1) ? 0 : just_this_one;

	for (int i = start; i < 4; ++i) {
		printf("%-11s: %23s / %23s : ", nation_list[i], player[i].name, player[i].country_name);
		switch (player[i].control) {
			case savegame::player::PLAYER:    printf("Player    "); break;
			case savegame::player::AI:        printf("AI        "); break;
			case savegame::player::WITHDRAWN: printf("WITHDRAWN "); break;
			default: printf("UNKNOWN (%02x)", player[i].control);
		}
		print_bytes(&player[i].unknown06,sizeof(player[i].unknown06));
		printf("founded: %2d ", player[i].founded_colonies);
		printf("diplomacy: %02x\n", player[i].diplomacy);

		if (just_this_one != -1)
			break;
	}
	printf("\n");
}

void print_other( const struct savegame::other  *other)
{
	printf("-- other --\n");

    print_bytes(other->unknown07,sizeof(other->unknown07));
}

void print_colony(const struct savegame::colony *colony, uint16_t colony_count, int just_this_one)
{
	printf("-- colonies --\n");

	int start = (just_this_one == -1) ? 0 : just_this_one;

	for (int i = start; i < colony_count; ++i) {
		if ( colony[i].nation_id != 3) /* Skip all non-dutch */
			continue;

		printf("[%3d] (%3d, %3d): %2d %s\n", i, colony[i].x, colony[i].y, colony[i].population, colony[i].name);

        print_bytes(colony[i].unknown08,sizeof(colony[i].unknown08));
		printf("\n");

		printf("Colonists;\n");
		for (int j = 0; j < colony[i].population; ++j) {
            struct savegame::colony::duration duration = colony[i].duration[j/2];
            int time = j%2?duration.low:duration.high;
			printf("[%2d]  %s working as %s for %d turns\n",
				j, profession_list[ colony[i].profession[j] ] ,
				   profession_list[ colony[i].occupation[j] ] ,
                   time
                );
        }
		printf("\n");

		printf("%2d | %2d | %2d\n", colony[i].tiles[4], colony[i].tiles[0], colony[i].tiles[5]);
		printf("-------------\n");
		printf("%2d |    | %2d\n",  colony[i].tiles[3],                     colony[i].tiles[1]);
		printf("-------------\n");
		printf("%2d | %2d | %2d\n", colony[i].tiles[7], colony[i].tiles[2], colony[i].tiles[6]);
		printf("\n");

        print_bytes(colony[i].unknown10,sizeof(colony[i].unknown10));
		printf("\n");

		printf("Colony buildings:\n");
			switch( colony[i].buildings.stockade ) {
				case 0: break;
				case 1: printf(" stockade\n"); break;
				case 3: printf(" fort    \n"); break;
				case 7: printf(" fortress\n"); break;
				default: printf("a0: %d\n", colony[i].buildings.stockade); break;
			}

			switch ( colony[i].buildings.armory ) {
				case 0: break;
				case 1: printf(" armory  \n"); break;
				case 3: printf(" magazine\n"); break;
				case 7: printf(" arsenal \n"); break;
				default: printf("a1: %d\n", colony[i].buildings.armory); break;
			}

			switch ( colony[i].buildings.docks ) {
				case 0: break;
				case 1: printf(" docks   \n"); break;
				case 3: printf(" dry dock\n"); break;
				case 7: printf(" shipyard\n"); break;
				default: printf("a2: %d\n", colony[i].buildings.docks); break;
			}

			switch ( colony[i].buildings.town_hall ) {
				case 0: break;
				case 1: printf(" town hall\n"); break;
				case 3: printf("a3: 3\n"); break;
				case 7: printf("a3: 7\n"); break;
				default: printf("a3: %d\n", colony[i].buildings.town_hall); break;
			}

			switch ( colony[i].buildings.schoolhouse ) {
				case 0: break;
				case 1: printf(" schoolhouse\n"); break;
				case 3: printf(" college    \n"); break;
				case 7: printf(" university \n"); break;
				default: printf("a4: %d\n", colony[i].buildings.schoolhouse); break;
			}

			switch ( colony[i].buildings.warehouse ) {
				case 0: break;
				case 1: printf("warehouse\n"); break;
				case 3: printf("warehouse (expansion)\n"); break;
				default: printf("a5: %d\n", colony[i].buildings.warehouse); break;
			}

			switch ( colony[i].buildings.stables ) {
				case 0: break;
				case 1: printf("stables\n"); break;
				default: printf("b1: %d\n", colony[i].buildings.stables); break;
			}

			switch ( colony[i].buildings.custom_house ) {
				case 0: break;
				case 1: printf("custom house\n"); break;
				default: printf("b2: %d\n", colony[i].buildings.custom_house); break;
			}

			switch ( colony[i].buildings.printing_press ) {
				case 0: break;
				case 1: printf("printing press\n"); break;
				case 3: printf("newspaper     \n"); break;
				default: printf("b3: %d\n", colony[i].buildings.printing_press); break;
			}

			switch ( colony[i].buildings.weavers_house ) {
				case 0: break;
				case 1: printf("weaver's house\n"); break;
				case 3: printf("weaver's shop \n"); break;
				case 7: printf("textile mill  \n"); break;
				default: printf("b4: %d\n", colony[i].buildings.weavers_house); break;
			}

			switch ( colony[i].buildings.tobacconists_house ) {
				case 0: break;
				case 1: printf("tobacconist's house\n"); break;
				case 3: printf("tobacconist's shop \n"); break;
				case 7: printf("cigar factory      \n"); break;
				default: printf("b5: %d\n", colony[i].buildings.tobacconists_house); break;
			}

			switch ( colony[i].buildings.rum_distillers_house ) {
				case 0: break;
				case 1: printf("rum distiller's house\n"); break;
				case 3: printf("rum distillery\n"); break;
				case 7: printf("rum factory\n"); break;
				default: printf("b6: %d\n", colony[i].buildings.rum_distillers_house); break;
			}

			switch ( colony[i].buildings.capitol ) {
				case 0: break;
				case 1: printf("capitol\n"); break;
				case 3: printf("capitol (expansion)\n"); break;
				default: printf("b7: %d\n", colony[i].buildings.capitol); break;
			}

			switch ( colony[i].buildings.fur_traders_house ) {
				case 0: break;
				case 1: printf("fur trader's house\n"); break;
				case 3: printf("fur trading post  \n"); break;
				case 7: printf("fur factory       \n"); break;
				default: printf("c0: %d\n", colony[i].buildings.fur_traders_house);
			}

			switch ( colony[i].buildings.carpenters_shop ) {
				case 0: break;
				case 1: printf("carpenter's shop\n"); break;
				case 3: printf("lumber mill\n"); break;
				default: printf("c1: %d\n", colony[i].buildings.carpenters_shop);
			}

			switch ( colony[i].buildings.church ) {
				case 0: break;
				case 1: printf("church\n"); break;
				case 3: printf("cathedral: 3\n"); break;
				default: printf("c2: %d\n", colony[i].buildings.church);
			}

			switch ( colony[i].buildings.blacksmiths_house ) {
				case 0: break;
				case 1: printf("blacksmith's house\n"); break;
				case 3: printf("blacksmith's shop \n"); break;
				case 7: printf("iron works        \n"); break;
				default: printf("c3: %d\n", colony[i].buildings.blacksmiths_house);
			}

			assert(colony[i].buildings.unused05 == 0);

		printf("Custom house:\n");
		printf("  %c food       \n", colony[i].custom_house.food        ? '*' : ' ');
		printf("  %c sugar      \n", colony[i].custom_house.sugar       ? '*' : ' ');
		printf("  %c tobacco    \n", colony[i].custom_house.tobacco     ? '*' : ' ');
		printf("  %c cotton     \n", colony[i].custom_house.cotton      ? '*' : ' ');
		printf("  %c furs       \n", colony[i].custom_house.furs        ? '*' : ' ');
		printf("  %c lumber     \n", colony[i].custom_house.lumber      ? '*' : ' ');
		printf("  %c ore        \n", colony[i].custom_house.ore         ? '*' : ' ');
		printf("  %c silver     \n", colony[i].custom_house.silver      ? '*' : ' ');
		printf("  %c horses     \n", colony[i].custom_house.horses      ? '*' : ' ');
		printf("  %c rum        \n", colony[i].custom_house.rum         ? '*' : ' ');
		printf("  %c cigars     \n", colony[i].custom_house.cigars      ? '*' : ' ');
		printf("  %c cloth      \n", colony[i].custom_house.cloth       ? '*' : ' ');
		printf("  %c coats      \n", colony[i].custom_house.coats       ? '*' : ' ');
		printf("  %c trade_goods\n", colony[i].custom_house.trade_goods ? '*' : ' ');
		printf("  %c tools      \n", colony[i].custom_house.tools       ? '*' : ' ');
		printf("  %c muskets    \n", colony[i].custom_house.muskets     ? '*' : ' ');
		printf("\n");

        print_bytes(colony[i].unknown11,sizeof(colony[i].unknown11));
		printf("\n");

		printf("%3d hammers ", colony[i].hammers);
		printf("producing: ");
		switch (colony[i].building_in_production) {
			case 255: printf("Nothing              \n"); break;
			case   0: printf("Stockade             \n"); break;
			case   1: printf("Fort                 \n"); break;
			case   2: printf("Fortress             \n"); break;
			case   3: printf("Armory               \n"); break;
			case   4: printf("Magazine             \n"); break;
			case   5: printf("Arsenal              \n"); break;
			case   6: printf("Docks                \n"); break;
			case   7: printf("Drydock              \n"); break;
			case   8: printf("Shipyard             \n"); break;
			case   9: printf("Town Hall            \n"); break;
			case  10: printf("Town Hall            \n"); break;
			case  11: printf("Town Hall            \n"); break;
			case  12: printf("Schoolhouse          \n"); break;
			case  13: printf("College              \n"); break;
			case  14: printf("University           \n"); break;
			case  15: printf("Warehouse            \n"); break;
			case  16: printf("Warehouse Expansion  \n"); break;
			case  17: printf("Stable               \n"); break;
			case  18: printf("Custom House         \n"); break;
			case  19: printf("Printing Press       \n"); break;
			case  20: printf("Newspaper            \n"); break;
			case  21: printf("Weaver's House       \n"); break;
			case  22: printf("Weaver's Shop        \n"); break;
			case  23: printf("Textile Mill         \n"); break;
			case  24: printf("Tobacconist's House  \n"); break;
			case  25: printf("Tobacconist's Shop   \n"); break;
			case  26: printf("Cigar Factory        \n"); break;
			case  27: printf("Rum Distiller's House\n"); break;
			case  28: printf("Rum Distillery       \n"); break;
			case  29: printf("Rum Factory          \n"); break;
			case  30: printf("Capitol              \n"); break;
			case  31: printf("Capitol Expansion    \n"); break;
			case  32: printf("Fur Trader's House   \n"); break;
			case  33: printf("Fur Trading Post     \n"); break;
			case  34: printf("Fur Factory          \n"); break;
			case  35: printf("Carpenter's Shop     \n"); break;
			case  36: printf("Lumber Mill          \n"); break;
			case  37: printf("Church               \n"); break;
			case  38: printf("Cathedral            \n"); break;
			case  39: printf("Blacksmith's House   \n"); break;
			case  40: printf("Blacksmith's Shop    \n"); break;
			case  41: printf("Iron Works           \n"); break;
			case  42: printf("Artillery            \n"); break;
			case  43: printf("Wagon Train          \n"); break;

			default:  printf("(%3d) unknown\n", colony[i].building_in_production); break;
		}

        print_bytes(colony[i].unknown12,sizeof(colony[i].unknown12));
		printf("\n");

		printf("Stock;\n");
		for (int j = 0; j < 16; ++j)
			printf("  %11s: %3d\n", cargo_name[j], colony[i].stock[j]);
		printf("\n");

        print_bytes(colony[i].unknown13,sizeof(colony[i].unknown13));
		printf("\n");

		printf("rebel ratio: %d/%d = %d\n",
			colony[i].rebel_dividend, colony[i].rebel_divisor,
			(colony[i].rebel_dividend * 100) / colony[i].rebel_divisor);
		printf("\n");

		if (just_this_one != -1)
			break;
	}

	printf("\n");
}

void print_unit(  const struct savegame::unit   *unit,   uint16_t unit_count, int just_this_one)
{
	printf("-- units --\n");

	int start = (just_this_one == -1) ? 0 : just_this_one;

	for (int i = start; i < unit_count; ++i) {
		printf("[%3d] (%3d, %3d): %-19s ", i, unit[i].x, unit[i].y, unit_type_list[unit[i].type]);

		printf("%-11s ", nation_list[unit[i].nation_id] );
        print_bytes(&unit[i].unknown15,sizeof(unit[i].unknown15));
		printf("moves:%02x ", unit[i].moves);
        print_bytes(unit[i].unknown16,sizeof(unit[i].unknown16));
		printf("orders:%02x ", unit[i].orders);
        print_bytes(&unit[i].unknown18,sizeof(unit[i].unknown18));

		assert(unit[i].holds_occupied >= 0 &&
			unit[i].holds_occupied < 7 );

		printf("cargo_holds (%d) : [ %s:%3d, %s:%3d, %s:%3d, %s:%3d, %s:%3d, %s:%3d ]",
			unit[i].holds_occupied,
			(unit[i].holds_occupied > 0) ? cargo_name[unit[i].cargo_item_0] : "", (unit[i].holds_occupied > 0) ? unit[i].cargo_hold[0] : -1,
			(unit[i].holds_occupied > 1) ? cargo_name[unit[i].cargo_item_1] : "", (unit[i].holds_occupied > 1) ? unit[i].cargo_hold[1] : -1,
			(unit[i].holds_occupied > 2) ? cargo_name[unit[i].cargo_item_2] : "", (unit[i].holds_occupied > 2) ? unit[i].cargo_hold[2] : -1,
			(unit[i].holds_occupied > 3) ? cargo_name[unit[i].cargo_item_3] : "", (unit[i].holds_occupied > 3) ? unit[i].cargo_hold[3] : -1,
			(unit[i].holds_occupied > 4) ? cargo_name[unit[i].cargo_item_4] : "", (unit[i].holds_occupied > 4) ? unit[i].cargo_hold[4] : -1,
			(unit[i].holds_occupied > 5) ? cargo_name[unit[i].cargo_item_5] : "", (unit[i].holds_occupied > 5) ? unit[i].cargo_hold[5] : -1);
		printf("worked:%d ", unit[i].turns_worked);

		switch (unit[i].type) {
			case  0: //savegame::unit::COLONIST:
			case  1: //savegame::unit::SOLDIER:
			case  2: //savegame::unit::PIONEER:
			case  3: //savegame::unit::MISSIONARY:
			case  4: //savegame::unit::DRAGOON:
			case  5: //savegame::unit::SCOUT:
			case  7: //savegame::unit::CONTINENTAL_CAVALRY:
			case  9: //savegame::unit::CONTINENTAL_ARMY:
			case 19: //savegame::unit::BRAVE:
				printf("%-22s", profession_list[unit[i].profession]);
				break;
			case 10: //savegame::unit::TREASURE:
				printf("%3d00 gold            ", unit[i].profession);
				break;
			case 13: //savegame::unit::CARAVEL:
			case 14: //savegame::uniT::MERCHANTMAN:
			case 15: //savegame::unit::GALEON:
				printf("%-22s", unit_type_list[unit[i].type]);
				assert(0 == unit[i].profession);
				break;
			default:
				printf("TYPE: %2d PROF: %2d     ", unit[i].type, unit[i].profession);
		}

		printf("next=%3d previous=%3d\n",
			unit[i].transport_chain.next_unit_idx,
			unit[i].transport_chain.prev_unit_idx);

		if (just_this_one != -1)
			break;
	}

	printf("\n");
}

void print_nation(const struct savegame::nation *nation, int just_this_one)
{
	printf("-- nations --\n");

	int start = (just_this_one == -1) ? 0 : just_this_one;

	for (int i = start; i < 4; ++i) {
		printf("[%d] %-11s\n", i, nation_list[i]);
        print_bytes(&nation[i].unknown19,sizeof(nation[i].unknown19));
		printf("\n");
		printf("tax_rate: %2d\n", nation[i].tax_rate);

		for (int j = 0; j < 3; ++j)
			printf("Recruit %d:  %s\n",j,profession_list[ nation[i].recruit[j] ]);
		assert(nation[i].unused07 == 0);

		assert(nation[i].recruit_count <= 180); //does not go above 180
		printf("Recruited: %d\n", nation[i].recruit_count);
        print_bytes(&nation[i].unknown21,sizeof(nation[i].unknown21));
		printf("\n");

		printf("Liberty bells: last_turn=%3d  total=%4d\n",
			nation[i].liberty_bells_last_turn,
			nation[i].liberty_bells_total);
        print_bytes(nation[i].unknown22,sizeof(nation[i].unknown22));
		printf("\n");

		printf("Next founding father: %s\n",(nation[i].next_founding_father == -1)?"none":founding_father_list[nation[i].next_founding_father] );
		printf("Founding fathers: %2d\n", nation[i].founding_father_count);
		assert(nation[i].unused08 == 0);

		printf("Villages burned: %d\n", nation[i].villages_burned);
        print_bytes(nation[i].unknown23,sizeof(nation[i].unknown23));
		printf("\n");

		printf("Artillery purchased: %d\n", nation[i].artillery_count);
		for (int j = 0; j < 16; ++j) {
			printf("%11s boycott: %s\n", cargo_name[j], nation[i].boycott_bitmap & (1 << j) ? "true" : "false");
        }

        print_bytes(nation[i].unknown24,sizeof(nation[i].unknown24));
		printf("\n");

		printf("Gold: %5d, Crosses: %4d of %4d\n",
			nation[i].gold, nation[i].current_crosses, nation[i].needed_crosses);
        
        print_bytes(nation[i].unknown25,sizeof(nation[i].unknown25));
		printf("\n");

		for (int j = 0; j < 8; ++j) {
			printf("Indian status - ");
			printf("%-8s:",indian_list[j]);
			switch (nation[i].relation_by_indian[j]) {
				case savegame::nation::WAR:     printf("war\n");     break;
				case savegame::nation::PEACE:   printf("peace\n");   break;
				case savegame::nation::NOT_MET: printf("not met\n"); break;
				default: printf("unknown (%02x)\n", nation[i].relation_by_indian[j]);
			}
		}
        print_bytes(nation[i].unknown26,sizeof(nation[i].unknown26));
		printf("\n");

		for (int j = 0; j < 16; ++j) {
			printf("%11s ", cargo_name[j]);
			printf("price: %2d, %4d(%08x) nr, %6d gold, %5d tons, %5d tons2\n",
				nation[i].trade.euro_price[j],
				nation[i].trade.nr[j], nation[i].trade.nr[j],
				nation[i].trade.gold[j],
				nation[i].trade.tons[j],
				nation[i].trade.tons2[j]);
			//assert(nation[i].trade.tons[j] == nation[i].trade.tons2[j]); //under which circumstances are these two not equal?
		}

		printf("\n");

		if (just_this_one != -1)
			break;
	}
	printf("\n");
}

void print_tribe(const struct savegame::tribe  *tribe,  uint16_t tribe_count, int just_this_one)
{
	printf("-- tribes --\n");

	int start = (just_this_one == -1) ? 0 : just_this_one;

	for (int i = start; i < tribe_count; ++i) {
		printf("[%3d] (%3d, %3d):%-8s:", i, tribe[i].x, tribe[i].y, nation_list[tribe[i].nation_id]);
        printf("artillery(%d) learned(%d) capital(%d) scouted(%d) ",
            tribe[i].state.artillery, tribe[i].state.learned, tribe[i].state.capital, tribe[i].state.scouted);
        assert(tribe[i].state.unused09==0);
        printf("pop(%02d) mission(%02d) ", tribe[i].population, tribe[i].mission);
        print_bytes(tribe[i].unknown28,sizeof(tribe[i].unknown28));
        
        const char* bought = cargo_name[tribe[i].last_bought];
        const char* sold = cargo_name[tribe[i].last_sold];
        printf("last_bought(%s) last_sold(%s) ", bought, sold);

        for (int j = 0; j < 4; ++j) {
            printf("%.*s[friction(%d),attacks(%d) ", 3, player_list[j], tribe[i].alarm[j].friction,
            tribe[i].alarm[j].attacks);
        }
	    printf("\n");

		if (just_this_one != -1)
			break;
	}
	printf("\n");
}

void print_indian(const struct savegame::indian *indian, int just_this_one)
{
	printf("-- indian --\n");

	int start = (just_this_one == -1) ? 0 : just_this_one;

	for (int i = start; i < 8; ++i) {
        printf("%-8s:",indian_list[i]);
        printf("capitol(%d,%d) tech(%s)", indian[i].capitol_x,indian[i].capitol_y,tech_list[indian[i].tech]);

        printf("\n%9s","");
        print_bytes(indian[i].unknown31,sizeof(indian[i].unknown31));

        printf("\n%9s","");
        for (int j = 0; j < 16; ++j) {
            printf("%s(%d) ", cargo_name[j], indian[i].tons[j]);
        }

        printf("\n%9s","");
        print_bytes(indian[i].unknown32,sizeof(indian[i].unknown32));

        printf("\n%9s","");
        for (int j = 0; j < 4; ++j) {
            printf("%.*s_met(%3d) ", 3,player_list[j],indian[i].met_by_player[j]);
        }
        
        printf("\n%9s","");
        print_bytes(indian[i].unknown33,sizeof(indian[i].unknown33));

        printf("\n%9s","");
        for (int j = 0; j < 4; ++j) {
            printf("%.*s_alarm(%3d) ", 3, player_list[j],indian[i].alarm_by_player[j]);
            assert(indian[i].alarm_by_player[j] <= 255 );
        }
        printf("\n");

		if (just_this_one != -1)
			break;
	}
}

void print_stuff(const struct savegame::stuff *stuff)
{
	printf("-- stuff --\n");

    print_bytes(stuff->unknown34,sizeof(stuff->unknown34));
	printf("\n");

	printf("decreasing_counter: %d\n", stuff->counter_decreasing_on_new_colony);
    print_bytes(stuff->unknown35,sizeof(stuff->unknown35));
	printf("\n");
	printf("increasing_counter: %d\n", stuff->counter_increasing_on_new_colony);

    print_bytes(stuff->unknown36,sizeof(stuff->unknown36));
	printf("\n");

	printf("Active unit: (%3d, %3d)\n", stuff->x, stuff->y);

	printf("Zoom level: ");
	switch (stuff->zoom_level) {
		case 0: printf(" 15 x 12"); break;
		case 1: printf(" 30 x 24"); break;
		case 2: printf(" 60 x 48"); break;
		case 3: printf("120 x 96"); break;
		default:
			printf("UNKNOWN: (%02x)", stuff->zoom_level);
			break;
	}
	printf("\n");

    print_bytes(&stuff->unknown37,sizeof(stuff->unknown37));
	printf("\n");

	printf("Viewport: (%3d, %3d)\n", stuff->viewport_x, stuff->viewport_y);
}

void print_tile(const struct savegame::map *map, int x, int y, int row)
{
    int base = map->tile[x+y*58].base;
    int special = map->tile[x+y*58].special;
    int forest = map->tile[x+y*58].forest;
    int major = map->tile[x+y*58].major;
    int hills = map->tile[x+y*58].hills;
    int river = map->tile[x+y*58].river;
	if (row==0){
        printf("+---------");
    }
	else if (row==1){
        printf("|%2d,%2d  %2d",x,y,map->path[x+y*58].region);
	}
	else if (row==2){
        printf("|%-9s", ( special ? special_name[base] : terrain_name[base] ).c_str() );
	}
	else if (row==3) {
        if (hills) {
            printf("|%-9s",(major?"mountains":"hills"));
        }
        else {
            printf("|%3s%6s",(river?(major?"Mjr":"Mnr"):""),(forest&&!special?"Forest":""));
        }
	}
	else if (row==4){
        printf("%s",map->mask[x+y*58].has_unit?"|unit,":"|    ,");
        printf("%s",map->mask[x+y*58].has_city?"city":"    ");
    }
    else if (row==5){
        printf("%s",map->mask[x+y*58].road?"|road,":"|    ,");
        printf("%s",map->mask[x+y*58].plowed?"plow":"    ");
	}
}

void print_map(const struct savegame::map *map, int x, int y)
{
    if (x != 0 && y != 0) {
		printf("map.tile.%d.%d.full=%02x\n",x,y,map->tile[x+y*58].full);
		printf("map.tile.%d.%d.base=%x\n",x,y,map->tile[x+y*58].base);
		printf("map.tile.%d.%d.forest=%x\n",x,y,map->tile[x+y*58].forest);
		printf("map.tile.%d.%d.special=%x\n",x,y,map->tile[x+y*58].special);
		printf("map.tile.%d.%d.hills=%x\n",x,y,map->tile[x+y*58].hills);
		printf("map.tile.%d.%d.river=%x\n",x,y,map->tile[x+y*58].river);
		printf("map.tile.%d.%d.major=%x\n",x,y,map->tile[x+y*58].major);
		printf("map.mask.%d.%d.full=%02x\n",x,y,map->mask[x+y*58].full);
		printf("map.mask.%d.%d.has_unit=%x\n",x,y,map->mask[x+y*58].has_unit);
		printf("map.mask.%d.%d.has_city=%x\n",x,y,map->mask[x+y*58].has_city);
		printf("map.mask.%d.%d.suppress=%x (hides ocean fish and depletes minerals)\n",x,y,map->mask[x+y*58].suppress);
		printf("map.mask.%d.%d.road=%x\n",x,y,map->mask[x+y*58].road);
		printf("map.mask.%d.%d.purchased=%x (purchased from natives)\n",x,y,map->mask[x+y*58].purchased);
		printf("map.mask.%d.%d.pacific=%x\n",x,y,map->mask[x+y*58].pacific);
		printf("map.mask.%d.%d.plowed=%x\n",x,y,map->mask[x+y*58].plowed);
		printf("map.mask.%d.%d.unused=%x\n",x,y,map->mask[x+y*58].unused);
		printf("map.path.%d.%d.full=%02x\n",x,y,map->path[x+y*58].full);
		printf("map.path.%d.%d.region=%x (ocean or continent id)\n",x,y,map->path[x+y*58].region);
		printf("map.path.%d.%d.visitor=%x (nation list (0-11), 15=unvisted)\n",x,y,map->path[x+y*58].visitor);
		printf("map.seen.%d.%d.full=%02x\n",x,y,map->seen[x+y*58].full);
		printf("map.seen.%d.%d.score=%x (helps AI choose colony sites)\n",x,y,map->seen[x+y*58].score);
		printf("map.seen.%d.%d.english=%x (visible to english)\n",x,y,map->seen[x+y*58].english);
		printf("map.seen.%d.%d.french=%x (visible to french)\n",x,y,map->seen[x+y*58].french);
		printf("map.seen.%d.%d.spanish=%x (visible to spanish)\n",x,y,map->seen[x+y*58].spanish);
		printf("map.seen.%d.%d.dutch=%x (visible to dutch)\n",x,y,map->seen[x+y*58].dutch);
        for (int j = y-2; j <= y+2; ++j) {
		    for (int row = 0; row < 6; row++) {
                for (int i = x-2; i <= x+2; ++i) {
					print_tile(map,i,j,row);
				}
				printf("%s\n",(row==0?"+":"|"));
			}
		}
        for (int i = x-2; i <= x+2; ++i) {
            print_tile(map,0,0,0);
        }
        printf("%s\n","+");
    } 
    else {
 	    printf("-- map.tile\n");
        for (y = 0; y < 72; ++y) {
            for (x = 0; x < 58; ++x) {
                printf("%02x",   map->tile[x + (y * 58)].full);
            }
            printf("\n");
        }
 	    printf("-- map.mask\n");
        for (y = 0; y < 72; ++y) {
            for (x = 0; x < 58; ++x) {
                printf("%02x",   map->mask[x + (y * 58)].full);
            }
            printf("\n");
        }
 	    printf("-- map.path\n");
        for (y = 0; y < 72; ++y) {
            for (x = 0; x < 58; ++x) {
                printf("%02x",   map->path[x + (y * 58)].full);
            }
            printf("\n");
        }
 	    printf("-- map.seen\n");
        for (y = 0; y < 72; ++y) {
            for (x = 0; x < 58; ++x) {
                printf("%02x",   map->seen[x + (y * 58)].full);
            }
            printf("\n");
        }
}
}

void print_tail(const uint8_t *tail)
{
	printf("-- tail --\n");

	for (int i = 0; i < sizeof(tail); ++i) {
		if (i % 20 == 0)
			printf("\n");
		printf("%02x ", tail[i]);
	}
	printf("\n");
}

void dump(void *address, size_t bytes, const char *filename)
{
	FILE *fp = fopen(filename, "w");
	fwrite(address, bytes, 1, fp);
	fclose(fp);
}

// vim: ts=3
