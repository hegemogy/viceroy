// THIS FILE WAS AUTO-GENTERATED FROM savegame.h
// json support, 'using json ...' is for convenience
#include <iostream>
#include <json.hpp>
using json = nlohmann::json;

json json_base();
void print_json(             const struct savegame *sg );

json merge_json_head(        const struct savegame *sg, json j );
json merge_json_other(       const struct savegame *sg, json j );
json merge_json_stuff(       const struct savegame *sg, json j );
json merge_json_tail(        const struct savegame *sg, json j );

json merge_json_player_list( const struct savegame *sg, json j );
json merge_json_nation_list( const struct savegame *sg, json j );
json merge_json_indian_list( const struct savegame *sg, json j );

json merge_json_colony_list( const struct savegame *sg, json j );

/*
json merge_json_unit_list(   const struct savegame *sg, json j );
json merge_json_tribe_list(  const struct savegame *sg, json j );
json merge_json_map(         const struct savegame *sg, json j );
*/

void print_json( const struct savegame *sg )
{
    json j = json_base();

    j = merge_json_head(        sg , j );
    j = merge_json_other(       sg , j );
    j = merge_json_stuff(       sg , j );
    j = merge_json_tail(        sg , j );
    
    j = merge_json_player_list( sg , j );
    j = merge_json_nation_list( sg , j );
    j = merge_json_indian_list( sg , j );

    j = merge_json_colony_list( sg , j );

    std::cout << j.dump(4) << std::endl;

/*
    j = merge_json_unit_list(   sg , j );
    j = merge_json_tribe_list(  sg , j );
    j = merge_json_map(         sg , j );

    std::cout << j.dump(4) << std::endl;
*/

}



json merge_json_head(        const struct savegame *sg, json j )
{
    j["head"]["tribe_count"]["value"] = sg->head.tribe_count;
    j["head"]["numbers02"]["value"] = sg->head.numbers02;
    j["head"]["colony_count"]["value"] = sg->head.colony_count;
    j["head"]["game_options"]["show_indian_moves"]["value"] = sg->head.game_options.show_indian_moves;
    j["head"]["game_options"]["end_of_turn"]["value"] = sg->head.game_options.end_of_turn;
    j["head"]["game_options"]["unknown"]["value"] = sg->head.game_options.unknown;
    j["head"]["game_options"]["tutorial_hints"]["value"] = sg->head.game_options.tutorial_hints;
    j["head"]["game_options"]["unknown7"]["value"] = sg->head.game_options.unknown7;
    j["head"]["game_options"]["fast_piece_slide"]["value"] = sg->head.game_options.fast_piece_slide;
    j["head"]["game_options"]["autosave"]["value"] = sg->head.game_options.autosave;
    j["head"]["game_options"]["combat_analysis"]["value"] = sg->head.game_options.combat_analysis;
    j["head"]["game_options"]["water_color_cycling"]["value"] = sg->head.game_options.water_color_cycling;
    j["head"]["game_options"]["show_foreign_moves"]["value"] = sg->head.game_options.show_foreign_moves;
    j["head"]["sig_colonize"]["value"] = sg->head.sig_colonize;
    j["head"]["autumn"]["value"] = sg->head.autumn;
    j["head"]["numbers03"]["value"] = sg->head.numbers03;
    j["head"]["count_down"]["value"] = sg->head.count_down;
    j["head"]["difficulty"]["value"] = sg->head.difficulty;
    j["head"]["turn"]["value"] = sg->head.turn;
    j["head"]["founding_father"]["value"] = sg->head.founding_father;
    j["head"]["numbers04"]["value"] = sg->head.numbers04;
    j["head"]["nation_relation"]["value"] = sg->head.nation_relation;
    j["head"]["tut3"]["nr7"]["value"] = sg->head.tut3.nr7;
    j["head"]["tut3"]["nr8"]["value"] = sg->head.tut3.nr8;
    j["head"]["tut3"]["nr5"]["value"] = sg->head.tut3.nr5;
    j["head"]["tut3"]["nr11"]["value"] = sg->head.tut3.nr11;
    j["head"]["tut3"]["nr9"]["value"] = sg->head.tut3.nr9;
    j["head"]["tut3"]["nr10"]["value"] = sg->head.tut3.nr10;
    j["head"]["tut3"]["nr6"]["value"] = sg->head.tut3.nr6;
    j["head"]["tut3"]["nr12"]["value"] = sg->head.tut3.nr12;
    j["head"]["unkb"]["value"] = sg->head.unkb;
    j["head"]["numbers05"]["value"] = sg->head.numbers05;
    j["head"]["map_size_y"]["value"] = sg->head.map_size_y;
    j["head"]["year"]["value"] = sg->head.year;
    j["head"]["tut2"]["nr1"]["value"] = sg->head.tut2.nr1;
    j["head"]["tut2"]["event_music"]["value"] = sg->head.tut2.event_music;
    j["head"]["tut2"]["nr4"]["value"] = sg->head.tut2.nr4;
    j["head"]["tut2"]["nr2"]["value"] = sg->head.tut2.nr2;
    j["head"]["tut2"]["howtowin"]["value"] = sg->head.tut2.howtowin;
    j["head"]["tut2"]["nr3"]["value"] = sg->head.tut2.nr3;
    j["head"]["tut2"]["background_music"]["value"] = sg->head.tut2.background_music;
    j["head"]["tut2"]["sound_effects"]["value"] = sg->head.tut2.sound_effects;
    j["head"]["numbers00"]["value"] = sg->head.numbers00;
    j["head"]["numbers06"]["value"] = sg->head.numbers06;
    j["head"]["map_size_x"]["value"] = sg->head.map_size_x;
    j["head"]["unit_count"]["value"] = sg->head.unit_count;
    j["head"]["event"]["the_inca_nation"]["value"] = sg->head.event.the_inca_nation;
    j["head"]["event"]["building_a_colony"]["value"] = sg->head.event.building_a_colony;
    j["head"]["event"]["woodcut15"]["value"] = sg->head.event.woodcut15;
    j["head"]["event"]["the_aztec_empire"]["value"] = sg->head.event.the_aztec_empire;
    j["head"]["event"]["woodcut14"]["value"] = sg->head.event.woodcut14;
    j["head"]["event"]["meeting_fellow_europeans"]["value"] = sg->head.event.meeting_fellow_europeans;
    j["head"]["event"]["indian_raid"]["value"] = sg->head.event.indian_raid;
    j["head"]["event"]["cargo_from_the_new_world"]["value"] = sg->head.event.cargo_from_the_new_world;
    j["head"]["event"]["meeting_the_natives"]["value"] = sg->head.event.meeting_the_natives;
    j["head"]["event"]["colony_destroyed"]["value"] = sg->head.event.colony_destroyed;
    j["head"]["event"]["discovery_of_the_pacific_ocean"]["value"] = sg->head.event.discovery_of_the_pacific_ocean;
    j["head"]["event"]["entering_indian_village"]["value"] = sg->head.event.entering_indian_village;
    j["head"]["event"]["the_fountain_of_youth"]["value"] = sg->head.event.the_fountain_of_youth;
    j["head"]["event"]["woodcut16"]["value"] = sg->head.event.woodcut16;
    j["head"]["event"]["colony_burning"]["value"] = sg->head.event.colony_burning;
    j["head"]["event"]["discovery_of_the_new_world"]["value"] = sg->head.event.discovery_of_the_new_world;
    j["head"]["numbers01"]["value"] = sg->head.numbers01;
    j["head"]["numbers07"]["value"] = sg->head.numbers07;
    j["head"]["unk0"]["value"] = sg->head.unk0;
    j["head"]["colony_report_options"]["report_tools_needed_for_production"]["value"] = sg->head.colony_report_options.report_tools_needed_for_production;
    j["head"]["colony_report_options"]["report_rebel_majorities"]["value"] = uint8_t( sg->head.colony_report_options.report_rebel_majorities );
    j["head"]["colony_report_options"]["report_when_colonists_trained"]["value"] = sg->head.colony_report_options.report_when_colonists_trained;
    j["head"]["colony_report_options"]["report_food_shortages"]["value"] = sg->head.colony_report_options.report_food_shortages;
    j["head"]["colony_report_options"]["labels_on_cargo_and_terrain"]["value"] = sg->head.colony_report_options.labels_on_cargo_and_terrain;
    j["head"]["colony_report_options"]["unused"]["value"] = sg->head.colony_report_options.unused;
    j["head"]["colony_report_options"]["report_sons_of_liberty_membership"]["value"] = sg->head.colony_report_options.report_sons_of_liberty_membership;
    j["head"]["colony_report_options"]["report_inefficient_government"]["value"] = sg->head.colony_report_options.report_inefficient_government;
    j["head"]["colony_report_options"]["report_raw_materials_shortages"]["value"] = sg->head.colony_report_options.report_raw_materials_shortages;
    j["head"]["colony_report_options"]["report_new_cargos_available"]["value"] = sg->head.colony_report_options.report_new_cargos_available;
    j["head"]["colony_report_options"]["labels_on_buildings"]["value"] = uint8_t( sg->head.colony_report_options.labels_on_buildings );
    j["head"]["unk1"]["value"] = sg->head.unk1;
    j["head"]["expeditionary_force"]["value"] = sg->head.expeditionary_force;
    j["head"]["tut1"]["nr17"]["value"] = sg->head.tut1.nr17;
    j["head"]["tut1"]["unk3"]["value"] = sg->head.tut1.unk3;
    j["head"]["tut1"]["unk7"]["value"] = sg->head.tut1.unk7;
    j["head"]["tut1"]["nr13"]["value"] = sg->head.tut1.nr13;
    j["head"]["tut1"]["nr19"]["value"] = sg->head.tut1.nr19;
    j["head"]["tut1"]["nr16"]["value"] = sg->head.tut1.nr16;
    j["head"]["tut1"]["nr14"]["value"] = sg->head.tut1.nr14;
    j["head"]["tut1"]["nr15"]["value"] = sg->head.tut1.nr15;
    j["head"]["active_unit"]["value"] = sg->head.active_unit;
    return j;
}


