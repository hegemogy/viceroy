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
json merge_json_unit_list(   const struct savegame *sg, json j );

/*
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
    j = merge_json_unit_list(   sg , j );

    std::cout << j.dump(4) << std::endl;

/*
    j = merge_json_tribe_list(  sg , j );
    j = merge_json_map(         sg , j );

    std::cout << j.dump(4) << std::endl;
*/

}



json merge_json_head(        const struct savegame *sg, json j )
{
    j["head"]["numbers06"]["value"] = sg->head.numbers06;
    j["head"]["numbers03"]["value"] = sg->head.numbers03;
    j["head"]["count_down"]["value"] = sg->head.count_down;
    j["head"]["sig_colonize"]["value"] = sg->head.sig_colonize;
    j["head"]["game_options"]["autosave"]["value"] = sg->head.game_options.autosave;
    j["head"]["game_options"]["fast_piece_slide"]["value"] = sg->head.game_options.fast_piece_slide;
    j["head"]["game_options"]["combat_analysis"]["value"] = sg->head.game_options.combat_analysis;
    j["head"]["game_options"]["show_indian_moves"]["value"] = sg->head.game_options.show_indian_moves;
    j["head"]["game_options"]["unknown"]["value"] = sg->head.game_options.unknown;
    j["head"]["game_options"]["water_color_cycling"]["value"] = sg->head.game_options.water_color_cycling;
    j["head"]["game_options"]["show_foreign_moves"]["value"] = sg->head.game_options.show_foreign_moves;
    j["head"]["game_options"]["tutorial_hints"]["value"] = sg->head.game_options.tutorial_hints;
    j["head"]["game_options"]["unknown7"]["value"] = sg->head.game_options.unknown7;
    j["head"]["game_options"]["end_of_turn"]["value"] = sg->head.game_options.end_of_turn;
    j["head"]["unk0"]["value"] = sg->head.unk0;
    j["head"]["tut3"]["nr6"]["value"] = sg->head.tut3.nr6;
    j["head"]["tut3"]["nr12"]["value"] = sg->head.tut3.nr12;
    j["head"]["tut3"]["nr5"]["value"] = sg->head.tut3.nr5;
    j["head"]["tut3"]["nr8"]["value"] = sg->head.tut3.nr8;
    j["head"]["tut3"]["nr9"]["value"] = sg->head.tut3.nr9;
    j["head"]["tut3"]["nr10"]["value"] = sg->head.tut3.nr10;
    j["head"]["tut3"]["nr7"]["value"] = sg->head.tut3.nr7;
    j["head"]["tut3"]["nr11"]["value"] = sg->head.tut3.nr11;
    j["head"]["tut1"]["unk3"]["value"] = sg->head.tut1.unk3;
    j["head"]["tut1"]["nr13"]["value"] = sg->head.tut1.nr13;
    j["head"]["tut1"]["nr15"]["value"] = sg->head.tut1.nr15;
    j["head"]["tut1"]["unk7"]["value"] = sg->head.tut1.unk7;
    j["head"]["tut1"]["nr14"]["value"] = sg->head.tut1.nr14;
    j["head"]["tut1"]["nr17"]["value"] = sg->head.tut1.nr17;
    j["head"]["tut1"]["nr19"]["value"] = sg->head.tut1.nr19;
    j["head"]["tut1"]["nr16"]["value"] = sg->head.tut1.nr16;
    j["head"]["tut2"]["event_music"]["value"] = sg->head.tut2.event_music;
    j["head"]["tut2"]["sound_effects"]["value"] = sg->head.tut2.sound_effects;
    j["head"]["tut2"]["howtowin"]["value"] = sg->head.tut2.howtowin;
    j["head"]["tut2"]["nr4"]["value"] = sg->head.tut2.nr4;
    j["head"]["tut2"]["background_music"]["value"] = sg->head.tut2.background_music;
    j["head"]["tut2"]["nr3"]["value"] = sg->head.tut2.nr3;
    j["head"]["tut2"]["nr1"]["value"] = sg->head.tut2.nr1;
    j["head"]["tut2"]["nr2"]["value"] = sg->head.tut2.nr2;
    j["head"]["active_unit"]["value"] = sg->head.active_unit;
    j["head"]["unkb"]["value"] = sg->head.unkb;
    j["head"]["turn"]["value"] = sg->head.turn;
    j["head"]["colony_report_options"]["report_sons_of_liberty_membership"]["value"] = sg->head.colony_report_options.report_sons_of_liberty_membership;
    j["head"]["colony_report_options"]["report_when_colonists_trained"]["value"] = sg->head.colony_report_options.report_when_colonists_trained;
    j["head"]["colony_report_options"]["report_inefficient_government"]["value"] = sg->head.colony_report_options.report_inefficient_government;
    j["head"]["colony_report_options"]["labels_on_buildings"]["value"] = uint16_t( sg->head.colony_report_options.labels_on_buildings );
    j["head"]["colony_report_options"]["report_food_shortages"]["value"] = sg->head.colony_report_options.report_food_shortages;
    j["head"]["colony_report_options"]["report_new_cargos_available"]["value"] = sg->head.colony_report_options.report_new_cargos_available;
    j["head"]["colony_report_options"]["unused"]["value"] = sg->head.colony_report_options.unused;
    j["head"]["colony_report_options"]["report_raw_materials_shortages"]["value"] = sg->head.colony_report_options.report_raw_materials_shortages;
    j["head"]["colony_report_options"]["labels_on_cargo_and_terrain"]["value"] = sg->head.colony_report_options.labels_on_cargo_and_terrain;
    j["head"]["colony_report_options"]["report_tools_needed_for_production"]["value"] = sg->head.colony_report_options.report_tools_needed_for_production;
    j["head"]["colony_report_options"]["report_rebel_majorities"]["value"] = uint16_t( sg->head.colony_report_options.report_rebel_majorities );
    j["head"]["unk1"]["value"] = sg->head.unk1;
    j["head"]["colony_count"]["value"] = sg->head.colony_count;
    j["head"]["numbers00"]["value"] = sg->head.numbers00;
    j["head"]["year"]["value"] = sg->head.year;
    j["head"]["event"]["the_fountain_of_youth"]["value"] = sg->head.event.the_fountain_of_youth;
    j["head"]["event"]["woodcut15"]["value"] = sg->head.event.woodcut15;
    j["head"]["event"]["indian_raid"]["value"] = sg->head.event.indian_raid;
    j["head"]["event"]["woodcut16"]["value"] = sg->head.event.woodcut16;
    j["head"]["event"]["meeting_fellow_europeans"]["value"] = sg->head.event.meeting_fellow_europeans;
    j["head"]["event"]["colony_burning"]["value"] = sg->head.event.colony_burning;
    j["head"]["event"]["meeting_the_natives"]["value"] = sg->head.event.meeting_the_natives;
    j["head"]["event"]["woodcut14"]["value"] = sg->head.event.woodcut14;
    j["head"]["event"]["entering_indian_village"]["value"] = sg->head.event.entering_indian_village;
    j["head"]["event"]["the_aztec_empire"]["value"] = sg->head.event.the_aztec_empire;
    j["head"]["event"]["building_a_colony"]["value"] = sg->head.event.building_a_colony;
    j["head"]["event"]["cargo_from_the_new_world"]["value"] = sg->head.event.cargo_from_the_new_world;
    j["head"]["event"]["discovery_of_the_new_world"]["value"] = sg->head.event.discovery_of_the_new_world;
    j["head"]["event"]["colony_destroyed"]["value"] = sg->head.event.colony_destroyed;
    j["head"]["event"]["the_inca_nation"]["value"] = sg->head.event.the_inca_nation;
    j["head"]["event"]["discovery_of_the_pacific_ocean"]["value"] = sg->head.event.discovery_of_the_pacific_ocean;
    j["head"]["numbers05"]["value"] = sg->head.numbers05;
    j["head"]["nation_relation"]["value"] = sg->head.nation_relation;
    j["head"]["tribe_count"]["value"] = sg->head.tribe_count;
    j["head"]["unit_count"]["value"] = sg->head.unit_count;
    j["head"]["numbers04"]["value"] = sg->head.numbers04;
    j["head"]["expeditionary_force"]["value"] = sg->head.expeditionary_force;
    j["head"]["founding_father"]["value"] = sg->head.founding_father;
    j["head"]["map_size_y"]["value"] = sg->head.map_size_y;
    j["head"]["numbers01"]["value"] = sg->head.numbers01;
    j["head"]["autumn"]["value"] = sg->head.autumn;
    j["head"]["map_size_x"]["value"] = sg->head.map_size_x;
    j["head"]["difficulty"]["value"] = sg->head.difficulty;
    j["head"]["numbers02"]["value"] = sg->head.numbers02;
    j["head"]["numbers07"]["value"] = sg->head.numbers07;
    return j;
}