json merge_json_other(        const struct savegame *sg, json j )
{
    j["other"]["unkXX_xx"]["value"] = sg->other.unkXX_xx;
    return j;
}


json merge_json_stuff(        const struct savegame *sg, json j )
{
    j["stuff"]["unk_short"]["value"] = sg->stuff.unk_short;
    j["stuff"]["x"]["value"] = sg->stuff.x;
    j["stuff"]["unk_big"]["value"] = sg->stuff.unk_big;
    j["stuff"]["counter_increasing_on_new_colony"]["value"] = sg->stuff.counter_increasing_on_new_colony;
    j["stuff"]["viewport_y"]["value"] = sg->stuff.viewport_y;
    j["stuff"]["unk15"]["value"] = sg->stuff.unk15;
    j["stuff"]["counter_decreasing_on_new_colony"]["value"] = sg->stuff.counter_decreasing_on_new_colony;
    j["stuff"]["unk7"]["value"] = sg->stuff.unk7;
    j["stuff"]["zoom_level"]["value"] = sg->stuff.zoom_level;
    j["stuff"]["y"]["value"] = sg->stuff.y;
    j["stuff"]["viewport_x"]["value"] = sg->stuff.viewport_x;
    return j;
}


json merge_json_tail(        const struct savegame *sg, json j )
{
    j["tail"]["unk"]["value"] = sg->tail.unk;
    return j;
}


json merge_json_player_list(   const struct savegame *sg, json j )
{
    json base = j["player"];

    for (int i = 0; i < sg->count.player; ++i) {
        j["player_list"][i] = base;
        
        j["player_list"][i]["diplomacy"]["value"] = sg->player[i].diplomacy;
        j["player_list"][i]["name"]["value"] = sg->player[i].name;
        j["player_list"][i]["country"]["value"] = sg->player[i].country;
        j["player_list"][i]["control"]["value"] = sg->player[i].control;
        j["player_list"][i]["founded_colonies"]["value"] = sg->player[i].founded_colonies;
        j["player_list"][i]["unk00"]["value"] = sg->player[i].unk00;
    }
    return j;
}


json merge_json_nation_list(   const struct savegame *sg, json j )
{
    json base = j["nation"];

    for (int i = 0; i < sg->count.nation; ++i) {
        j["nation_list"][i] = base;
        
        j["nation_list"][i]["founding_father_count"]["value"] = sg->nation[i].founding_father_count;
        j["nation_list"][i]["villages_burned"]["value"] = sg->nation[i].villages_burned;
        j["nation_list"][i]["liberty_bells_last_turn"]["value"] = sg->nation[i].liberty_bells_last_turn;
        j["nation_list"][i]["unk3"]["value"] = sg->nation[i].unk3;
        j["nation_list"][i]["artillery_count"]["value"] = sg->nation[i].artillery_count;
        j["nation_list"][i]["relation_by_indian"]["value"] = sg->nation[i].relation_by_indian;
        j["nation_list"][i]["unk5"]["value"] = sg->nation[i].unk5;
        j["nation_list"][i]["unk7"]["value"] = sg->nation[i].unk7;
        j["nation_list"][i]["unk6"]["value"] = sg->nation[i].unk6;
        j["nation_list"][i]["crosses"]["value"] = sg->nation[i].crosses;
        j["nation_list"][i]["gold"]["value"] = sg->nation[i].gold;
        j["nation_list"][i]["unk4"]["value"] = sg->nation[i].unk4;
        j["nation_list"][i]["tax_rate"]["value"] = sg->nation[i].tax_rate;
        j["nation_list"][i]["unk1"]["value"] = sg->nation[i].unk1;
        j["nation_list"][i]["boycott_bitmap"]["value"] = sg->nation[i].boycott_bitmap;
        j["nation_list"][i]["recruit"]["value"] = sg->nation[i].recruit;
        j["nation_list"][i]["unk2"]["value"] = sg->nation[i].unk2;
        j["nation_list"][i]["unk0"]["value"] = sg->nation[i].unk0;
        j["nation_list"][i]["ffc_high"]["value"] = sg->nation[i].ffc_high;
        j["nation_list"][i]["trade"]["nr"]["value"] = sg->nation[i].trade.nr;
        j["nation_list"][i]["trade"]["tons"]["value"] = sg->nation[i].trade.tons;
        j["nation_list"][i]["trade"]["tons2"]["value"] = sg->nation[i].trade.tons2;
        j["nation_list"][i]["trade"]["gold"]["value"] = sg->nation[i].trade.gold;
        j["nation_list"][i]["trade"]["euro_price"]["value"] = sg->nation[i].trade.euro_price;
        j["nation_list"][i]["recruit_count"]["value"] = sg->nation[i].recruit_count;
        j["nation_list"][i]["liberty_bells_total"]["value"] = sg->nation[i].liberty_bells_total;
        j["nation_list"][i]["next_founding_father"]["value"] = sg->nation[i].next_founding_father;
    }
    return j;
}


json merge_json_indian_list(   const struct savegame *sg, json j )
{
    json base = j["indian"];

    for (int i = 0; i < sg->count.indian; ++i) {
        j["indian_list"][i] = base;
                j["indian_list"][i]["_label"] = indian_list[i];

        j["indian_list"][i]["unk0"]["value"] = sg->indian[i].unk0;
        j["indian_list"][i]["unk1"]["value"] = sg->indian[i].unk1;
        j["indian_list"][i]["alarm_by_player"]["value"] = sg->indian[i].alarm_by_player;
        j["indian_list"][i]["met_by_player"]["value"] = sg->indian[i].met_by_player;
    }
    return j;
}


json merge_json_colony_list(   const struct savegame *sg, json j )
{
    json base = j["colony"];

    for (int i = 0; i < sg->count.colony; ++i) {
        j["colony_list"][i] = base;
        
        j["colony_list"][i]["tiles"]["value"] = sg->colony[i].tiles;
        j["colony_list"][i]["buildings"]["carpenters_shop"]["value"] = uint8_t( sg->colony[i].buildings.carpenters_shop );
        j["colony_list"][i]["buildings"]["armory"]["value"] = uint8_t( sg->colony[i].buildings.armory );
        j["colony_list"][i]["buildings"]["blacksmiths_house"]["value"] = uint8_t( sg->colony[i].buildings.blacksmiths_house );
        j["colony_list"][i]["buildings"]["docks"]["value"] = uint8_t( sg->colony[i].buildings.docks );
        j["colony_list"][i]["buildings"]["custom_house"]["value"] = uint8_t( sg->colony[i].buildings.custom_house );
        j["colony_list"][i]["buildings"]["stockade"]["value"] = uint8_t( sg->colony[i].buildings.stockade );
        j["colony_list"][i]["buildings"]["tobacconists_house"]["value"] = uint8_t( sg->colony[i].buildings.tobacconists_house );
        j["colony_list"][i]["buildings"]["warehouse"]["value"] = uint8_t( sg->colony[i].buildings.warehouse );
        j["colony_list"][i]["buildings"]["stables"]["value"] = uint8_t( sg->colony[i].buildings.stables );
        j["colony_list"][i]["buildings"]["weavers_house"]["value"] = uint8_t( sg->colony[i].buildings.weavers_house );
        j["colony_list"][i]["buildings"]["rum_distillers_house"]["value"] = uint8_t( sg->colony[i].buildings.rum_distillers_house );
        j["colony_list"][i]["buildings"]["fur_traders_house"]["value"] = uint8_t( sg->colony[i].buildings.fur_traders_house );
        j["colony_list"][i]["buildings"]["unused"]["value"] = uint8_t( sg->colony[i].buildings.unused );
        j["colony_list"][i]["buildings"]["church"]["value"] = uint8_t( sg->colony[i].buildings.church );
        j["colony_list"][i]["buildings"]["town_hall"]["value"] = uint8_t( sg->colony[i].buildings.town_hall );
        j["colony_list"][i]["buildings"]["capitol"]["value"] = uint8_t( sg->colony[i].buildings.capitol );
        j["colony_list"][i]["buildings"]["printing_press"]["value"] = uint8_t( sg->colony[i].buildings.printing_press );
        j["colony_list"][i]["buildings"]["schoolhouse"]["value"] = uint8_t( sg->colony[i].buildings.schoolhouse );
        j["colony_list"][i]["unk8"]["value"] = sg->colony[i].unk8;
        j["colony_list"][i]["y"]["value"] = sg->colony[i].y;
        j["colony_list"][i]["unka"]["value"] = sg->colony[i].unka;
        j["colony_list"][i]["hammers"]["value"] = uint8_t( sg->colony[i].hammers );
        j["colony_list"][i]["rebel_dividend"]["value"] = uint8_t( sg->colony[i].rebel_dividend );
        j["colony_list"][i]["unk6"]["value"] = sg->colony[i].unk6;
        uint16_t colony_stock[] = {
			sg->colony[i].stock[0],
			sg->colony[i].stock[1],
			sg->colony[i].stock[2],
			sg->colony[i].stock[3],
			sg->colony[i].stock[4],
			sg->colony[i].stock[5],
			sg->colony[i].stock[6],
			sg->colony[i].stock[7],
			sg->colony[i].stock[8],
			sg->colony[i].stock[9],
			sg->colony[i].stock[10],
			sg->colony[i].stock[11],
			sg->colony[i].stock[12],
			sg->colony[i].stock[13],
			sg->colony[i].stock[14],
			sg->colony[i].stock[15],
		};
		j["colony_list"][i]["stock"]["value"] = colony_stock;
        j["colony_list"][i]["nation"]["value"] = sg->colony[i].nation;
        j["colony_list"][i]["unkb"]["value"] = sg->colony[i].unkb;
        j["colony_list"][i]["population"]["value"] = sg->colony[i].population;
        j["colony_list"][i]["building_in_production"]["value"] = sg->colony[i].building_in_production;
        j["colony_list"][i]["name"]["value"] = sg->colony[i].name;
        j["colony_list"][i]["unkd"]["value"] = sg->colony[i].unkd;
        j["colony_list"][i]["occupation"]["value"] = sg->colony[i].occupation;
        j["colony_list"][i]["unk0"]["value"] = sg->colony[i].unk0;
        j["colony_list"][i]["profession"]["value"] = sg->colony[i].profession;
        j["colony_list"][i]["rebel_divisor"]["value"] = uint8_t( sg->colony[i].rebel_divisor );
        j["colony_list"][i]["custom_house"]["tobacco"]["value"] = uint8_t( sg->colony[i].custom_house.tobacco );
        j["colony_list"][i]["custom_house"]["silver"]["value"] = uint8_t( sg->colony[i].custom_house.silver );
        j["colony_list"][i]["custom_house"]["sugar"]["value"] = uint8_t( sg->colony[i].custom_house.sugar );
        j["colony_list"][i]["custom_house"]["coats"]["value"] = uint8_t( sg->colony[i].custom_house.coats );
        j["colony_list"][i]["custom_house"]["cotton"]["value"] = uint8_t( sg->colony[i].custom_house.cotton );
        j["colony_list"][i]["custom_house"]["lumber"]["value"] = uint8_t( sg->colony[i].custom_house.lumber );
        j["colony_list"][i]["custom_house"]["cloth"]["value"] = uint8_t( sg->colony[i].custom_house.cloth );
        j["colony_list"][i]["custom_house"]["horses"]["value"] = uint8_t( sg->colony[i].custom_house.horses );
        j["colony_list"][i]["custom_house"]["cigars"]["value"] = uint8_t( sg->colony[i].custom_house.cigars );
        j["colony_list"][i]["custom_house"]["muskets"]["value"] = uint8_t( sg->colony[i].custom_house.muskets );
        j["colony_list"][i]["custom_house"]["rum"]["value"] = uint8_t( sg->colony[i].custom_house.rum );
        j["colony_list"][i]["custom_house"]["food"]["value"] = uint8_t( sg->colony[i].custom_house.food );
        j["colony_list"][i]["custom_house"]["tools"]["value"] = uint8_t( sg->colony[i].custom_house.tools );
        j["colony_list"][i]["custom_house"]["furs"]["value"] = uint8_t( sg->colony[i].custom_house.furs );
        j["colony_list"][i]["custom_house"]["ore"]["value"] = uint8_t( sg->colony[i].custom_house.ore );
        j["colony_list"][i]["custom_house"]["trade_goods"]["value"] = uint8_t( sg->colony[i].custom_house.trade_goods );
        j["colony_list"][i]["x"]["value"] = sg->colony[i].x;
    }
    return j;
}