json merge_json_other(        const struct savegame *sg, json j )
{
    j["other"]["unkXX_xx"]["value"] = sg->other.unkXX_xx;
    return j;
}


json merge_json_stuff(        const struct savegame *sg, json j )
{
    j["stuff"]["unk7"]["value"] = sg->stuff.unk7;
    j["stuff"]["zoom_level"]["value"] = sg->stuff.zoom_level;
    j["stuff"]["unk15"]["value"] = sg->stuff.unk15;
    j["stuff"]["viewport_y"]["value"] = sg->stuff.viewport_y;
    j["stuff"]["counter_decreasing_on_new_colony"]["value"] = sg->stuff.counter_decreasing_on_new_colony;
    j["stuff"]["unk_big"]["value"] = sg->stuff.unk_big;
    j["stuff"]["viewport_x"]["value"] = sg->stuff.viewport_x;
    j["stuff"]["counter_increasing_on_new_colony"]["value"] = sg->stuff.counter_increasing_on_new_colony;
    j["stuff"]["unk_short"]["value"] = sg->stuff.unk_short;
    j["stuff"]["y"]["value"] = sg->stuff.y;
    j["stuff"]["x"]["value"] = sg->stuff.x;
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
        
        j["player_list"][i]["founded_colonies"]["value"] = sg->player[i].founded_colonies;
        j["player_list"][i]["unk00"]["value"] = sg->player[i].unk00;
        j["player_list"][i]["control"]["value"] = sg->player[i].control;
        j["player_list"][i]["diplomacy"]["value"] = sg->player[i].diplomacy;
        j["player_list"][i]["name"]["value"] = sg->player[i].name;
        j["player_list"][i]["country"]["value"] = sg->player[i].country;
    }
    return j;
}


json merge_json_nation_list(   const struct savegame *sg, json j )
{
    json base = j["nation"];

    for (int i = 0; i < sg->count.nation; ++i) {
        j["nation_list"][i] = base;
        
        j["nation_list"][i]["trade"]["tons"]["value"] = sg->nation[i].trade.tons;
        j["nation_list"][i]["trade"]["gold"]["value"] = sg->nation[i].trade.gold;
        j["nation_list"][i]["trade"]["tons2"]["value"] = sg->nation[i].trade.tons2;
        j["nation_list"][i]["trade"]["nr"]["value"] = sg->nation[i].trade.nr;
        j["nation_list"][i]["trade"]["euro_price"]["value"] = sg->nation[i].trade.euro_price;
        j["nation_list"][i]["relation_by_indian"]["value"] = sg->nation[i].relation_by_indian;
        j["nation_list"][i]["unk6"]["value"] = sg->nation[i].unk6;
        j["nation_list"][i]["unk7"]["value"] = sg->nation[i].unk7;
        j["nation_list"][i]["gold"]["value"] = sg->nation[i].gold;
        j["nation_list"][i]["tax_rate"]["value"] = sg->nation[i].tax_rate;
        j["nation_list"][i]["crosses"]["value"] = sg->nation[i].crosses;
        j["nation_list"][i]["recruit_count"]["value"] = sg->nation[i].recruit_count;
        j["nation_list"][i]["founding_father_count"]["value"] = sg->nation[i].founding_father_count;
        j["nation_list"][i]["unk1"]["value"] = sg->nation[i].unk1;
        j["nation_list"][i]["recruit"]["value"] = sg->nation[i].recruit;
        j["nation_list"][i]["boycott_bitmap"]["value"] = sg->nation[i].boycott_bitmap;
        j["nation_list"][i]["unk4"]["value"] = sg->nation[i].unk4;
        j["nation_list"][i]["unk3"]["value"] = sg->nation[i].unk3;
        j["nation_list"][i]["liberty_bells_last_turn"]["value"] = sg->nation[i].liberty_bells_last_turn;
        j["nation_list"][i]["unk5"]["value"] = sg->nation[i].unk5;
        j["nation_list"][i]["liberty_bells_total"]["value"] = sg->nation[i].liberty_bells_total;
        j["nation_list"][i]["artillery_count"]["value"] = sg->nation[i].artillery_count;
        j["nation_list"][i]["unk2"]["value"] = sg->nation[i].unk2;
        j["nation_list"][i]["next_founding_father"]["value"] = sg->nation[i].next_founding_father;
        j["nation_list"][i]["ffc_high"]["value"] = sg->nation[i].ffc_high;
        j["nation_list"][i]["villages_burned"]["value"] = sg->nation[i].villages_burned;
        j["nation_list"][i]["unk0"]["value"] = sg->nation[i].unk0;
    }
    return j;
}


json merge_json_indian_list(   const struct savegame *sg, json j )
{
    json base = j["indian"];

    for (int i = 0; i < sg->count.indian; ++i) {
        j["indian_list"][i] = base;
                j["indian_list"][i]["_label"] = indian_list[i];

        j["indian_list"][i]["alarm_by_player"]["value"] = sg->indian[i].alarm_by_player;
        j["indian_list"][i]["unk0"]["value"] = sg->indian[i].unk0;
        j["indian_list"][i]["unk1"]["value"] = sg->indian[i].unk1;
        j["indian_list"][i]["met_by_player"]["value"] = sg->indian[i].met_by_player;
    }
    return j;
}


json merge_json_colony_list(   const struct savegame *sg, json j )
{
    json base = j["colony"];

    for (int i = 0; i < sg->count.colony; ++i) {
        j["colony_list"][i] = base;
        
        j["colony_list"][i]["y"]["value"] = sg->colony[i].y;
        j["colony_list"][i]["x"]["value"] = sg->colony[i].x;
        j["colony_list"][i]["rebel_divisor"]["value"] = uint16_t( sg->colony[i].rebel_divisor );
        j["colony_list"][i]["unkd"]["value"] = sg->colony[i].unkd;
        j["colony_list"][i]["population"]["value"] = sg->colony[i].population;
        j["colony_list"][i]["hammers"]["value"] = uint16_t( sg->colony[i].hammers );
        j["colony_list"][i]["occupation"]["value"] = sg->colony[i].occupation;
        j["colony_list"][i]["custom_house"]["coats"]["value"] = uint16_t( sg->colony[i].custom_house.coats );
        j["colony_list"][i]["custom_house"]["food"]["value"] = uint16_t( sg->colony[i].custom_house.food );
        j["colony_list"][i]["custom_house"]["muskets"]["value"] = uint16_t( sg->colony[i].custom_house.muskets );
        j["colony_list"][i]["custom_house"]["ore"]["value"] = uint16_t( sg->colony[i].custom_house.ore );
        j["colony_list"][i]["custom_house"]["sugar"]["value"] = uint16_t( sg->colony[i].custom_house.sugar );
        j["colony_list"][i]["custom_house"]["lumber"]["value"] = uint16_t( sg->colony[i].custom_house.lumber );
        j["colony_list"][i]["custom_house"]["cotton"]["value"] = uint16_t( sg->colony[i].custom_house.cotton );
        j["colony_list"][i]["custom_house"]["cigars"]["value"] = uint16_t( sg->colony[i].custom_house.cigars );
        j["colony_list"][i]["custom_house"]["tools"]["value"] = uint16_t( sg->colony[i].custom_house.tools );
        j["colony_list"][i]["custom_house"]["furs"]["value"] = uint16_t( sg->colony[i].custom_house.furs );
        j["colony_list"][i]["custom_house"]["trade_goods"]["value"] = uint16_t( sg->colony[i].custom_house.trade_goods );
        j["colony_list"][i]["custom_house"]["cloth"]["value"] = uint16_t( sg->colony[i].custom_house.cloth );
        j["colony_list"][i]["custom_house"]["horses"]["value"] = uint16_t( sg->colony[i].custom_house.horses );
        j["colony_list"][i]["custom_house"]["silver"]["value"] = uint16_t( sg->colony[i].custom_house.silver );
        j["colony_list"][i]["custom_house"]["rum"]["value"] = uint16_t( sg->colony[i].custom_house.rum );
        j["colony_list"][i]["custom_house"]["tobacco"]["value"] = uint16_t( sg->colony[i].custom_house.tobacco );
        j["colony_list"][i]["profession"]["value"] = sg->colony[i].profession;
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
        j["colony_list"][i]["tiles"]["value"] = sg->colony[i].tiles;
        j["colony_list"][i]["unk0"]["value"] = sg->colony[i].unk0;
        j["colony_list"][i]["rebel_dividend"]["value"] = uint16_t( sg->colony[i].rebel_dividend );
        j["colony_list"][i]["building_in_production"]["value"] = sg->colony[i].building_in_production;
        j["colony_list"][i]["unkb"]["value"] = sg->colony[i].unkb;
        j["colony_list"][i]["unk6"]["value"] = sg->colony[i].unk6;
        j["colony_list"][i]["unk8"]["value"] = sg->colony[i].unk8;
        j["colony_list"][i]["name"]["value"] = sg->colony[i].name;
        j["colony_list"][i]["buildings"]["church"]["value"] = uint16_t( sg->colony[i].buildings.church );
        j["colony_list"][i]["buildings"]["town_hall"]["value"] = uint16_t( sg->colony[i].buildings.town_hall );
        j["colony_list"][i]["buildings"]["armory"]["value"] = uint16_t( sg->colony[i].buildings.armory );
        j["colony_list"][i]["buildings"]["docks"]["value"] = uint16_t( sg->colony[i].buildings.docks );
        j["colony_list"][i]["buildings"]["stockade"]["value"] = uint16_t( sg->colony[i].buildings.stockade );
        j["colony_list"][i]["buildings"]["schoolhouse"]["value"] = uint16_t( sg->colony[i].buildings.schoolhouse );
        j["colony_list"][i]["buildings"]["capitol"]["value"] = uint16_t( sg->colony[i].buildings.capitol );
        j["colony_list"][i]["buildings"]["custom_house"]["value"] = uint16_t( sg->colony[i].buildings.custom_house );
        j["colony_list"][i]["buildings"]["warehouse"]["value"] = uint16_t( sg->colony[i].buildings.warehouse );
        j["colony_list"][i]["buildings"]["blacksmiths_house"]["value"] = uint16_t( sg->colony[i].buildings.blacksmiths_house );
        j["colony_list"][i]["buildings"]["unused"]["value"] = uint16_t( sg->colony[i].buildings.unused );
        j["colony_list"][i]["buildings"]["weavers_house"]["value"] = uint16_t( sg->colony[i].buildings.weavers_house );
        j["colony_list"][i]["buildings"]["tobacconists_house"]["value"] = uint16_t( sg->colony[i].buildings.tobacconists_house );
        j["colony_list"][i]["buildings"]["rum_distillers_house"]["value"] = uint16_t( sg->colony[i].buildings.rum_distillers_house );
        j["colony_list"][i]["buildings"]["carpenters_shop"]["value"] = uint16_t( sg->colony[i].buildings.carpenters_shop );
        j["colony_list"][i]["buildings"]["stables"]["value"] = uint16_t( sg->colony[i].buildings.stables );
        j["colony_list"][i]["buildings"]["fur_traders_house"]["value"] = uint16_t( sg->colony[i].buildings.fur_traders_house );
        j["colony_list"][i]["buildings"]["printing_press"]["value"] = uint16_t( sg->colony[i].buildings.printing_press );
        j["colony_list"][i]["unka"]["value"] = sg->colony[i].unka;
        j["colony_list"][i]["nation"]["value"] = sg->colony[i].nation;
    }
    return j;
}


json merge_json_unit_list(   const struct savegame *sg, json j )
{
    json base = j["unit"];

    for (int i = 0; i < sg->count.unit; ++i) {
        j["unit_list"][i] = base;
        
        j["unit_list"][i]["transport_chain"]["prev_unit_idx"]["value"] = uint16_t( sg->unit[i].transport_chain.prev_unit_idx );
        j["unit_list"][i]["transport_chain"]["next_unit_idx"]["value"] = uint16_t( sg->unit[i].transport_chain.next_unit_idx );
        j["unit_list"][i]["profession"]["value"] = sg->unit[i].profession;
        j["unit_list"][i]["cargo_item_5"]["value"] = uint16_t( sg->unit[i].cargo_item_5 );
        j["unit_list"][i]["unk06"]["value"] = sg->unit[i].unk06;
        j["unit_list"][i]["cargo_item_0"]["value"] = uint16_t( sg->unit[i].cargo_item_0 );
        j["unit_list"][i]["x"]["value"] = sg->unit[i].x;
        j["unit_list"][i]["cargo_item_2"]["value"] = uint16_t( sg->unit[i].cargo_item_2 );
        j["unit_list"][i]["type"]["value"] = sg->unit[i].type;
        j["unit_list"][i]["nation"]["value"] = uint16_t( sg->unit[i].nation );
        j["unit_list"][i]["turns_worked"]["value"] = sg->unit[i].turns_worked;
        j["unit_list"][i]["unk05"]["value"] = sg->unit[i].unk05;
        j["unit_list"][i]["order"]["value"] = sg->unit[i].order;
        j["unit_list"][i]["unk08"]["value"] = sg->unit[i].unk08;
        j["unit_list"][i]["cargo_item_4"]["value"] = uint16_t( sg->unit[i].cargo_item_4 );
        j["unit_list"][i]["holds_occupied"]["value"] = sg->unit[i].holds_occupied;
        j["unit_list"][i]["unk07"]["value"] = sg->unit[i].unk07;
        j["unit_list"][i]["moves"]["value"] = sg->unit[i].moves;
        j["unit_list"][i]["cargo_hold"]["value"] = sg->unit[i].cargo_hold;
        j["unit_list"][i]["unk04"]["value"] = uint16_t( sg->unit[i].unk04 );
        j["unit_list"][i]["cargo_item_1"]["value"] = uint16_t( sg->unit[i].cargo_item_1 );
        j["unit_list"][i]["cargo_item_3"]["value"] = uint16_t( sg->unit[i].cargo_item_3 );
    }
    return j;
}