json json_base() {
    auto j = R"(
{
   "stuff" : {
      "unk_short" : {
         "bytes" : {
            "base" : 2,
            "suffix" : 1,
            "total" : 2
         },
         "order" : 225,
         "hints" : ""
      },
      "x" : {
         "hints" : "",
         "order" : 228,
         "bytes" : {
            "base" : 2,
            "suffix" : 1,
            "total" : 2
         }
      },
      "unk_big" : {
         "order" : 227,
         "bytes" : {
            "base" : 1,
            "suffix" : 696,
            "total" : 696
         },
         "hints" : ""
      },
      "counter_increasing_on_new_colony" : {
         "bytes" : {
            "total" : 2,
            "suffix" : 1,
            "base" : 2
         },
         "order" : 226,
         "hints" : ""
      },
      "viewport_y" : {
         "order" : 233,
         "bytes" : {
            "total" : 2,
            "base" : 2,
            "suffix" : 1
         },
         "hints" : ""
      },
      "unk15" : {
         "order" : 223,
         "bytes" : {
            "total" : 15,
            "suffix" : 15,
            "base" : 1
         },
         "hints" : ""
      },
      "counter_decreasing_on_new_colony" : {
         "bytes" : {
            "total" : 2,
            "base" : 2,
            "suffix" : 1
         },
         "order" : 224,
         "hints" : ""
      },
      "unk7" : {
         "bytes" : {
            "total" : 1,
            "suffix" : 1,
            "base" : 1
         },
         "order" : 231,
         "hints" : ""
      },
      "zoom_level" : {
         "hints" : "",
         "order" : 230,
         "bytes" : {
            "base" : 1,
            "suffix" : 1,
            "total" : 1
         }
      },
      "y" : {
         "bytes" : {
            "total" : 2,
            "suffix" : 1,
            "base" : 2
         },
         "order" : 229,
         "hints" : ""
      },
      "viewport_x" : {
         "hints" : "",
         "bytes" : {
            "suffix" : 1,
            "base" : 2,
            "total" : 2
         },
         "order" : 232
      }
   },
   "head" : {
      "tribe_count" : {
         "hints" : "",
         "bytes" : {
            "suffix" : 1,
            "base" : 2,
            "total" : 2
         },
         "order" : 64
      },
      "numbers02" : {
         "hints" : "",
         "bytes" : {
            "base" : 2,
            "suffix" : 3,
            "total" : 6
         },
         "order" : 63
      },
      "colony_count" : {
         "hints" : "",
         "order" : 66,
         "bytes" : {
            "total" : 2,
            "base" : 2,
            "suffix" : 1
         }
      },
      "game_options" : {
         "show_indian_moves" : {
            "hints" : "",
            "order" : 29,
            "bytes" : {
               "base" : 2,
               "suffix" : 1,
               "total" : 2
            }
         },
         "end_of_turn" : {
            "hints" : "",
            "bytes" : {
               "suffix" : 1,
               "base" : 2,
               "total" : 2
            },
            "order" : 25
         },
         "unknown" : {
            "bytes" : {
               "base" : 2,
               "suffix" : 1,
               "total" : 2
            },
            "order" : 27,
            "hints" : ""
         },
         "tutorial_hints" : {
            "hints" : "",
            "bytes" : {
               "base" : 2,
               "suffix" : 1,
               "total" : 2
            },
            "order" : 21
         },
         "unknown7" : {
            "bytes" : {
               "total" : 14,
               "suffix" : 7,
               "base" : 2
            },
            "order" : 20,
            "hints" : ""
         },
         "fast_piece_slide" : {
            "hints" : "",
            "order" : 26,
            "bytes" : {
               "base" : 2,
               "suffix" : 1,
               "total" : 2
            }
         },
         "autosave" : {
            "bytes" : {
               "suffix" : 1,
               "base" : 2,
               "total" : 2
            },
            "order" : 24,
            "hints" : ""
         },
         "combat_analysis" : {
            "bytes" : {
               "total" : 2,
               "suffix" : 1,
               "base" : 2
            },
            "order" : 23,
            "hints" : ""
         },
         "water_color_cycling" : {
            "order" : 22,
            "bytes" : {
               "total" : 2,
               "base" : 2,
               "suffix" : 1
            },
            "hints" : ""
         },
         "show_foreign_moves" : {
            "hints" : "",
            "order" : 28,
            "bytes" : {
               "total" : 2,
               "base" : 2,
               "suffix" : 1
            }
         }
      },
      "sig_colonize" : {
         "hints" : "",
         "order" : 7,
         "bytes" : {
            "total" : 9,
            "suffix" : 9,
            "base" : 1
         }
      },
      "autumn" : {
         "order" : 59,
         "bytes" : {
            "base" : 2,
            "suffix" : 1,
            "total" : 2
         },
         "hints" : " //boolean, true if autumn"
      },
      "numbers03" : {
         "hints" : "",
         "order" : 67,
         "bytes" : {
            "total" : 6,
            "base" : 2,
            "suffix" : 3
         }
      },
      "count_down" : {
         "bytes" : {
            "total" : 32,
            "base" : 2,
            "suffix" : 16
         },
         "order" : 76,
         "hints" : ""
      },
      "difficulty" : {
         "bytes" : {
            "suffix" : 1,
            "base" : 1,
            "total" : 1
         },
         "order" : 68,
         "hints" : " enum { DISCOVERER = 0, EXPLORER = 1, CONQUISTADOR = 2, GOVERNOR = 3, VICEROY = 4 }; //36"
      },
      "turn" : {
         "hints" : "",
         "bytes" : {
            "total" : 2,
            "base" : 2,
            "suffix" : 1
         },
         "order" : 60
      },
      "founding_father" : {
         "hints" : "",
         "order" : 70,
         "bytes" : {
            "total" : 25,
            "suffix" : 25,
            "base" : 1
         }
      },
      "numbers04" : {
         "order" : 69,
         "bytes" : {
            "base" : 2,
            "suffix" : 1,
            "total" : 2
         },
         "hints" : ""
      },
      "nation_relation" : {
         "order" : 72,
         "bytes" : {
            "base" : 2,
            "suffix" : 4,
            "total" : 8
         },
         "hints" : ""
      },
      "tut3" : {
         "nr7" : {
            "bytes" : {
               "base" : 1,
               "suffix" : 1,
               "total" : 1
            },
            "order" : 51,
            "hints" : ""
         },
         "nr8" : {
            "bytes" : {
               "total" : 1,
               "base" : 1,
               "suffix" : 1
            },
            "order" : 52,
            "hints" : ""
         },
         "nr5" : {
            "order" : 49,
            "bytes" : {
               "total" : 1,
               "base" : 1,
               "suffix" : 1
            },
            "hints" : ""
         },
         "nr11" : {
            "hints" : "",
            "bytes" : {
               "total" : 1,
               "base" : 1,
               "suffix" : 1
            },
            "order" : 55
         },
         "nr9" : {
            "bytes" : {
               "total" : 1,
               "base" : 1,
               "suffix" : 1
            },
            "order" : 53,
            "hints" : ""
         },
         "nr10" : {
            "order" : 54,
            "bytes" : {
               "total" : 1,
               "base" : 1,
               "suffix" : 1
            },
            "hints" : ""
         },
         "nr6" : {
            "hints" : "",
            "bytes" : {
               "base" : 1,
               "suffix" : 1,
               "total" : 1
            },
            "order" : 50
         },
         "nr12" : {
            "hints" : "",
            "order" : 56,
            "bytes" : {
               "total" : 1,
               "suffix" : 1,
               "base" : 1
            }
         }
      },
      "unkb" : {
         "hints" : "",
         "bytes" : {
            "base" : 1,
            "suffix" : 2,
            "total" : 2
         },
         "order" : 93
      },
      "numbers05" : {
         "bytes" : {
            "suffix" : 3,
            "base" : 2,
            "total" : 6
         },
         "order" : 71,
         "hints" : ""
      },
      "map_size_y" : {
         "hints" : "",
         "order" : 10,
         "bytes" : {
            "suffix" : 1,
            "base" : 2,
            "total" : 2
         }
      },
      "year" : {
         "hints" : "",
         "order" : 58,
         "bytes" : {
            "total" : 2,
            "base" : 2,
            "suffix" : 1
         }
      },
      "tut2" : {
         "nr1" : {
            "hints" : " // shown immediately on game-start",
            "order" : 45,
            "bytes" : {
               "total" : 1,
               "suffix" : 1,
               "base" : 1
            }
         },
         "event_music" : {
            "bytes" : {
               "suffix" : 1,
               "base" : 1,
               "total" : 1
            },
            "order" : 43,
            "hints" : ""
         },
         "nr4" : {
            "hints" : "",
            "order" : 48,
            "bytes" : {
               "base" : 1,
               "suffix" : 1,
               "total" : 1
            }
         },
         "nr2" : {
            "hints" : " // probably not used, also triggers event_discovery_of_the_new_world",
            "bytes" : {
               "total" : 1,
               "suffix" : 1,
               "base" : 1
            },
            "order" : 46
         },
         "howtowin" : {
            "order" : 41,
            "bytes" : {
               "base" : 1,
               "suffix" : 1,
               "total" : 1
            },
            "hints" : ""
         },
         "nr3" : {
            "bytes" : {
               "base" : 1,
               "suffix" : 1,
               "total" : 1
            },
            "order" : 47,
            "hints" : ""
         },
         "background_music" : {
            "order" : 42,
            "bytes" : {
               "suffix" : 1,
               "base" : 1,
               "total" : 1
            },
            "hints" : ""
         },
         "sound_effects" : {
            "order" : 44,
            "bytes" : {
               "total" : 1,
               "base" : 1,
               "suffix" : 1
            },
            "hints" : ""
         }
      },
      "numbers00" : {
         "bytes" : {
            "suffix" : 1,
            "base" : 2,
            "total" : 2
         },
         "order" : 57,
         "hints" : ""
      },
      "numbers06" : {
         "hints" : "",
         "order" : 73,
         "bytes" : {
            "total" : 10,
            "base" : 2,
            "suffix" : 5
         }
      },
      "map_size_x" : {
         "order" : 9,
         "bytes" : {
            "total" : 2,
            "base" : 2,
            "suffix" : 1
         },
         "hints" : ""
      },
      "unit_count" : {
         "hints" : "",
         "bytes" : {
            "suffix" : 1,
            "base" : 2,
            "total" : 2
         },
         "order" : 65
      },
      "event" : {
         "the_inca_nation" : {
            "hints" : "",
            "order" : 81,
            "bytes" : {
               "total" : 2,
               "suffix" : 1,
               "base" : 2
            }
         },
         "building_a_colony" : {
            "hints" : "",
            "order" : 78,
            "bytes" : {
               "total" : 2,
               "base" : 2,
               "suffix" : 1
            }
         },
         "woodcut15" : {
            "order" : 91,
            "bytes" : {
               "suffix" : 1,
               "base" : 2,
               "total" : 2
            },
            "hints" : ""
         },
         "the_aztec_empire" : {
            "hints" : "",
            "bytes" : {
               "base" : 2,
               "suffix" : 1,
               "total" : 2
            },
            "order" : 80
         },
         "woodcut14" : {
            "hints" : "",
            "order" : 90,
            "bytes" : {
               "suffix" : 1,
               "base" : 2,
               "total" : 2
            }
         },
         "meeting_fellow_europeans" : {
            "order" : 86,
            "bytes" : {
               "total" : 2,
               "suffix" : 1,
               "base" : 2
            },
            "hints" : ""
         },
         "indian_raid" : {
            "order" : 89,
            "bytes" : {
               "total" : 2,
               "suffix" : 1,
               "base" : 2
            },
            "hints" : ""
         },
         "cargo_from_the_new_world" : {
            "order" : 85,
            "bytes" : {
               "base" : 2,
               "suffix" : 1,
               "total" : 2
            },
            "hints" : ""
         },
         "meeting_the_natives" : {
            "bytes" : {
               "total" : 2,
               "base" : 2,
               "suffix" : 1
            },
            "order" : 79,
            "hints" : ""
         },
         "colony_destroyed" : {
            "order" : 88,
            "bytes" : {
               "suffix" : 1,
               "base" : 2,
               "total" : 2
            },
            "hints" : ""
         },
         "discovery_of_the_pacific_ocean" : {
            "order" : 82,
            "bytes" : {
               "suffix" : 1,
               "base" : 2,
               "total" : 2
            },
            "hints" : ""
         },
         "entering_indian_village" : {
            "bytes" : {
               "total" : 2,
               "base" : 2,
               "suffix" : 1
            },
            "order" : 83,
            "hints" : ""
         },
         "the_fountain_of_youth" : {
            "order" : 84,
            "bytes" : {
               "total" : 2,
               "base" : 2,
               "suffix" : 1
            },
            "hints" : ""
         },
         "woodcut16" : {
            "hints" : "",
            "order" : 92,
            "bytes" : {
               "base" : 2,
               "suffix" : 1,
               "total" : 2
            }
         },
         "colony_burning" : {
            "hints" : "",
            "bytes" : {
               "suffix" : 1,
               "base" : 2,
               "total" : 2
            },
            "order" : 87
         },
         "discovery_of_the_new_world" : {
            "hints" : "",
            "bytes" : {
               "total" : 2,
               "suffix" : 1,
               "base" : 2
            },
            "order" : 77
         }
      },
      "numbers01" : {
         "hints" : "",
         "order" : 61,
         "bytes" : {
            "base" : 2,
            "suffix" : 1,
            "total" : 2
         }
      },
      "numbers07" : {
         "bytes" : {
            "total" : 8,
            "base" : 2,
            "suffix" : 4
         },
         "order" : 75,
         "hints" : " //backup force, once you produce enough bells."
      },
      "unk0" : {
         "hints" : "",
         "bytes" : {
            "total" : 3,
            "suffix" : 3,
            "base" : 1
         },
         "order" : 8
      },
      "colony_report_options" : {
         "report_tools_needed_for_production" : {
            "hints" : "",
            "order" : 34,
            "bytes" : {
               "suffix" : 1,
               "base" : 2,
               "total" : 2
            }
         },
         "report_rebel_majorities" : {
            "hints" : "",
            "order" : 39,
            "bytes" : {
               "total" : 2,
               "base" : 2,
               "suffix" : 1
            }
         },
         "report_when_colonists_trained" : {
            "hints" : "",
            "order" : 37,
            "bytes" : {
               "total" : 2,
               "suffix" : 1,
               "base" : 2
            }
         },
         "report_food_shortages" : {
            "hints" : "",
            "order" : 36,
            "bytes" : {
               "total" : 2,
               "base" : 2,
               "suffix" : 1
            }
         },
         "labels_on_cargo_and_terrain" : {
            "order" : 30,
            "bytes" : {
               "base" : 2,
               "suffix" : 1,
               "total" : 2
            },
            "hints" : ""
         },
         "unused" : {
            "bytes" : {
               "suffix" : 6,
               "base" : 2,
               "total" : 12
            },
            "order" : 40,
            "hints" : ""
         },
         "report_sons_of_liberty_membership" : {
            "order" : 38,
            "bytes" : {
               "base" : 2,
               "suffix" : 1,
               "total" : 2
            },
            "hints" : ""
         },
         "report_inefficient_government" : {
            "order" : 33,
            "bytes" : {
               "suffix" : 1,
               "base" : 2,
               "total" : 2
            },
            "hints" : ""
         },
         "report_raw_materials_shortages" : {
            "order" : 35,
            "bytes" : {
               "suffix" : 1,
               "base" : 2,
               "total" : 2
            },
            "hints" : ""
         },
         "report_new_cargos_available" : {
            "hints" : "",
            "bytes" : {
               "total" : 2,
               "base" : 2,
               "suffix" : 1
            },
            "order" : 32
         },
         "labels_on_buildings" : {
            "bytes" : {
               "base" : 2,
               "suffix" : 1,
               "total" : 2
            },
            "order" : 31,
            "hints" : ""
         }
      },
      "unk1" : {
         "order" : 19,
         "bytes" : {
            "suffix" : 1,
            "base" : 1,
            "total" : 1
         },
         "hints" : ""
      },
      "expeditionary_force" : {
         "hints" : "",
         "bytes" : {
            "suffix" : 4,
            "base" : 2,
            "total" : 8
         },
         "order" : 74
      },
      "tut1" : {
         "nr17" : {
            "hints" : "",
            "bytes" : {
               "suffix" : 1,
               "base" : 1,
               "total" : 1
            },
            "order" : 16
         },
         "unk3" : {
            "hints" : "",
            "order" : 13,
            "bytes" : {
               "total" : 1,
               "suffix" : 1,
               "base" : 1
            }
         },
         "unk7" : {
            "hints" : "",
            "order" : 17,
            "bytes" : {
               "total" : 1,
               "base" : 1,
               "suffix" : 1
            }
         },
         "nr13" : {
            "order" : 11,
            "bytes" : {
               "base" : 1,
               "suffix" : 1,
               "total" : 1
            },
            "hints" : ""
         },
         "nr19" : {
            "hints" : "",
            "bytes" : {
               "total" : 1,
               "base" : 1,
               "suffix" : 1
            },
            "order" : 18
         },
         "nr16" : {
            "order" : 15,
            "bytes" : {
               "total" : 1,
               "suffix" : 1,
               "base" : 1
            },
            "hints" : ""
         },
         "nr14" : {
            "bytes" : {
               "base" : 1,
               "suffix" : 1,
               "total" : 1
            },
            "order" : 12,
            "hints" : ""
         },
         "nr15" : {
            "order" : 14,
            "bytes" : {
               "base" : 1,
               "suffix" : 1,
               "total" : 1
            },
            "hints" : ""
         }
      },
      "active_unit" : {
         "hints" : "",
         "order" : 62,
         "bytes" : {
            "total" : 2,
            "base" : 2,
            "suffix" : 1
         }
      }
   },
   "player" : {
      "diplomacy" : {
         "bytes" : {
            "base" : 1,
            "suffix" : 1,
            "total" : 1
         },
         "order" : 99,
         "hints" : ""
      },
      "name" : {
         "hints" : "",
         "bytes" : {
            "total" : 24,
            "base" : 1,
            "suffix" : 24
         },
         "order" : 94
      },
      "country" : {
         "hints" : "",
         "order" : 95,
         "bytes" : {
            "total" : 24,
            "suffix" : 24,
            "base" : 1
         }
      },
      "control" : {
         "bytes" : {
            "total" : 1,
            "base" : 1,
            "suffix" : 1
         },
         "order" : 97,
         "hints" : " enum { PLAYER = 0, AI = 1 };"
      },
      "founded_colonies" : {
         "hints" : " // founded colonies, probably used pick next colony name",
         "order" : 98,
         "bytes" : {
            "suffix" : 1,
            "base" : 1,
            "total" : 1
         }
      },
      "unk00" : {
         "order" : 96,
         "bytes" : {
            "base" : 1,
            "suffix" : 1,
            "total" : 1
         },
         "hints" : ""
      }
   },
   "colony" : {
      "tiles" : {
         "hints" : " //represents tiles around the colony. idx to citizen.",
         "order" : 110,
         "bytes" : {
            "suffix" : 8,
            "base" : 1,
            "total" : 8
         }
      },
      "buildings" : {
         "carpenters_shop" : {
            "order" : 126,
            "bytes" : {
               "base" : 2,
               "suffix" : 2,
               "total" : 4
            },
            "hints" : ""
         },
         "armory" : {
            "bytes" : {
               "suffix" : 3,
               "base" : 4,
               "total" : 12
            },
            "order" : 113,
            "hints" : ""
         },
         "blacksmiths_house" : {
            "order" : 128,
            "bytes" : {
               "total" : 6,
               "suffix" : 3,
               "base" : 2
            },
            "hints" : ""
         },
         "docks" : {
            "hints" : "",
            "bytes" : {
               "suffix" : 3,
               "base" : 4,
               "total" : 12
            },
            "order" : 114
         },
         "custom_house" : {
            "bytes" : {
               "total" : 4,
               "suffix" : 1,
               "base" : 4
            },
            "order" : 119,
            "hints" : ""
         },
         "stockade" : {
            "hints" : "",
            "order" : 112,
            "bytes" : {
               "total" : 12,
               "base" : 4,
               "suffix" : 3
            }
         },
         "tobacconists_house" : {
            "order" : 122,
            "bytes" : {
               "suffix" : 3,
               "base" : 4,
               "total" : 12
            },
            "hints" : ""
         },
         "warehouse" : {
            "hints" : "",
            "order" : 117,
            "bytes" : {
               "total" : 8,
               "suffix" : 2,
               "base" : 4
            }
         },
         "stables" : {
            "hints" : "",
            "bytes" : {
               "base" : 4,
               "suffix" : 1,
               "total" : 4
            },
            "order" : 118
         },
         "weavers_house" : {
            "hints" : "",
            "order" : 121,
            "bytes" : {
               "suffix" : 3,
               "base" : 4,
               "total" : 12
            }
         },
         "rum_distillers_house" : {
            "order" : 123,
            "bytes" : {
               "total" : 12,
               "suffix" : 3,
               "base" : 4
            },
            "hints" : ""
         },
         "fur_traders_house" : {
            "order" : 125,
            "bytes" : {
               "total" : 6,
               "base" : 2,
               "suffix" : 3
            },
            "hints" : ""
         },
         "unused" : {
            "hints" : "",
            "order" : 129,
            "bytes" : {
               "base" : 2,
               "suffix" : 6,
               "total" : 12
            }
         },
         "church" : {
            "bytes" : {
               "base" : 2,
               "suffix" : 2,
               "total" : 4
            },
            "order" : 127,
            "hints" : ""
         },
         "town_hall" : {
            "bytes" : {
               "suffix" : 3,
               "base" : 4,
               "total" : 12
            },
            "order" : 115,
            "hints" : ""
         },
         "capitol" : {
            "hints" : " /* not really in use */",
            "order" : 124,
            "bytes" : {
               "base" : 4,
               "suffix" : 2,
               "total" : 8
            }
         },
         "printing_press" : {
            "order" : 120,
            "bytes" : {
               "total" : 8,
               "suffix" : 2,
               "base" : 4
            },
            "hints" : ""
         },
         "schoolhouse" : {
            "order" : 116,
            "bytes" : {
               "total" : 12,
               "suffix" : 3,
               "base" : 4
            },
            "hints" : ""
         }
      },
      "unk8" : {
         "hints" : "",
         "order" : 111,
         "bytes" : {
            "total" : 12,
            "base" : 1,
            "suffix" : 12
         }
      },
      "y" : {
         "order" : 102,
         "bytes" : {
            "total" : 1,
            "base" : 1,
            "suffix" : 1
         },
         "hints" : ""
      },
      "unka" : {
         "order" : 146,
         "bytes" : {
            "total" : 6,
            "suffix" : 6,
            "base" : 1
         },
         "hints" : ""
      },
      "hammers" : {
         "hints" : "",
         "order" : 147,
         "bytes" : {
            "base" : 2,
            "suffix" : 1,
            "total" : 2
         }
      },
      "rebel_dividend" : {
         "hints" : "",
         "bytes" : {
            "base" : 4,
            "suffix" : 1,
            "total" : 4
         },
         "order" : 152
      },
      "unk6" : {
         "hints" : "",
         "bytes" : {
            "total" : 16,
            "base" : 1,
            "suffix" : 16
         },
         "order" : 109
      },
      "stock" : {
         "order" : 150,
         "bytes" : {
            "suffix" : 16,
            "base" : 2,
            "total" : 32
         },
         "hints" : ""
      },
      "nation" : {
         "bytes" : {
            "suffix" : 1,
            "base" : 1,
            "total" : 1
         },
         "order" : 104,
         "hints" : ""
      },
      "unkb" : {
         "bytes" : {
            "total" : 5,
            "base" : 1,
            "suffix" : 5
         },
         "order" : 149,
         "hints" : ""
      },
      "population" : {
         "hints" : "",
         "bytes" : {
            "total" : 1,
            "suffix" : 1,
            "base" : 1
         },
         "order" : 106
      },
      "building_in_production" : {
         "hints" : "",
         "order" : 148,
         "bytes" : {
            "total" : 1,
            "suffix" : 1,
            "base" : 1
         }
      },
      "name" : {
         "order" : 103,
         "bytes" : {
            "suffix" : 24,
            "base" : 1,
            "total" : 24
         },
         "hints" : ""
      },
      "unkd" : {
         "hints" : "",
         "order" : 151,
         "bytes" : {
            "suffix" : 8,
            "base" : 1,
            "total" : 8
         }
      },
      "occupation" : {
         "hints" : "",
         "order" : 107,
         "bytes" : {
            "total" : 32,
            "base" : 1,
            "suffix" : 32
         }
      },
      "unk0" : {
         "order" : 105,
         "bytes" : {
            "base" : 1,
            "suffix" : 4,
            "total" : 4
         },
         "hints" : ""
      },
      "profession" : {
         "hints" : "",
         "bytes" : {
            "suffix" : 32,
            "base" : 1,
            "total" : 32
         },
         "order" : 108
      },
      "rebel_divisor" : {
         "bytes" : {
            "base" : 4,
            "suffix" : 1,
            "total" : 4
         },
         "order" : 153,
         "hints" : ""
      },
      "custom_house" : {
         "tobacco" : {
            "hints" : "",
            "order" : 132,
            "bytes" : {
               "total" : 2,
               "suffix" : 1,
               "base" : 2
            }
         },
         "silver" : {
            "hints" : "",
            "order" : 137,
            "bytes" : {
               "total" : 2,
               "base" : 2,
               "suffix" : 1
            }
         },
         "sugar" : {
            "hints" : "",
            "order" : 131,
            "bytes" : {
               "suffix" : 1,
               "base" : 2,
               "total" : 2
            }
         },
         "coats" : {
            "hints" : "",
            "order" : 142,
            "bytes" : {
               "total" : 2,
               "suffix" : 1,
               "base" : 2
            }
         },
         "cotton" : {
            "hints" : "",
            "bytes" : {
               "base" : 2,
               "suffix" : 1,
               "total" : 2
            },
            "order" : 133
         },
         "lumber" : {
            "hints" : "",
            "bytes" : {
               "total" : 2,
               "base" : 2,
               "suffix" : 1
            },
            "order" : 135
         },
         "cloth" : {
            "hints" : "",
            "bytes" : {
               "total" : 2,
               "suffix" : 1,
               "base" : 2
            },
            "order" : 141
         },
         "horses" : {
            "hints" : "",
            "order" : 138,
            "bytes" : {
               "total" : 2,
               "base" : 2,
               "suffix" : 1
            }
         },
         "cigars" : {
            "bytes" : {
               "base" : 2,
               "suffix" : 1,
               "total" : 2
            },
            "order" : 140,
            "hints" : ""
         },
         "muskets" : {
            "hints" : "",
            "bytes" : {
               "base" : 2,
               "suffix" : 1,
               "total" : 2
            },
            "order" : 145
         },
         "rum" : {
            "hints" : "",
            "order" : 139,
            "bytes" : {
               "total" : 2,
               "base" : 2,
               "suffix" : 1
            }
         },
         "food" : {
            "bytes" : {
               "base" : 2,
               "suffix" : 1,
               "total" : 2
            },
            "order" : 130,
            "hints" : ""
         },
         "tools" : {
            "hints" : "",
            "bytes" : {
               "base" : 2,
               "suffix" : 1,
               "total" : 2
            },
            "order" : 144
         },
         "furs" : {
            "hints" : "",
            "order" : 134,
            "bytes" : {
               "total" : 2,
               "suffix" : 1,
               "base" : 2
            }
         },
         "ore" : {
            "hints" : "",
            "order" : 136,
            "bytes" : {
               "base" : 2,
               "suffix" : 1,
               "total" : 2
            }
         },
         "trade_goods" : {
            "hints" : "",
            "order" : 143,
            "bytes" : {
               "base" : 2,
               "suffix" : 1,
               "total" : 2
            }
         }
      },
      "x" : {
         "hints" : "",
         "order" : 101,
         "bytes" : {
            "total" : 1,
            "suffix" : 1,
            "base" : 1
         }
      }
   },
   "count" : {
      "nation" : {
         "hints" : "",
         "bytes" : {
            "total" : 2,
            "base" : 2,
            "suffix" : 1
         },
         "order" : 5
      },
      "player" : {
         "hints" : "",
         "bytes" : {
            "base" : 2,
            "suffix" : 1,
            "total" : 2
         },
         "order" : 4
      },
      "unit" : {
         "hints" : "",
         "bytes" : {
            "total" : 2,
            "base" : 2,
            "suffix" : 1
         },
         "order" : 2
      },
      "indian" : {
         "order" : 6,
         "bytes" : {
            "total" : 2,
            "base" : 2,
            "suffix" : 1
         },
         "hints" : ""
      },
      "colony" : {
         "bytes" : {
            "base" : 2,
            "suffix" : 1,
            "total" : 2
         },
         "order" : 1,
         "hints" : ""
      },
      "tribe" : {
         "hints" : "",
         "bytes" : {
            "total" : 2,
            "base" : 2,
            "suffix" : 1
         },
         "order" : 3
      }
   },
   "unit" : {
      "cargo_item_5" : {
         "order" : 170,
         "bytes" : {
            "total" : 4,
            "base" : 1,
            "suffix" : 4
         },
         "hints" : ""
      },
      "order" : {
         "hints" : " enum { PLOW = 8, ROAD = 9 };",
         "bytes" : {
            "base" : 1,
            "suffix" : 1,
            "total" : 1
         },
         "order" : 162
      },
      "holds_occupied" : {
         "hints" : "",
         "bytes" : {
            "base" : 1,
            "suffix" : 1,
            "total" : 1
         },
         "order" : 164
      },
      "x" : {
         "hints" : "",
         "order" : 154,
         "bytes" : {
            "base" : 1,
            "suffix" : 1,
            "total" : 1
         }
      },
      "transport_chain" : {
         "next_unit_idx" : {
            "hints" : "",
            "order" : 174,
            "bytes" : {
               "suffix" : 1,
               "base" : 2,
               "total" : 2
            }
         },
         "prev_unit_idx" : {
            "order" : 175,
            "bytes" : {
               "suffix" : 1,
               "base" : 2,
               "total" : 2
            },
            "hints" : " // index to unit being transported? (treasure) "
         }
      },
      "cargo_item_1" : {
         "bytes" : {
            "suffix" : 4,
            "base" : 1,
            "total" : 4
         },
         "order" : 166,
         "hints" : ""
      },
      "profession" : {
         "bytes" : {
            "total" : 1,
            "suffix" : 1,
            "base" : 1
         },
         "order" : 173,
         "hints" : ""
      },
      "cargo_item_2" : {
         "hints" : "",
         "bytes" : {
            "base" : 1,
            "suffix" : 4,
            "total" : 4
         },
         "order" : 167
      },
      "cargo_hold" : {
         "hints" : "",
         "bytes" : {
            "suffix" : 6,
            "base" : 1,
            "total" : 6
         },
         "order" : 171
      },
      "moves" : {
         "hints" : " /* Accumulated moves (3 between land, 1 on roads, etc.) */",
         "order" : 159,
         "bytes" : {
            "total" : 1,
            "suffix" : 1,
            "base" : 1
         }
      },
      "cargo_item_0" : {
         "bytes" : {
            "total" : 4,
            "base" : 1,
            "suffix" : 4
         },
         "order" : 165,
         "hints" : ""
      },
      "cargo_item_4" : {
         "hints" : "",
         "bytes" : {
            "total" : 4,
            "base" : 1,
            "suffix" : 4
         },
         "order" : 169
      },
      "turns_worked" : {
         "hints" : "",
         "bytes" : {
            "total" : 1,
            "suffix" : 1,
            "base" : 1
         },
         "order" : 172
      },
      "unk08" : {
         "hints" : "",
         "order" : 163,
         "bytes" : {
            "total" : 3,
            "base" : 1,
            "suffix" : 3
         }
      },
      "unk06" : {
         "hints" : "",
         "order" : 160,
         "bytes" : {
            "base" : 1,
            "suffix" : 1,
            "total" : 1
         }
      },
      "unk05" : {
         "hints" : "",
         "bytes" : {
            "suffix" : 1,
            "base" : 1,
            "total" : 1
         },
         "order" : 158
      },
      "cargo_item_3" : {
         "order" : 168,
         "bytes" : {
            "total" : 4,
            "base" : 1,
            "suffix" : 4
         },
         "hints" : ""
      },
      "type" : {
         "bytes" : {
            "total" : 1,
            "suffix" : 1,
            "base" : 1
         },
         "order" : 155,
         "hints" : ""
      },
      "unk07" : {
         "hints" : "",
         "bytes" : {
            "base" : 1,
            "suffix" : 1,
            "total" : 1
         },
         "order" : 161
      },
      "unk04" : {
         "bytes" : {
            "suffix" : 4,
            "base" : 1,
            "total" : 4
         },
         "order" : 157,
         "hints" : ""
      },
      "nation" : {
         "hints" : " /* likely to be owner of unit, eng, fra, spa, dut, indian tribes, etc. */",
         "bytes" : {
            "suffix" : 4,
            "base" : 1,
            "total" : 4
         },
         "order" : 156
      }
   },
   "nation" : {
      "founding_father_count" : {
         "hints" : "",
         "bytes" : {
            "total" : 2,
            "suffix" : 1,
            "base" : 2
         },
         "order" : 186
      },
      "villages_burned" : {
         "hints" : "",
         "order" : 188,
         "bytes" : {
            "base" : 1,
            "suffix" : 1,
            "total" : 1
         }
      },
      "liberty_bells_last_turn" : {
         "hints" : "",
         "bytes" : {
            "suffix" : 1,
            "base" : 2,
            "total" : 2
         },
         "order" : 183
      },
      "unk3" : {
         "hints" : "",
         "bytes" : {
            "total" : 2,
            "base" : 1,
            "suffix" : 2
         },
         "order" : 184
      },
      "artillery_count" : {
         "bytes" : {
            "suffix" : 1,
            "base" : 2,
            "total" : 2
         },
         "order" : 190,
         "hints" : " //artillery purchased in europe. 500 + (count * 100) price penalty."
      },
      "relation_by_indian" : {
         "order" : 196,
         "bytes" : {
            "base" : 1,
            "suffix" : 8,
            "total" : 8
         },
         "hints" : " enum { NOT_MET = 0x00, WAR = 0x20, PEACE = 0x60};"
      },
      "unk5" : {
         "hints" : "",
         "order" : 192,
         "bytes" : {
            "base" : 1,
            "suffix" : 8,
            "total" : 8
         }
      },
      "unk7" : {
         "hints" : "",
         "order" : 197,
         "bytes" : {
            "total" : 12,
            "base" : 1,
            "suffix" : 12
         }
      },
      "unk6" : {
         "hints" : "",
         "order" : 195,
         "bytes" : {
            "base" : 2,
            "suffix" : 4,
            "total" : 8
         }
      },
      "crosses" : {
         "hints" : "",
         "bytes" : {
            "total" : 2,
            "base" : 2,
            "suffix" : 1
         },
         "order" : 194
      },
      "gold" : {
         "bytes" : {
            "total" : 4,
            "base" : 4,
            "suffix" : 1
         },
         "order" : 193,
         "hints" : ""
      },
      "unk4" : {
         "hints" : "",
         "bytes" : {
            "suffix" : 5,
            "base" : 1,
            "total" : 5
         },
         "order" : 189
      },
      "tax_rate" : {
         "bytes" : {
            "total" : 1,
            "base" : 1,
            "suffix" : 1
         },
         "order" : 177,
         "hints" : ""
      },
      "unk1" : {
         "bytes" : {
            "base" : 1,
            "suffix" : 1,
            "total" : 1
         },
         "order" : 179,
         "hints" : ""
      },
      "boycott_bitmap" : {
         "order" : 191,
         "bytes" : {
            "total" : 2,
            "base" : 2,
            "suffix" : 1
         },
         "hints" : ""
      },
      "recruit" : {
         "hints" : "",
         "order" : 178,
         "bytes" : {
            "suffix" : 3,
            "base" : 1,
            "total" : 3
         }
      },
      "unk2" : {
         "hints" : "",
         "bytes" : {
            "total" : 5,
            "suffix" : 5,
            "base" : 1
         },
         "order" : 181
      },
      "unk0" : {
         "order" : 176,
         "bytes" : {
            "base" : 1,
            "suffix" : 1,
            "total" : 1
         },
         "hints" : ""
      },
      "ffc_high" : {
         "hints" : " //suspect founding_father_count is 32bit.",
         "order" : 187,
         "bytes" : {
            "total" : 2,
            "suffix" : 1,
            "base" : 2
         }
      },
      "trade" : {
         "nr" : {
            "hints" : "",
            "bytes" : {
               "total" : 32,
               "base" : 2,
               "suffix" : 16
            },
            "order" : 199
         },
         "tons" : {
            "order" : 201,
            "bytes" : {
               "total" : 64,
               "base" : 4,
               "suffix" : 16
            },
            "hints" : ""
         },
         "tons2" : {
            "bytes" : {
               "total" : 64,
               "base" : 4,
               "suffix" : 16
            },
            "order" : 202,
            "hints" : ""
         },
         "gold" : {
            "hints" : "",
            "bytes" : {
               "total" : 64,
               "base" : 4,
               "suffix" : 16
            },
            "order" : 200
         },
         "euro_price" : {
            "hints" : "",
            "bytes" : {
               "suffix" : 16,
               "base" : 1,
               "total" : 16
            },
            "order" : 198
         }
      },
      "recruit_count" : {
         "hints" : " //recruit penalty 120 + (count * 20) (does not go above 180) ",
         "order" : 180,
         "bytes" : {
            "total" : 1,
            "suffix" : 1,
            "base" : 1
         }
      },
      "liberty_bells_total" : {
         "hints" : "",
         "bytes" : {
            "total" : 2,
            "suffix" : 1,
            "base" : 2
         },
         "order" : 182
      },
      "next_founding_father" : {
         "hints" : "",
         "bytes" : {
            "total" : 2,
            "base" : 2,
            "suffix" : 1
         },
         "order" : 185
      }
   },
   "other" : {
      "unkXX_xx" : {
         "hints" : "",
         "bytes" : {
            "total" : 24,
            "base" : 1,
            "suffix" : 24
         },
         "order" : 100
      }
   },
   "indian" : {
      "unk0" : {
         "hints" : "",
         "order" : 219,
         "bytes" : {
            "total" : 58,
            "base" : 1,
            "suffix" : 58
         }
      },
      "unk1" : {
         "bytes" : {
            "base" : 1,
            "suffix" : 8,
            "total" : 8
         },
         "order" : 221,
         "hints" : " "
      },
      "alarm_by_player" : {
         "bytes" : {
            "base" : 2,
            "suffix" : 4,
            "total" : 8
         },
         "order" : 222,
         "hints" : ""
      },
      "met_by_player" : {
         "hints" : "",
         "order" : 220,
         "bytes" : {
            "suffix" : 4,
            "base" : 1,
            "total" : 4
         }
      }
   },
   "map" : {
      "hints" : "// 56*70 visible + border, = 58*72 = 4176,",
      "order" : 234,
      "bytes" : {
         "suffix" : 4176,
         "base" : 1,
         "total" : 4176
      }
   },
   "tail" : {
      "unk" : {
         "hints" : "",
         "order" : 235,
         "bytes" : {
            "total" : 1502,
            "base" : 1,
            "suffix" : 1502
         }
      }
   },
   "tribe" : {
      "nation" : {
         "hints" : "",
         "bytes" : {
            "total" : 1,
            "suffix" : 1,
            "base" : 1
         },
         "order" : 204
      },
      "state" : {
         "capital" : {
            "order" : 207,
            "bytes" : {
               "total" : 1,
               "base" : 1,
               "suffix" : 1
            },
            "hints" : ""
         },
         "unk6" : {
            "bytes" : {
               "total" : 1,
               "suffix" : 1,
               "base" : 1
            },
            "order" : 210,
            "hints" : ""
         },
         "artillery" : {
            "hints" : " //artillery has been nearby?",
            "bytes" : {
               "total" : 1,
               "suffix" : 1,
               "base" : 1
            },
            "order" : 205
         },
         "unk5" : {
            "hints" : "",
            "order" : 209,
            "bytes" : {
               "base" : 1,
               "suffix" : 1,
               "total" : 1
            }
         },
         "unk7" : {
            "order" : 211,
            "bytes" : {
               "total" : 1,
               "suffix" : 1,
               "base" : 1
            },
            "hints" : ""
         },
         "unk8" : {
            "hints" : "",
            "order" : 212,
            "bytes" : {
               "suffix" : 1,
               "base" : 1,
               "total" : 1
            }
         },
         "learned" : {
            "hints" : " //visited and learned skill",
            "bytes" : {
               "total" : 1,
               "suffix" : 1,
               "base" : 1
            },
            "order" : 206
         },
         "scouted" : {
            "hints" : " //visited by scout",
            "bytes" : {
               "suffix" : 1,
               "base" : 1,
               "total" : 1
            },
            "order" : 208
         }
      },
      "unk2" : {
         "hints" : "",
         "order" : 217,
         "bytes" : {
            "base" : 1,
            "suffix" : 6,
            "total" : 6
         }
      },
      "population" : {
         "hints" : "",
         "order" : 213,
         "bytes" : {
            "total" : 1,
            "base" : 1,
            "suffix" : 1
         }
      },
      "mission" : {
         "hints" : " //ff if none, 0 1 2 3 = eng fra spa dut",
         "order" : 214,
         "bytes" : {
            "total" : 1,
            "suffix" : 1,
            "base" : 1
         }
      },
      "x" : {
         "hints" : "",
         "bytes" : {
            "base" : 1,
            "suffix" : 1,
            "total" : 1
         },
         "order" : 203
      },
      "population_loss_in_current_turn" : {
         "hints" : " //due to attacks",
         "order" : 218,
         "bytes" : {
            "suffix" : 1,
            "base" : 1,
            "total" : 1
         }
      },
      "panic" : {
         "bytes" : {
            "suffix" : 1,
            "base" : 1,
            "total" : 1
         },
         "order" : 216,
         "hints" : ""
      },
      "unk1" : {
         "order" : 215,
         "bytes" : {
            "total" : 4,
            "base" : 1,
            "suffix" : 4
         },
         "hints" : ""
      }
   }
}

    )"_json;
    return j;
}