json json_base() {
    auto j = R"(
{
   "indian" : {
      "alarm_by_player" : {
         "order" : 222,
         "hints" : "",
         "bytes" : {
            "base" : 2,
            "total" : 8,
            "suffix" : 4
         }
      },
      "unk0" : {
         "bytes" : {
            "suffix" : 58,
            "base" : 1,
            "total" : 58
         },
         "hints" : "",
         "order" : 219
      },
      "unk1" : {
         "order" : 221,
         "hints" : " ",
         "bytes" : {
            "total" : 8,
            "base" : 1,
            "suffix" : 8
         }
      },
      "met_by_player" : {
         "bytes" : {
            "suffix" : 4,
            "base" : 1,
            "total" : 4
         },
         "hints" : "",
         "order" : 220
      }
   },
   "map" : {
      "hints" : "// 56*70 visible + border, = 58*72 = 4176,",
      "order" : 234,
      "bytes" : {
         "total" : 4176,
         "base" : 1,
         "suffix" : 4176
      }
   },
   "stuff" : {
      "unk7" : {
         "bytes" : {
            "base" : 1,
            "total" : 1,
            "suffix" : 1
         },
         "hints" : "",
         "order" : 231
      },
      "zoom_level" : {
         "order" : 230,
         "hints" : "",
         "bytes" : {
            "base" : 1,
            "total" : 1,
            "suffix" : 1
         }
      },
      "unk15" : {
         "hints" : "",
         "order" : 223,
         "bytes" : {
            "suffix" : 15,
            "base" : 1,
            "total" : 15
         }
      },
      "viewport_y" : {
         "bytes" : {
            "suffix" : 1,
            "base" : 2,
            "total" : 2
         },
         "hints" : "",
         "order" : 233
      },
      "counter_decreasing_on_new_colony" : {
         "bytes" : {
            "base" : 2,
            "total" : 2,
            "suffix" : 1
         },
         "order" : 224,
         "hints" : ""
      },
      "unk_big" : {
         "order" : 227,
         "hints" : "",
         "bytes" : {
            "suffix" : 696,
            "total" : 696,
            "base" : 1
         }
      },
      "viewport_x" : {
         "order" : 232,
         "hints" : "",
         "bytes" : {
            "suffix" : 1,
            "total" : 2,
            "base" : 2
         }
      },
      "counter_increasing_on_new_colony" : {
         "order" : 226,
         "hints" : "",
         "bytes" : {
            "suffix" : 1,
            "base" : 2,
            "total" : 2
         }
      },
      "unk_short" : {
         "bytes" : {
            "suffix" : 1,
            "base" : 2,
            "total" : 2
         },
         "order" : 225,
         "hints" : ""
      },
      "y" : {
         "order" : 229,
         "hints" : "",
         "bytes" : {
            "base" : 2,
            "total" : 2,
            "suffix" : 1
         }
      },
      "x" : {
         "bytes" : {
            "base" : 2,
            "total" : 2,
            "suffix" : 1
         },
         "order" : 228,
         "hints" : ""
      }
   },
   "head" : {
      "numbers06" : {
         "hints" : "",
         "order" : 73,
         "bytes" : {
            "suffix" : 5,
            "total" : 10,
            "base" : 2
         }
      },
      "numbers03" : {
         "bytes" : {
            "total" : 6,
            "base" : 2,
            "suffix" : 3
         },
         "order" : 67,
         "hints" : ""
      },
      "count_down" : {
         "bytes" : {
            "suffix" : 16,
            "total" : 32,
            "base" : 2
         },
         "order" : 76,
         "hints" : ""
      },
      "sig_colonize" : {
         "hints" : "",
         "order" : 7,
         "bytes" : {
            "suffix" : 9,
            "base" : 1,
            "total" : 9
         }
      },
      "game_options" : {
         "autosave" : {
            "bytes" : {
               "total" : 2,
               "base" : 2,
               "suffix" : 1
            },
            "hints" : "",
            "order" : 24
         },
         "fast_piece_slide" : {
            "order" : 26,
            "hints" : "",
            "bytes" : {
               "total" : 2,
               "base" : 2,
               "suffix" : 1
            }
         },
         "combat_analysis" : {
            "bytes" : {
               "suffix" : 1,
               "base" : 2,
               "total" : 2
            },
            "hints" : "",
            "order" : 23
         },
         "show_indian_moves" : {
            "hints" : "",
            "order" : 29,
            "bytes" : {
               "total" : 2,
               "base" : 2,
               "suffix" : 1
            }
         },
         "unknown" : {
            "order" : 27,
            "hints" : "",
            "bytes" : {
               "suffix" : 1,
               "total" : 2,
               "base" : 2
            }
         },
         "water_color_cycling" : {
            "bytes" : {
               "base" : 2,
               "total" : 2,
               "suffix" : 1
            },
            "hints" : "",
            "order" : 22
         },
         "show_foreign_moves" : {
            "hints" : "",
            "order" : 28,
            "bytes" : {
               "suffix" : 1,
               "base" : 2,
               "total" : 2
            }
         },
         "tutorial_hints" : {
            "bytes" : {
               "base" : 2,
               "total" : 2,
               "suffix" : 1
            },
            "order" : 21,
            "hints" : ""
         },
         "unknown7" : {
            "hints" : "",
            "order" : 20,
            "bytes" : {
               "base" : 2,
               "total" : 14,
               "suffix" : 7
            }
         },
         "end_of_turn" : {
            "bytes" : {
               "base" : 2,
               "total" : 2,
               "suffix" : 1
            },
            "order" : 25,
            "hints" : ""
         }
      },
      "unk0" : {
         "order" : 8,
         "hints" : "",
         "bytes" : {
            "suffix" : 3,
            "total" : 3,
            "base" : 1
         }
      },
      "tut3" : {
         "nr6" : {
            "hints" : "",
            "order" : 50,
            "bytes" : {
               "suffix" : 1,
               "base" : 1,
               "total" : 1
            }
         },
         "nr12" : {
            "bytes" : {
               "total" : 1,
               "base" : 1,
               "suffix" : 1
            },
            "order" : 56,
            "hints" : ""
         },
         "nr5" : {
            "bytes" : {
               "total" : 1,
               "base" : 1,
               "suffix" : 1
            },
            "order" : 49,
            "hints" : ""
         },
         "nr8" : {
            "bytes" : {
               "base" : 1,
               "total" : 1,
               "suffix" : 1
            },
            "hints" : "",
            "order" : 52
         },
         "nr9" : {
            "hints" : "",
            "order" : 53,
            "bytes" : {
               "suffix" : 1,
               "base" : 1,
               "total" : 1
            }
         },
         "nr10" : {
            "hints" : "",
            "order" : 54,
            "bytes" : {
               "suffix" : 1,
               "total" : 1,
               "base" : 1
            }
         },
         "nr7" : {
            "order" : 51,
            "hints" : "",
            "bytes" : {
               "base" : 1,
               "total" : 1,
               "suffix" : 1
            }
         },
         "nr11" : {
            "bytes" : {
               "suffix" : 1,
               "base" : 1,
               "total" : 1
            },
            "order" : 55,
            "hints" : ""
         }
      },
      "tut1" : {
         "unk3" : {
            "hints" : "",
            "order" : 13,
            "bytes" : {
               "suffix" : 1,
               "base" : 1,
               "total" : 1
            }
         },
         "nr13" : {
            "order" : 11,
            "hints" : "",
            "bytes" : {
               "base" : 1,
               "total" : 1,
               "suffix" : 1
            }
         },
         "nr15" : {
            "bytes" : {
               "suffix" : 1,
               "total" : 1,
               "base" : 1
            },
            "hints" : "",
            "order" : 14
         },
         "unk7" : {
            "bytes" : {
               "base" : 1,
               "total" : 1,
               "suffix" : 1
            },
            "order" : 17,
            "hints" : ""
         },
         "nr14" : {
            "bytes" : {
               "suffix" : 1,
               "total" : 1,
               "base" : 1
            },
            "hints" : "",
            "order" : 12
         },
         "nr17" : {
            "order" : 16,
            "hints" : "",
            "bytes" : {
               "suffix" : 1,
               "base" : 1,
               "total" : 1
            }
         },
         "nr19" : {
            "bytes" : {
               "base" : 1,
               "total" : 1,
               "suffix" : 1
            },
            "order" : 18,
            "hints" : ""
         },
         "nr16" : {
            "order" : 15,
            "hints" : "",
            "bytes" : {
               "base" : 1,
               "total" : 1,
               "suffix" : 1
            }
         }
      },
      "tut2" : {
         "event_music" : {
            "hints" : "",
            "order" : 43,
            "bytes" : {
               "suffix" : 1,
               "base" : 1,
               "total" : 1
            }
         },
         "sound_effects" : {
            "order" : 44,
            "hints" : "",
            "bytes" : {
               "suffix" : 1,
               "total" : 1,
               "base" : 1
            }
         },
         "howtowin" : {
            "hints" : "",
            "order" : 41,
            "bytes" : {
               "suffix" : 1,
               "total" : 1,
               "base" : 1
            }
         },
         "nr4" : {
            "hints" : "",
            "order" : 48,
            "bytes" : {
               "total" : 1,
               "base" : 1,
               "suffix" : 1
            }
         },
         "background_music" : {
            "order" : 42,
            "hints" : "",
            "bytes" : {
               "suffix" : 1,
               "base" : 1,
               "total" : 1
            }
         },
         "nr3" : {
            "order" : 47,
            "hints" : "",
            "bytes" : {
               "base" : 1,
               "total" : 1,
               "suffix" : 1
            }
         },
         "nr1" : {
            "bytes" : {
               "base" : 1,
               "total" : 1,
               "suffix" : 1
            },
            "order" : 45,
            "hints" : " // shown immediately on game-start"
         },
         "nr2" : {
            "bytes" : {
               "total" : 1,
               "base" : 1,
               "suffix" : 1
            },
            "hints" : " // probably not used, also triggers event_discovery_of_the_new_world",
            "order" : 46
         }
      },
      "active_unit" : {
         "hints" : "",
         "order" : 62,
         "bytes" : {
            "base" : 2,
            "total" : 2,
            "suffix" : 1
         }
      },
      "unkb" : {
         "bytes" : {
            "total" : 2,
            "base" : 1,
            "suffix" : 2
         },
         "hints" : "",
         "order" : 93
      },
      "turn" : {
         "hints" : "",
         "order" : 60,
         "bytes" : {
            "suffix" : 1,
            "total" : 2,
            "base" : 2
         }
      },
      "colony_report_options" : {
         "report_sons_of_liberty_membership" : {
            "hints" : "",
            "order" : 38,
            "bytes" : {
               "base" : 2,
               "total" : 2,
               "suffix" : 1
            }
         },
         "report_when_colonists_trained" : {
            "bytes" : {
               "suffix" : 1,
               "base" : 2,
               "total" : 2
            },
            "order" : 37,
            "hints" : ""
         },
         "report_inefficient_government" : {
            "bytes" : {
               "suffix" : 1,
               "base" : 2,
               "total" : 2
            },
            "order" : 33,
            "hints" : ""
         },
         "labels_on_buildings" : {
            "order" : 31,
            "hints" : "",
            "bytes" : {
               "base" : 2,
               "total" : 2,
               "suffix" : 1
            }
         },
         "report_food_shortages" : {
            "order" : 36,
            "hints" : "",
            "bytes" : {
               "total" : 2,
               "base" : 2,
               "suffix" : 1
            }
         },
         "report_new_cargos_available" : {
            "hints" : "",
            "order" : 32,
            "bytes" : {
               "suffix" : 1,
               "base" : 2,
               "total" : 2
            }
         },
         "unused" : {
            "order" : 40,
            "hints" : "",
            "bytes" : {
               "base" : 2,
               "total" : 12,
               "suffix" : 6
            }
         },
         "report_raw_materials_shortages" : {
            "bytes" : {
               "total" : 2,
               "base" : 2,
               "suffix" : 1
            },
            "hints" : "",
            "order" : 35
         },
         "labels_on_cargo_and_terrain" : {
            "order" : 30,
            "hints" : "",
            "bytes" : {
               "total" : 2,
               "base" : 2,
               "suffix" : 1
            }
         },
         "report_tools_needed_for_production" : {
            "bytes" : {
               "base" : 2,
               "total" : 2,
               "suffix" : 1
            },
            "order" : 34,
            "hints" : ""
         },
         "report_rebel_majorities" : {
            "hints" : "",
            "order" : 39,
            "bytes" : {
               "suffix" : 1,
               "base" : 2,
               "total" : 2
            }
         }
      },
      "unk1" : {
         "bytes" : {
            "base" : 1,
            "total" : 1,
            "suffix" : 1
         },
         "order" : 19,
         "hints" : ""
      },
      "colony_count" : {
         "bytes" : {
            "base" : 2,
            "total" : 2,
            "suffix" : 1
         },
         "order" : 66,
         "hints" : ""
      },
      "numbers00" : {
         "bytes" : {
            "base" : 2,
            "total" : 2,
            "suffix" : 1
         },
         "hints" : "",
         "order" : 57
      },
      "year" : {
         "hints" : "",
         "order" : 58,
         "bytes" : {
            "suffix" : 1,
            "base" : 2,
            "total" : 2
         }
      },
      "event" : {
         "the_fountain_of_youth" : {
            "bytes" : {
               "suffix" : 1,
               "base" : 2,
               "total" : 2
            },
            "order" : 84,
            "hints" : ""
         },
         "woodcut15" : {
            "order" : 91,
            "hints" : "",
            "bytes" : {
               "total" : 2,
               "base" : 2,
               "suffix" : 1
            }
         },
         "indian_raid" : {
            "bytes" : {
               "suffix" : 1,
               "base" : 2,
               "total" : 2
            },
            "order" : 89,
            "hints" : ""
         },
         "woodcut16" : {
            "bytes" : {
               "base" : 2,
               "total" : 2,
               "suffix" : 1
            },
            "hints" : "",
            "order" : 92
         },
         "meeting_fellow_europeans" : {
            "hints" : "",
            "order" : 86,
            "bytes" : {
               "total" : 2,
               "base" : 2,
               "suffix" : 1
            }
         },
         "colony_burning" : {
            "hints" : "",
            "order" : 87,
            "bytes" : {
               "total" : 2,
               "base" : 2,
               "suffix" : 1
            }
         },
         "meeting_the_natives" : {
            "order" : 79,
            "hints" : "",
            "bytes" : {
               "suffix" : 1,
               "total" : 2,
               "base" : 2
            }
         },
         "woodcut14" : {
            "hints" : "",
            "order" : 90,
            "bytes" : {
               "total" : 2,
               "base" : 2,
               "suffix" : 1
            }
         },
         "entering_indian_village" : {
            "bytes" : {
               "base" : 2,
               "total" : 2,
               "suffix" : 1
            },
            "hints" : "",
            "order" : 83
         },
         "the_aztec_empire" : {
            "hints" : "",
            "order" : 80,
            "bytes" : {
               "suffix" : 1,
               "base" : 2,
               "total" : 2
            }
         },
         "building_a_colony" : {
            "hints" : "",
            "order" : 78,
            "bytes" : {
               "suffix" : 1,
               "base" : 2,
               "total" : 2
            }
         },
         "cargo_from_the_new_world" : {
            "hints" : "",
            "order" : 85,
            "bytes" : {
               "base" : 2,
               "total" : 2,
               "suffix" : 1
            }
         },
         "discovery_of_the_new_world" : {
            "bytes" : {
               "base" : 2,
               "total" : 2,
               "suffix" : 1
            },
            "hints" : "",
            "order" : 77
         },
         "colony_destroyed" : {
            "bytes" : {
               "base" : 2,
               "total" : 2,
               "suffix" : 1
            },
            "order" : 88,
            "hints" : ""
         },
         "the_inca_nation" : {
            "order" : 81,
            "hints" : "",
            "bytes" : {
               "total" : 2,
               "base" : 2,
               "suffix" : 1
            }
         },
         "discovery_of_the_pacific_ocean" : {
            "hints" : "",
            "order" : 82,
            "bytes" : {
               "suffix" : 1,
               "total" : 2,
               "base" : 2
            }
         }
      },
      "numbers05" : {
         "hints" : "",
         "order" : 71,
         "bytes" : {
            "suffix" : 3,
            "total" : 6,
            "base" : 2
         }
      },
      "nation_relation" : {
         "order" : 72,
         "hints" : "",
         "bytes" : {
            "suffix" : 4,
            "base" : 2,
            "total" : 8
         }
      },
      "tribe_count" : {
         "hints" : "",
         "order" : 64,
         "bytes" : {
            "base" : 2,
            "total" : 2,
            "suffix" : 1
         }
      },
      "unit_count" : {
         "bytes" : {
            "total" : 2,
            "base" : 2,
            "suffix" : 1
         },
         "hints" : "",
         "order" : 65
      },
      "numbers04" : {
         "hints" : "",
         "order" : 69,
         "bytes" : {
            "suffix" : 1,
            "base" : 2,
            "total" : 2
         }
      },
      "expeditionary_force" : {
         "bytes" : {
            "total" : 8,
            "base" : 2,
            "suffix" : 4
         },
         "hints" : "",
         "order" : 74
      },
      "founding_father" : {
         "bytes" : {
            "total" : 25,
            "base" : 1,
            "suffix" : 25
         },
         "hints" : "",
         "order" : 70
      },
      "map_size_y" : {
         "bytes" : {
            "suffix" : 1,
            "base" : 2,
            "total" : 2
         },
         "hints" : "",
         "order" : 10
      },
      "numbers01" : {
         "order" : 61,
         "hints" : "",
         "bytes" : {
            "base" : 2,
            "total" : 2,
            "suffix" : 1
         }
      },
      "autumn" : {
         "order" : 59,
         "hints" : " //boolean, true if autumn",
         "bytes" : {
            "suffix" : 1,
            "base" : 2,
            "total" : 2
         }
      },
      "map_size_x" : {
         "bytes" : {
            "base" : 2,
            "total" : 2,
            "suffix" : 1
         },
         "order" : 9,
         "hints" : ""
      },
      "difficulty" : {
         "order" : 68,
         "hints" : " enum { DISCOVERER = 0, EXPLORER = 1, CONQUISTADOR = 2, GOVERNOR = 3, VICEROY = 4 }; //36",
         "bytes" : {
            "suffix" : 1,
            "total" : 1,
            "base" : 1
         }
      },
      "numbers02" : {
         "hints" : "",
         "order" : 63,
         "bytes" : {
            "base" : 2,
            "total" : 6,
            "suffix" : 3
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
      }
   },
   "tribe" : {
      "panic" : {
         "bytes" : {
            "suffix" : 1,
            "base" : 1,
            "total" : 1
         },
         "order" : 216,
         "hints" : ""
      },
      "population_loss_in_current_turn" : {
         "hints" : " //due to attacks",
         "order" : 218,
         "bytes" : {
            "suffix" : 1,
            "total" : 1,
            "base" : 1
         }
      },
      "nation" : {
         "hints" : "",
         "order" : 204,
         "bytes" : {
            "suffix" : 1,
            "base" : 1,
            "total" : 1
         }
      },
      "state" : {
         "unk7" : {
            "order" : 211,
            "hints" : "",
            "bytes" : {
               "total" : 1,
               "base" : 1,
               "suffix" : 1
            }
         },
         "learned" : {
            "order" : 206,
            "hints" : " //visited and learned skill",
            "bytes" : {
               "suffix" : 1,
               "base" : 1,
               "total" : 1
            }
         },
         "unk5" : {
            "bytes" : {
               "suffix" : 1,
               "total" : 1,
               "base" : 1
            },
            "order" : 209,
            "hints" : ""
         },
         "unk8" : {
            "bytes" : {
               "suffix" : 1,
               "total" : 1,
               "base" : 1
            },
            "hints" : "",
            "order" : 212
         },
         "scouted" : {
            "bytes" : {
               "suffix" : 1,
               "base" : 1,
               "total" : 1
            },
            "hints" : " //visited by scout",
            "order" : 208
         },
         "capital" : {
            "order" : 207,
            "hints" : "",
            "bytes" : {
               "base" : 1,
               "total" : 1,
               "suffix" : 1
            }
         },
         "unk6" : {
            "order" : 210,
            "hints" : "",
            "bytes" : {
               "suffix" : 1,
               "base" : 1,
               "total" : 1
            }
         },
         "artillery" : {
            "hints" : " //artillery has been nearby?",
            "order" : 205,
            "bytes" : {
               "suffix" : 1,
               "total" : 1,
               "base" : 1
            }
         }
      },
      "unk1" : {
         "order" : 215,
         "hints" : "",
         "bytes" : {
            "suffix" : 4,
            "base" : 1,
            "total" : 4
         }
      },
      "unk2" : {
         "bytes" : {
            "total" : 6,
            "base" : 1,
            "suffix" : 6
         },
         "hints" : "",
         "order" : 217
      },
      "population" : {
         "order" : 213,
         "hints" : "",
         "bytes" : {
            "suffix" : 1,
            "total" : 1,
            "base" : 1
         }
      },
      "mission" : {
         "hints" : " //ff if none, 0 1 2 3 = eng fra spa dut",
         "order" : 214,
         "bytes" : {
            "base" : 1,
            "total" : 1,
            "suffix" : 1
         }
      },
      "x" : {
         "bytes" : {
            "suffix" : 1,
            "base" : 1,
            "total" : 1
         },
         "order" : 203,
         "hints" : ""
      }
   },
   "count" : {
      "tribe" : {
         "bytes" : {
            "suffix" : 1,
            "total" : 2,
            "base" : 2
         },
         "hints" : "",
         "order" : 3
      },
      "colony" : {
         "order" : 1,
         "hints" : "",
         "bytes" : {
            "total" : 2,
            "base" : 2,
            "suffix" : 1
         }
      },
      "unit" : {
         "order" : 2,
         "hints" : "",
         "bytes" : {
            "total" : 2,
            "base" : 2,
            "suffix" : 1
         }
      },
      "nation" : {
         "bytes" : {
            "base" : 2,
            "total" : 2,
            "suffix" : 1
         },
         "order" : 5,
         "hints" : ""
      },
      "indian" : {
         "hints" : "",
         "order" : 6,
         "bytes" : {
            "suffix" : 1,
            "total" : 2,
            "base" : 2
         }
      },
      "player" : {
         "order" : 4,
         "hints" : "",
         "bytes" : {
            "total" : 2,
            "base" : 2,
            "suffix" : 1
         }
      }
   },
   "other" : {
      "unkXX_xx" : {
         "bytes" : {
            "suffix" : 24,
            "total" : 24,
            "base" : 1
         },
         "hints" : "",
         "order" : 100
      }
   },
   "unit" : {
      "transport_chain" : {
         "prev_unit_idx" : {
            "bytes" : {
               "suffix" : 1,
               "total" : 2,
               "base" : 2
            },
            "hints" : " // index to unit being transported? (treasure) ",
            "order" : 175
         },
         "next_unit_idx" : {
            "bytes" : {
               "base" : 2,
               "total" : 2,
               "suffix" : 1
            },
            "hints" : "",
            "order" : 174
         }
      },
      "profession" : {
         "order" : 173,
         "hints" : "",
         "bytes" : {
            "suffix" : 1,
            "total" : 1,
            "base" : 1
         }
      },
      "cargo_item_5" : {
         "hints" : "",
         "order" : 170,
         "bytes" : {
            "suffix" : 4,
            "base" : 1,
            "total" : 4
         }
      },
      "unk06" : {
         "hints" : "",
         "order" : 160,
         "bytes" : {
            "base" : 1,
            "total" : 1,
            "suffix" : 1
         }
      },
      "cargo_item_0" : {
         "bytes" : {
            "suffix" : 4,
            "total" : 4,
            "base" : 1
         },
         "order" : 165,
         "hints" : ""
      },
      "x" : {
         "bytes" : {
            "total" : 1,
            "base" : 1,
            "suffix" : 1
         },
         "order" : 154,
         "hints" : ""
      },
      "cargo_item_2" : {
         "hints" : "",
         "order" : 167,
         "bytes" : {
            "total" : 4,
            "base" : 1,
            "suffix" : 4
         }
      },
      "type" : {
         "order" : 155,
         "hints" : "",
         "bytes" : {
            "base" : 1,
            "total" : 1,
            "suffix" : 1
         }
      },
      "nation" : {
         "hints" : " /* likely to be owner of unit, eng, fra, spa, dut, indian tribes, etc. */",
         "order" : 156,
         "bytes" : {
            "suffix" : 4,
            "base" : 1,
            "total" : 4
         }
      },
      "turns_worked" : {
         "order" : 172,
         "hints" : "",
         "bytes" : {
            "total" : 1,
            "base" : 1,
            "suffix" : 1
         }
      },
      "unk05" : {
         "order" : 158,
         "hints" : "",
         "bytes" : {
            "base" : 1,
            "total" : 1,
            "suffix" : 1
         }
      },
      "order" : {
         "bytes" : {
            "suffix" : 1,
            "total" : 1,
            "base" : 1
         },
         "hints" : " enum { PLOW = 8, ROAD = 9 };",
         "order" : 162
      },
      "unk08" : {
         "order" : 163,
         "hints" : "",
         "bytes" : {
            "suffix" : 3,
            "base" : 1,
            "total" : 3
         }
      },
      "cargo_item_4" : {
         "bytes" : {
            "total" : 4,
            "base" : 1,
            "suffix" : 4
         },
         "hints" : "",
         "order" : 169
      },
      "holds_occupied" : {
         "bytes" : {
            "suffix" : 1,
            "total" : 1,
            "base" : 1
         },
         "order" : 164,
         "hints" : ""
      },
      "unk07" : {
         "bytes" : {
            "suffix" : 1,
            "total" : 1,
            "base" : 1
         },
         "hints" : "",
         "order" : 161
      },
      "moves" : {
         "bytes" : {
            "suffix" : 1,
            "total" : 1,
            "base" : 1
         },
         "order" : 159,
         "hints" : " /* Accumulated moves (3 between land, 1 on roads, etc.) */"
      },
      "cargo_hold" : {
         "order" : 171,
         "hints" : "",
         "bytes" : {
            "suffix" : 6,
            "base" : 1,
            "total" : 6
         }
      },
      "unk04" : {
         "bytes" : {
            "suffix" : 4,
            "total" : 4,
            "base" : 1
         },
         "order" : 157,
         "hints" : ""
      },
      "cargo_item_1" : {
         "bytes" : {
            "base" : 1,
            "total" : 4,
            "suffix" : 4
         },
         "hints" : "",
         "order" : 166
      },
      "cargo_item_3" : {
         "order" : 168,
         "hints" : "",
         "bytes" : {
            "suffix" : 4,
            "base" : 1,
            "total" : 4
         }
      }
   },
   "nation" : {
      "trade" : {
         "tons" : {
            "hints" : "",
            "order" : 201,
            "bytes" : {
               "base" : 4,
               "total" : 64,
               "suffix" : 16
            }
         },
         "gold" : {
            "bytes" : {
               "base" : 4,
               "total" : 64,
               "suffix" : 16
            },
            "hints" : "",
            "order" : 200
         },
         "tons2" : {
            "hints" : "",
            "order" : 202,
            "bytes" : {
               "suffix" : 16,
               "base" : 4,
               "total" : 64
            }
         },
         "nr" : {
            "hints" : "",
            "order" : 199,
            "bytes" : {
               "suffix" : 16,
               "total" : 32,
               "base" : 2
            }
         },
         "euro_price" : {
            "order" : 198,
            "hints" : "",
            "bytes" : {
               "suffix" : 16,
               "base" : 1,
               "total" : 16
            }
         }
      },
      "relation_by_indian" : {
         "bytes" : {
            "base" : 1,
            "total" : 8,
            "suffix" : 8
         },
         "hints" : " enum { NOT_MET = 0x00, WAR = 0x20, PEACE = 0x60};",
         "order" : 196
      },
      "unk6" : {
         "hints" : "",
         "order" : 195,
         "bytes" : {
            "suffix" : 4,
            "base" : 2,
            "total" : 8
         }
      },
      "unk7" : {
         "bytes" : {
            "suffix" : 12,
            "total" : 12,
            "base" : 1
         },
         "hints" : "",
         "order" : 197
      },
      "gold" : {
         "bytes" : {
            "suffix" : 1,
            "total" : 4,
            "base" : 4
         },
         "hints" : "",
         "order" : 193
      },
      "tax_rate" : {
         "bytes" : {
            "base" : 1,
            "total" : 1,
            "suffix" : 1
         },
         "order" : 177,
         "hints" : ""
      },
      "crosses" : {
         "bytes" : {
            "base" : 2,
            "total" : 2,
            "suffix" : 1
         },
         "order" : 194,
         "hints" : ""
      },
      "recruit_count" : {
         "bytes" : {
            "suffix" : 1,
            "base" : 1,
            "total" : 1
         },
         "order" : 180,
         "hints" : " //recruit penalty 120 + (count * 20) (does not go above 180) "
      },
      "founding_father_count" : {
         "bytes" : {
            "base" : 2,
            "total" : 2,
            "suffix" : 1
         },
         "order" : 186,
         "hints" : ""
      },
      "unk1" : {
         "bytes" : {
            "total" : 1,
            "base" : 1,
            "suffix" : 1
         },
         "hints" : "",
         "order" : 179
      },
      "recruit" : {
         "order" : 178,
         "hints" : "",
         "bytes" : {
            "total" : 3,
            "base" : 1,
            "suffix" : 3
         }
      },
      "boycott_bitmap" : {
         "bytes" : {
            "suffix" : 1,
            "total" : 2,
            "base" : 2
         },
         "order" : 191,
         "hints" : ""
      },
      "unk4" : {
         "hints" : "",
         "order" : 189,
         "bytes" : {
            "base" : 1,
            "total" : 5,
            "suffix" : 5
         }
      },
      "unk3" : {
         "bytes" : {
            "total" : 2,
            "base" : 1,
            "suffix" : 2
         },
         "order" : 184,
         "hints" : ""
      },
      "liberty_bells_last_turn" : {
         "bytes" : {
            "total" : 2,
            "base" : 2,
            "suffix" : 1
         },
         "hints" : "",
         "order" : 183
      },
      "unk5" : {
         "bytes" : {
            "total" : 8,
            "base" : 1,
            "suffix" : 8
         },
         "hints" : "",
         "order" : 192
      },
      "liberty_bells_total" : {
         "hints" : "",
         "order" : 182,
         "bytes" : {
            "suffix" : 1,
            "base" : 2,
            "total" : 2
         }
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
      "unk2" : {
         "bytes" : {
            "base" : 1,
            "total" : 5,
            "suffix" : 5
         },
         "hints" : "",
         "order" : 181
      },
      "next_founding_father" : {
         "hints" : "",
         "order" : 185,
         "bytes" : {
            "suffix" : 1,
            "base" : 2,
            "total" : 2
         }
      },
      "ffc_high" : {
         "bytes" : {
            "suffix" : 1,
            "total" : 2,
            "base" : 2
         },
         "hints" : " //suspect founding_father_count is 32bit.",
         "order" : 187
      },
      "villages_burned" : {
         "bytes" : {
            "total" : 1,
            "base" : 1,
            "suffix" : 1
         },
         "hints" : "",
         "order" : 188
      },
      "unk0" : {
         "hints" : "",
         "order" : 176,
         "bytes" : {
            "suffix" : 1,
            "base" : 1,
            "total" : 1
         }
      }
   },
   "player" : {
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
         "hints" : "",
         "bytes" : {
            "suffix" : 1,
            "base" : 1,
            "total" : 1
         }
      },
      "control" : {
         "hints" : " enum { PLAYER = 0, AI = 1 };",
         "order" : 97,
         "bytes" : {
            "suffix" : 1,
            "total" : 1,
            "base" : 1
         }
      },
      "diplomacy" : {
         "hints" : "",
         "order" : 99,
         "bytes" : {
            "total" : 1,
            "base" : 1,
            "suffix" : 1
         }
      },
      "name" : {
         "bytes" : {
            "base" : 1,
            "total" : 24,
            "suffix" : 24
         },
         "hints" : "",
         "order" : 94
      },
      "country" : {
         "hints" : "",
         "order" : 95,
         "bytes" : {
            "suffix" : 24,
            "total" : 24,
            "base" : 1
         }
      }
   },
   "tail" : {
      "unk" : {
         "order" : 235,
         "hints" : "",
         "bytes" : {
            "base" : 1,
            "total" : 1502,
            "suffix" : 1502
         }
      }
   },
   "colony" : {
      "y" : {
         "order" : 102,
         "hints" : "",
         "bytes" : {
            "suffix" : 1,
            "total" : 1,
            "base" : 1
         }
      },
      "x" : {
         "order" : 101,
         "hints" : "",
         "bytes" : {
            "base" : 1,
            "total" : 1,
            "suffix" : 1
         }
      },
      "rebel_divisor" : {
         "order" : 153,
         "hints" : "",
         "bytes" : {
            "suffix" : 1,
            "total" : 4,
            "base" : 4
         }
      },
      "unkd" : {
         "order" : 151,
         "hints" : "",
         "bytes" : {
            "base" : 1,
            "total" : 8,
            "suffix" : 8
         }
      },
      "population" : {
         "order" : 106,
         "hints" : "",
         "bytes" : {
            "suffix" : 1,
            "total" : 1,
            "base" : 1
         }
      },
      "hammers" : {
         "bytes" : {
            "suffix" : 1,
            "total" : 2,
            "base" : 2
         },
         "order" : 147,
         "hints" : ""
      },
      "occupation" : {
         "bytes" : {
            "suffix" : 32,
            "total" : 32,
            "base" : 1
         },
         "hints" : "",
         "order" : 107
      },
      "custom_house" : {
         "coats" : {
            "bytes" : {
               "suffix" : 1,
               "base" : 2,
               "total" : 2
            },
            "hints" : "",
            "order" : 142
         },
         "food" : {
            "hints" : "",
            "order" : 130,
            "bytes" : {
               "suffix" : 1,
               "base" : 2,
               "total" : 2
            }
         },
         "muskets" : {
            "order" : 145,
            "hints" : "",
            "bytes" : {
               "suffix" : 1,
               "base" : 2,
               "total" : 2
            }
         },
         "ore" : {
            "bytes" : {
               "total" : 2,
               "base" : 2,
               "suffix" : 1
            },
            "hints" : "",
            "order" : 136
         },
         "sugar" : {
            "order" : 131,
            "hints" : "",
            "bytes" : {
               "base" : 2,
               "total" : 2,
               "suffix" : 1
            }
         },
         "lumber" : {
            "bytes" : {
               "suffix" : 1,
               "base" : 2,
               "total" : 2
            },
            "order" : 135,
            "hints" : ""
         },
         "cotton" : {
            "order" : 133,
            "hints" : "",
            "bytes" : {
               "suffix" : 1,
               "base" : 2,
               "total" : 2
            }
         },
         "cigars" : {
            "order" : 140,
            "hints" : "",
            "bytes" : {
               "suffix" : 1,
               "base" : 2,
               "total" : 2
            }
         },
         "tools" : {
            "bytes" : {
               "suffix" : 1,
               "base" : 2,
               "total" : 2
            },
            "order" : 144,
            "hints" : ""
         },
         "furs" : {
            "hints" : "",
            "order" : 134,
            "bytes" : {
               "suffix" : 1,
               "total" : 2,
               "base" : 2
            }
         },
         "trade_goods" : {
            "order" : 143,
            "hints" : "",
            "bytes" : {
               "suffix" : 1,
               "total" : 2,
               "base" : 2
            }
         },
         "cloth" : {
            "bytes" : {
               "suffix" : 1,
               "base" : 2,
               "total" : 2
            },
            "order" : 141,
            "hints" : ""
         },
         "horses" : {
            "order" : 138,
            "hints" : "",
            "bytes" : {
               "total" : 2,
               "base" : 2,
               "suffix" : 1
            }
         },
         "silver" : {
            "order" : 137,
            "hints" : "",
            "bytes" : {
               "suffix" : 1,
               "base" : 2,
               "total" : 2
            }
         },
         "rum" : {
            "order" : 139,
            "hints" : "",
            "bytes" : {
               "base" : 2,
               "total" : 2,
               "suffix" : 1
            }
         },
         "tobacco" : {
            "hints" : "",
            "order" : 132,
            "bytes" : {
               "suffix" : 1,
               "base" : 2,
               "total" : 2
            }
         }
      },
      "profession" : {
         "bytes" : {
            "suffix" : 32,
            "base" : 1,
            "total" : 32
         },
         "order" : 108,
         "hints" : ""
      },
      "stock" : {
         "order" : 150,
         "hints" : "",
         "bytes" : {
            "base" : 2,
            "total" : 32,
            "suffix" : 16
         }
      },
      "tiles" : {
         "bytes" : {
            "base" : 1,
            "total" : 8,
            "suffix" : 8
         },
         "hints" : " //represents tiles around the colony. idx to citizen.",
         "order" : 110
      },
      "unk0" : {
         "hints" : "",
         "order" : 105,
         "bytes" : {
            "base" : 1,
            "total" : 4,
            "suffix" : 4
         }
      },
      "rebel_dividend" : {
         "bytes" : {
            "suffix" : 1,
            "base" : 4,
            "total" : 4
         },
         "hints" : "",
         "order" : 152
      },
      "building_in_production" : {
         "bytes" : {
            "base" : 1,
            "total" : 1,
            "suffix" : 1
         },
         "order" : 148,
         "hints" : ""
      },
      "unkb" : {
         "order" : 149,
         "hints" : "",
         "bytes" : {
            "suffix" : 5,
            "base" : 1,
            "total" : 5
         }
      },
      "unk6" : {
         "hints" : "",
         "order" : 109,
         "bytes" : {
            "suffix" : 16,
            "base" : 1,
            "total" : 16
         }
      },
      "unk8" : {
         "hints" : "",
         "order" : 111,
         "bytes" : {
            "base" : 1,
            "total" : 12,
            "suffix" : 12
         }
      },
      "name" : {
         "order" : 103,
         "hints" : "",
         "bytes" : {
            "base" : 1,
            "total" : 24,
            "suffix" : 24
         }
      },
      "buildings" : {
         "church" : {
            "bytes" : {
               "base" : 2,
               "total" : 4,
               "suffix" : 2
            },
            "hints" : "",
            "order" : 127
         },
         "town_hall" : {
            "hints" : "",
            "order" : 115,
            "bytes" : {
               "suffix" : 3,
               "total" : 12,
               "base" : 4
            }
         },
         "armory" : {
            "order" : 113,
            "hints" : "",
            "bytes" : {
               "total" : 12,
               "base" : 4,
               "suffix" : 3
            }
         },
         "docks" : {
            "bytes" : {
               "base" : 4,
               "total" : 12,
               "suffix" : 3
            },
            "hints" : "",
            "order" : 114
         },
         "stockade" : {
            "hints" : "",
            "order" : 112,
            "bytes" : {
               "suffix" : 3,
               "base" : 4,
               "total" : 12
            }
         },
         "schoolhouse" : {
            "order" : 116,
            "hints" : "",
            "bytes" : {
               "base" : 4,
               "total" : 12,
               "suffix" : 3
            }
         },
         "capitol" : {
            "order" : 124,
            "hints" : " /* not really in use */",
            "bytes" : {
               "suffix" : 2,
               "base" : 4,
               "total" : 8
            }
         },
         "custom_house" : {
            "bytes" : {
               "suffix" : 1,
               "total" : 4,
               "base" : 4
            },
            "order" : 119,
            "hints" : ""
         },
         "warehouse" : {
            "bytes" : {
               "suffix" : 2,
               "base" : 4,
               "total" : 8
            },
            "order" : 117,
            "hints" : ""
         },
         "blacksmiths_house" : {
            "hints" : "",
            "order" : 128,
            "bytes" : {
               "suffix" : 3,
               "base" : 2,
               "total" : 6
            }
         },
         "unused" : {
            "hints" : "",
            "order" : 129,
            "bytes" : {
               "suffix" : 6,
               "base" : 2,
               "total" : 12
            }
         },
         "weavers_house" : {
            "bytes" : {
               "suffix" : 3,
               "total" : 12,
               "base" : 4
            },
            "order" : 121,
            "hints" : ""
         },
         "tobacconists_house" : {
            "bytes" : {
               "total" : 12,
               "base" : 4,
               "suffix" : 3
            },
            "order" : 122,
            "hints" : ""
         },
         "rum_distillers_house" : {
            "bytes" : {
               "suffix" : 3,
               "total" : 12,
               "base" : 4
            },
            "hints" : "",
            "order" : 123
         },
         "carpenters_shop" : {
            "hints" : "",
            "order" : 126,
            "bytes" : {
               "suffix" : 2,
               "total" : 4,
               "base" : 2
            }
         },
         "stables" : {
            "bytes" : {
               "base" : 4,
               "total" : 4,
               "suffix" : 1
            },
            "hints" : "",
            "order" : 118
         },
         "fur_traders_house" : {
            "hints" : "",
            "order" : 125,
            "bytes" : {
               "suffix" : 3,
               "base" : 2,
               "total" : 6
            }
         },
         "printing_press" : {
            "hints" : "",
            "order" : 120,
            "bytes" : {
               "suffix" : 2,
               "total" : 8,
               "base" : 4
            }
         }
      },
      "unka" : {
         "bytes" : {
            "suffix" : 6,
            "base" : 1,
            "total" : 6
         },
         "order" : 146,
         "hints" : ""
      },
      "nation" : {
         "order" : 104,
         "hints" : "",
         "bytes" : {
            "total" : 1,
            "base" : 1,
            "suffix" : 1
         }
      }
   }
}

    )"_json;
    return j;
}
