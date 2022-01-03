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
json merge_json_tribe_list(  const struct savegame *sg, json j );

/*
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
    j = merge_json_tribe_list(  sg , j );

    std::cout << j.dump(4) << std::endl;

/*
    j = merge_json_map(         sg , j );

    std::cout << j.dump(4) << std::endl;
*/

}



json merge_json_head(        const struct savegame *sg, json j )
{
    j["head"]["active_unit"]["value"] = (uint16_t) sg->head.active_unit;
    j["head"]["autumn"]["value"] = (uint16_t) sg->head.autumn;
    j["head"]["colony_count"]["value"] = (uint16_t) sg->head.colony_count;
    j["head"]["colony_report_options"]["labels_on_buildings"]["value"] = (uint16_t) sg->head.colony_report_options.labels_on_buildings;
    j["head"]["colony_report_options"]["labels_on_cargo_and_terrain"]["value"] = (uint16_t) sg->head.colony_report_options.labels_on_cargo_and_terrain;
    j["head"]["colony_report_options"]["report_food_shortages"]["value"] = (uint16_t) sg->head.colony_report_options.report_food_shortages;
    j["head"]["colony_report_options"]["report_inefficient_government"]["value"] = (uint16_t) sg->head.colony_report_options.report_inefficient_government;
    j["head"]["colony_report_options"]["report_new_cargos_available"]["value"] = (uint16_t) sg->head.colony_report_options.report_new_cargos_available;
    j["head"]["colony_report_options"]["report_raw_materials_shortages"]["value"] = (uint16_t) sg->head.colony_report_options.report_raw_materials_shortages;
    j["head"]["colony_report_options"]["report_rebel_majorities"]["value"] = (uint16_t) sg->head.colony_report_options.report_rebel_majorities;
    j["head"]["colony_report_options"]["report_sons_of_liberty_membership"]["value"] = (uint16_t) sg->head.colony_report_options.report_sons_of_liberty_membership;
    j["head"]["colony_report_options"]["report_tools_needed_for_production"]["value"] = (uint16_t) sg->head.colony_report_options.report_tools_needed_for_production;
    j["head"]["colony_report_options"]["report_when_colonists_trained"]["value"] = (uint16_t) sg->head.colony_report_options.report_when_colonists_trained;
    j["head"]["colony_report_options"]["unused"]["value"] = (uint16_t) sg->head.colony_report_options.unused;
    uint16_t sg_head_count_down[] = {
			sg->head.count_down[0],
			sg->head.count_down[1],
			sg->head.count_down[2],
			sg->head.count_down[3],
			sg->head.count_down[4],
			sg->head.count_down[5],
			sg->head.count_down[6],
			sg->head.count_down[7],
			sg->head.count_down[8],
			sg->head.count_down[9],
			sg->head.count_down[10],
			sg->head.count_down[11],
			sg->head.count_down[12],
			sg->head.count_down[13],
			sg->head.count_down[14],
			sg->head.count_down[15],
		};
		j["head"]["count_down"]["value"] = sg_head_count_down;
    j["head"]["difficulty"]["value"] = (uint8_t) sg->head.difficulty;
    j["head"]["event"]["building_a_colony"]["value"] = (uint16_t) sg->head.event.building_a_colony;
    j["head"]["event"]["cargo_from_the_new_world"]["value"] = (uint16_t) sg->head.event.cargo_from_the_new_world;
    j["head"]["event"]["colony_burning"]["value"] = (uint16_t) sg->head.event.colony_burning;
    j["head"]["event"]["colony_destroyed"]["value"] = (uint16_t) sg->head.event.colony_destroyed;
    j["head"]["event"]["discovery_of_the_new_world"]["value"] = (uint16_t) sg->head.event.discovery_of_the_new_world;
    j["head"]["event"]["discovery_of_the_pacific_ocean"]["value"] = (uint16_t) sg->head.event.discovery_of_the_pacific_ocean;
    j["head"]["event"]["entering_indian_village"]["value"] = (uint16_t) sg->head.event.entering_indian_village;
    j["head"]["event"]["indian_raid"]["value"] = (uint16_t) sg->head.event.indian_raid;
    j["head"]["event"]["meeting_fellow_europeans"]["value"] = (uint16_t) sg->head.event.meeting_fellow_europeans;
    j["head"]["event"]["meeting_the_natives"]["value"] = (uint16_t) sg->head.event.meeting_the_natives;
    j["head"]["event"]["the_aztec_empire"]["value"] = (uint16_t) sg->head.event.the_aztec_empire;
    j["head"]["event"]["the_fountain_of_youth"]["value"] = (uint16_t) sg->head.event.the_fountain_of_youth;
    j["head"]["event"]["the_inca_nation"]["value"] = (uint16_t) sg->head.event.the_inca_nation;
    j["head"]["event"]["woodcut14"]["value"] = (uint16_t) sg->head.event.woodcut14;
    j["head"]["event"]["woodcut15"]["value"] = (uint16_t) sg->head.event.woodcut15;
    j["head"]["event"]["woodcut16"]["value"] = (uint16_t) sg->head.event.woodcut16;
    uint16_t sg_head_expeditionary_force[] = {
			sg->head.expeditionary_force[0],
			sg->head.expeditionary_force[1],
			sg->head.expeditionary_force[2],
			sg->head.expeditionary_force[3],
		};
		j["head"]["expeditionary_force"]["value"] = sg_head_expeditionary_force;
    j["head"]["founding_father"]["value"] = sg->head.founding_father;
    j["head"]["game_options"]["autosave"]["value"] = (uint16_t) sg->head.game_options.autosave;
    j["head"]["game_options"]["combat_analysis"]["value"] = (uint16_t) sg->head.game_options.combat_analysis;
    j["head"]["game_options"]["end_of_turn"]["value"] = (uint16_t) sg->head.game_options.end_of_turn;
    j["head"]["game_options"]["fast_piece_slide"]["value"] = (uint16_t) sg->head.game_options.fast_piece_slide;
    j["head"]["game_options"]["show_foreign_moves"]["value"] = (uint16_t) sg->head.game_options.show_foreign_moves;
    j["head"]["game_options"]["show_indian_moves"]["value"] = (uint16_t) sg->head.game_options.show_indian_moves;
    j["head"]["game_options"]["tutorial_hints"]["value"] = (uint16_t) sg->head.game_options.tutorial_hints;
    j["head"]["game_options"]["unknown"]["value"] = (uint16_t) sg->head.game_options.unknown;
    j["head"]["game_options"]["unknown7"]["value"] = (uint16_t) sg->head.game_options.unknown7;
    j["head"]["game_options"]["water_color_cycling"]["value"] = (uint16_t) sg->head.game_options.water_color_cycling;
    j["head"]["map_size_x"]["value"] = (uint16_t) sg->head.map_size_x;
    j["head"]["map_size_y"]["value"] = (uint16_t) sg->head.map_size_y;
    int16_t sg_head_nation_relation[] = {
			sg->head.nation_relation[0],
			sg->head.nation_relation[1],
			sg->head.nation_relation[2],
			sg->head.nation_relation[3],
		};
		j["head"]["nation_relation"]["value"] = sg_head_nation_relation;
    j["head"]["numbers00"]["value"] = (int16_t) sg->head.numbers00;
    j["head"]["numbers01"]["value"] = (int16_t) sg->head.numbers01;
    int16_t sg_head_numbers02[] = {
			sg->head.numbers02[0],
			sg->head.numbers02[1],
			sg->head.numbers02[2],
		};
		j["head"]["numbers02"]["value"] = sg_head_numbers02;
    int16_t sg_head_numbers03[] = {
			sg->head.numbers03[0],
			sg->head.numbers03[1],
			sg->head.numbers03[2],
		};
		j["head"]["numbers03"]["value"] = sg_head_numbers03;
    j["head"]["numbers04"]["value"] = (int16_t) sg->head.numbers04;
    uint16_t sg_head_numbers05[] = {
			sg->head.numbers05[0],
			sg->head.numbers05[1],
			sg->head.numbers05[2],
		};
		j["head"]["numbers05"]["value"] = sg_head_numbers05;
    int16_t sg_head_numbers06[] = {
			sg->head.numbers06[0],
			sg->head.numbers06[1],
			sg->head.numbers06[2],
			sg->head.numbers06[3],
			sg->head.numbers06[4],
		};
		j["head"]["numbers06"]["value"] = sg_head_numbers06;
    uint16_t sg_head_numbers07[] = {
			sg->head.numbers07[0],
			sg->head.numbers07[1],
			sg->head.numbers07[2],
			sg->head.numbers07[3],
		};
		j["head"]["numbers07"]["value"] = sg_head_numbers07;
    char sg_head_sig_colonize[] = {
			sg->head.sig_colonize[0],
			sg->head.sig_colonize[1],
			sg->head.sig_colonize[2],
			sg->head.sig_colonize[3],
			sg->head.sig_colonize[4],
			sg->head.sig_colonize[5],
			sg->head.sig_colonize[6],
			sg->head.sig_colonize[7],
			sg->head.sig_colonize[8],
		};
		j["head"]["sig_colonize"]["value"] = sg_head_sig_colonize;
    j["head"]["tribe_count"]["value"] = (uint16_t) sg->head.tribe_count;
    j["head"]["turn"]["value"] = (uint16_t) sg->head.turn;
    j["head"]["tut1"]["nr13"]["value"] = (uint8_t) sg->head.tut1.nr13;
    j["head"]["tut1"]["nr14"]["value"] = (uint8_t) sg->head.tut1.nr14;
    j["head"]["tut1"]["nr15"]["value"] = (uint8_t) sg->head.tut1.nr15;
    j["head"]["tut1"]["nr16"]["value"] = (uint8_t) sg->head.tut1.nr16;
    j["head"]["tut1"]["nr17"]["value"] = (uint8_t) sg->head.tut1.nr17;
    j["head"]["tut1"]["nr19"]["value"] = (uint8_t) sg->head.tut1.nr19;
    j["head"]["tut1"]["unk3"]["value"] = (uint8_t) sg->head.tut1.unk3;
    j["head"]["tut1"]["unk7"]["value"] = (uint8_t) sg->head.tut1.unk7;
    j["head"]["tut2"]["background_music"]["value"] = (uint8_t) sg->head.tut2.background_music;
    j["head"]["tut2"]["event_music"]["value"] = (uint8_t) sg->head.tut2.event_music;
    j["head"]["tut2"]["howtowin"]["value"] = (uint8_t) sg->head.tut2.howtowin;
    j["head"]["tut2"]["nr1"]["value"] = (uint8_t) sg->head.tut2.nr1;
    j["head"]["tut2"]["nr2"]["value"] = (uint8_t) sg->head.tut2.nr2;
    j["head"]["tut2"]["nr3"]["value"] = (uint8_t) sg->head.tut2.nr3;
    j["head"]["tut2"]["nr4"]["value"] = (uint8_t) sg->head.tut2.nr4;
    j["head"]["tut2"]["sound_effects"]["value"] = (uint8_t) sg->head.tut2.sound_effects;
    j["head"]["tut3"]["nr10"]["value"] = (uint8_t) sg->head.tut3.nr10;
    j["head"]["tut3"]["nr11"]["value"] = (uint8_t) sg->head.tut3.nr11;
    j["head"]["tut3"]["nr12"]["value"] = (uint8_t) sg->head.tut3.nr12;
    j["head"]["tut3"]["nr5"]["value"] = (uint8_t) sg->head.tut3.nr5;
    j["head"]["tut3"]["nr6"]["value"] = (uint8_t) sg->head.tut3.nr6;
    j["head"]["tut3"]["nr7"]["value"] = (uint8_t) sg->head.tut3.nr7;
    j["head"]["tut3"]["nr8"]["value"] = (uint8_t) sg->head.tut3.nr8;
    j["head"]["tut3"]["nr9"]["value"] = (uint8_t) sg->head.tut3.nr9;
    j["head"]["unit_count"]["value"] = (uint16_t) sg->head.unit_count;
    uint8_t sg_head_unk0[] = {
			sg->head.unk0[0],
			sg->head.unk0[1],
			sg->head.unk0[2],
		};
		j["head"]["unk0"]["value"] = sg_head_unk0;
    j["head"]["unk1"]["value"] = sg->head.unk1;
    uint8_t sg_head_unkb[] = {
			sg->head.unkb[0],
			sg->head.unkb[1],
		};
		j["head"]["unkb"]["value"] = sg_head_unkb;
    j["head"]["year"]["value"] = (uint16_t) sg->head.year;
    return j;
}


json merge_json_other(        const struct savegame *sg, json j )
{
    j["other"]["unkXX_xx"]["value"] = sg->other.unkXX_xx;
    return j;
}


json merge_json_stuff(        const struct savegame *sg, json j )
{
    j["stuff"]["counter_decreasing_on_new_colony"]["value"] = (uint16_t) sg->stuff.counter_decreasing_on_new_colony;
    j["stuff"]["counter_increasing_on_new_colony"]["value"] = (uint16_t) sg->stuff.counter_increasing_on_new_colony;
    uint8_t sg_stuff_unk15[] = {
			sg->stuff.unk15[0],
			sg->stuff.unk15[1],
			sg->stuff.unk15[2],
			sg->stuff.unk15[3],
			sg->stuff.unk15[4],
			sg->stuff.unk15[5],
			sg->stuff.unk15[6],
			sg->stuff.unk15[7],
			sg->stuff.unk15[8],
			sg->stuff.unk15[9],
			sg->stuff.unk15[10],
			sg->stuff.unk15[11],
			sg->stuff.unk15[12],
			sg->stuff.unk15[13],
			sg->stuff.unk15[14],
		};
		j["stuff"]["unk15"]["value"] = sg_stuff_unk15;
    j["stuff"]["unk7"]["value"] = (uint8_t) sg->stuff.unk7;
    j["stuff"]["unk_big"]["value"] = sg->stuff.unk_big;
    j["stuff"]["unk_short"]["value"] = (uint16_t) sg->stuff.unk_short;
    j["stuff"]["viewport_x"]["value"] = (uint16_t) sg->stuff.viewport_x;
    j["stuff"]["viewport_y"]["value"] = (uint16_t) sg->stuff.viewport_y;
    j["stuff"]["x"]["value"] = (uint16_t) sg->stuff.x;
    j["stuff"]["y"]["value"] = (uint16_t) sg->stuff.y;
    j["stuff"]["zoom_level"]["value"] = (uint8_t) sg->stuff.zoom_level;
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
        
        j["player_list"][i]["control"]["value"] = (uint8_t) sg->player[i].control;
        j["player_list"][i]["country"]["value"] = sg->player[i].country;
        j["player_list"][i]["diplomacy"]["value"] = (uint8_t) sg->player[i].diplomacy;
        j["player_list"][i]["founded_colonies"]["value"] = (uint8_t) sg->player[i].founded_colonies;
        j["player_list"][i]["name"]["value"] = sg->player[i].name;
        j["player_list"][i]["unk00"]["value"] = (uint8_t) sg->player[i].unk00;
    }
    return j;
}


json merge_json_nation_list(   const struct savegame *sg, json j )
{
    json base = j["nation"];

    for (int i = 0; i < sg->count.nation; ++i) {
        j["nation_list"][i] = base;
        
        j["nation_list"][i]["artillery_count"]["value"] = (uint16_t) sg->nation[i].artillery_count;
        j["nation_list"][i]["boycott_bitmap"]["value"] = (uint16_t) sg->nation[i].boycott_bitmap;
        j["nation_list"][i]["crosses"]["value"] = (uint16_t) sg->nation[i].crosses;
        j["nation_list"][i]["ffc_high"]["value"] = (uint16_t) sg->nation[i].ffc_high;
        j["nation_list"][i]["founding_father_count"]["value"] = (uint16_t) sg->nation[i].founding_father_count;
        j["nation_list"][i]["gold"]["value"] = (uint32_t) sg->nation[i].gold;
        j["nation_list"][i]["liberty_bells_last_turn"]["value"] = (uint16_t) sg->nation[i].liberty_bells_last_turn;
        j["nation_list"][i]["liberty_bells_total"]["value"] = (uint16_t) sg->nation[i].liberty_bells_total;
        j["nation_list"][i]["next_founding_father"]["value"] = (int16_t) sg->nation[i].next_founding_father;
        uint8_t sg_nation_recruit[] = {
			sg->nation[i].recruit[0],
			sg->nation[i].recruit[1],
			sg->nation[i].recruit[2],
		};
		j["nation_list"][i]["recruit"]["value"] = sg_nation_recruit;
        j["nation_list"][i]["recruit_count"]["value"] = (uint8_t) sg->nation[i].recruit_count;
        uint8_t sg_nation_relation_by_indian[] = {
			sg->nation[i].relation_by_indian[0],
			sg->nation[i].relation_by_indian[1],
			sg->nation[i].relation_by_indian[2],
			sg->nation[i].relation_by_indian[3],
			sg->nation[i].relation_by_indian[4],
			sg->nation[i].relation_by_indian[5],
			sg->nation[i].relation_by_indian[6],
			sg->nation[i].relation_by_indian[7],
		};
		j["nation_list"][i]["relation_by_indian"]["value"] = sg_nation_relation_by_indian;
        j["nation_list"][i]["tax_rate"]["value"] = (uint8_t) sg->nation[i].tax_rate;
        uint8_t sg_nation_trade_euro_price[] = {
			sg->nation[i].trade.euro_price[0],
			sg->nation[i].trade.euro_price[1],
			sg->nation[i].trade.euro_price[2],
			sg->nation[i].trade.euro_price[3],
			sg->nation[i].trade.euro_price[4],
			sg->nation[i].trade.euro_price[5],
			sg->nation[i].trade.euro_price[6],
			sg->nation[i].trade.euro_price[7],
			sg->nation[i].trade.euro_price[8],
			sg->nation[i].trade.euro_price[9],
			sg->nation[i].trade.euro_price[10],
			sg->nation[i].trade.euro_price[11],
			sg->nation[i].trade.euro_price[12],
			sg->nation[i].trade.euro_price[13],
			sg->nation[i].trade.euro_price[14],
			sg->nation[i].trade.euro_price[15],
		};
		j["nation_list"][i]["trade"]["euro_price"]["value"] = sg_nation_trade_euro_price;
        int32_t sg_nation_trade_gold[] = {
			sg->nation[i].trade.gold[0],
			sg->nation[i].trade.gold[1],
			sg->nation[i].trade.gold[2],
			sg->nation[i].trade.gold[3],
			sg->nation[i].trade.gold[4],
			sg->nation[i].trade.gold[5],
			sg->nation[i].trade.gold[6],
			sg->nation[i].trade.gold[7],
			sg->nation[i].trade.gold[8],
			sg->nation[i].trade.gold[9],
			sg->nation[i].trade.gold[10],
			sg->nation[i].trade.gold[11],
			sg->nation[i].trade.gold[12],
			sg->nation[i].trade.gold[13],
			sg->nation[i].trade.gold[14],
			sg->nation[i].trade.gold[15],
		};
		j["nation_list"][i]["trade"]["gold"]["value"] = sg_nation_trade_gold;
        int16_t sg_nation_trade_nr[] = {
			sg->nation[i].trade.nr[0],
			sg->nation[i].trade.nr[1],
			sg->nation[i].trade.nr[2],
			sg->nation[i].trade.nr[3],
			sg->nation[i].trade.nr[4],
			sg->nation[i].trade.nr[5],
			sg->nation[i].trade.nr[6],
			sg->nation[i].trade.nr[7],
			sg->nation[i].trade.nr[8],
			sg->nation[i].trade.nr[9],
			sg->nation[i].trade.nr[10],
			sg->nation[i].trade.nr[11],
			sg->nation[i].trade.nr[12],
			sg->nation[i].trade.nr[13],
			sg->nation[i].trade.nr[14],
			sg->nation[i].trade.nr[15],
		};
		j["nation_list"][i]["trade"]["nr"]["value"] = sg_nation_trade_nr;
        int32_t sg_nation_trade_tons[] = {
			sg->nation[i].trade.tons[0],
			sg->nation[i].trade.tons[1],
			sg->nation[i].trade.tons[2],
			sg->nation[i].trade.tons[3],
			sg->nation[i].trade.tons[4],
			sg->nation[i].trade.tons[5],
			sg->nation[i].trade.tons[6],
			sg->nation[i].trade.tons[7],
			sg->nation[i].trade.tons[8],
			sg->nation[i].trade.tons[9],
			sg->nation[i].trade.tons[10],
			sg->nation[i].trade.tons[11],
			sg->nation[i].trade.tons[12],
			sg->nation[i].trade.tons[13],
			sg->nation[i].trade.tons[14],
			sg->nation[i].trade.tons[15],
		};
		j["nation_list"][i]["trade"]["tons"]["value"] = sg_nation_trade_tons;
        int32_t sg_nation_trade_tons2[] = {
			sg->nation[i].trade.tons2[0],
			sg->nation[i].trade.tons2[1],
			sg->nation[i].trade.tons2[2],
			sg->nation[i].trade.tons2[3],
			sg->nation[i].trade.tons2[4],
			sg->nation[i].trade.tons2[5],
			sg->nation[i].trade.tons2[6],
			sg->nation[i].trade.tons2[7],
			sg->nation[i].trade.tons2[8],
			sg->nation[i].trade.tons2[9],
			sg->nation[i].trade.tons2[10],
			sg->nation[i].trade.tons2[11],
			sg->nation[i].trade.tons2[12],
			sg->nation[i].trade.tons2[13],
			sg->nation[i].trade.tons2[14],
			sg->nation[i].trade.tons2[15],
		};
		j["nation_list"][i]["trade"]["tons2"]["value"] = sg_nation_trade_tons2;
        j["nation_list"][i]["unk0"]["value"] = (uint8_t) sg->nation[i].unk0;
        j["nation_list"][i]["unk1"]["value"] = (uint8_t) sg->nation[i].unk1;
        uint8_t sg_nation_unk2[] = {
			sg->nation[i].unk2[0],
			sg->nation[i].unk2[1],
			sg->nation[i].unk2[2],
			sg->nation[i].unk2[3],
			sg->nation[i].unk2[4],
		};
		j["nation_list"][i]["unk2"]["value"] = sg_nation_unk2;
        uint8_t sg_nation_unk3[] = {
			sg->nation[i].unk3[0],
			sg->nation[i].unk3[1],
		};
		j["nation_list"][i]["unk3"]["value"] = sg_nation_unk3;
        uint8_t sg_nation_unk4[] = {
			sg->nation[i].unk4[0],
			sg->nation[i].unk4[1],
			sg->nation[i].unk4[2],
			sg->nation[i].unk4[3],
			sg->nation[i].unk4[4],
		};
		j["nation_list"][i]["unk4"]["value"] = sg_nation_unk4;
        uint8_t sg_nation_unk5[] = {
			sg->nation[i].unk5[0],
			sg->nation[i].unk5[1],
			sg->nation[i].unk5[2],
			sg->nation[i].unk5[3],
			sg->nation[i].unk5[4],
			sg->nation[i].unk5[5],
			sg->nation[i].unk5[6],
			sg->nation[i].unk5[7],
		};
		j["nation_list"][i]["unk5"]["value"] = sg_nation_unk5;
        int16_t sg_nation_unk6[] = {
			sg->nation[i].unk6[0],
			sg->nation[i].unk6[1],
			sg->nation[i].unk6[2],
			sg->nation[i].unk6[3],
		};
		j["nation_list"][i]["unk6"]["value"] = sg_nation_unk6;
        uint8_t sg_nation_unk7[] = {
			sg->nation[i].unk7[0],
			sg->nation[i].unk7[1],
			sg->nation[i].unk7[2],
			sg->nation[i].unk7[3],
			sg->nation[i].unk7[4],
			sg->nation[i].unk7[5],
			sg->nation[i].unk7[6],
			sg->nation[i].unk7[7],
			sg->nation[i].unk7[8],
			sg->nation[i].unk7[9],
			sg->nation[i].unk7[10],
			sg->nation[i].unk7[11],
		};
		j["nation_list"][i]["unk7"]["value"] = sg_nation_unk7;
        j["nation_list"][i]["villages_burned"]["value"] = (uint8_t) sg->nation[i].villages_burned;
    }
    return j;
}


json merge_json_indian_list(   const struct savegame *sg, json j )
{
    json base = j["indian"];

    for (int i = 0; i < sg->count.indian; ++i) {
        j["indian_list"][i] = base;
                j["indian_list"][i]["_label"] = indian_list[i];

        uint16_t sg_indian_alarm_by_player[] = {
			sg->indian[i].alarm_by_player[0],
			sg->indian[i].alarm_by_player[1],
			sg->indian[i].alarm_by_player[2],
			sg->indian[i].alarm_by_player[3],
		};
		j["indian_list"][i]["alarm_by_player"]["value"] = sg_indian_alarm_by_player;
        uint8_t sg_indian_met_by_player[] = {
			sg->indian[i].met_by_player[0],
			sg->indian[i].met_by_player[1],
			sg->indian[i].met_by_player[2],
			sg->indian[i].met_by_player[3],
		};
		j["indian_list"][i]["met_by_player"]["value"] = sg_indian_met_by_player;
        j["indian_list"][i]["unk0"]["value"] = sg->indian[i].unk0;
        uint8_t sg_indian_unk1[] = {
			sg->indian[i].unk1[0],
			sg->indian[i].unk1[1],
			sg->indian[i].unk1[2],
			sg->indian[i].unk1[3],
			sg->indian[i].unk1[4],
			sg->indian[i].unk1[5],
			sg->indian[i].unk1[6],
			sg->indian[i].unk1[7],
		};
		j["indian_list"][i]["unk1"]["value"] = sg_indian_unk1;
    }
    return j;
}


json merge_json_colony_list(   const struct savegame *sg, json j )
{
    json base = j["colony"];

    for (int i = 0; i < sg->count.colony; ++i) {
        j["colony_list"][i] = base;
        
        j["colony_list"][i]["building_in_production"]["value"] = (uint8_t) sg->colony[i].building_in_production;
        j["colony_list"][i]["buildings"]["armory"]["value"] = (uint32_t) sg->colony[i].buildings.armory;
        j["colony_list"][i]["buildings"]["blacksmiths_house"]["value"] = (uint16_t) sg->colony[i].buildings.blacksmiths_house;
        j["colony_list"][i]["buildings"]["capitol"]["value"] = (uint32_t) sg->colony[i].buildings.capitol;
        j["colony_list"][i]["buildings"]["carpenters_shop"]["value"] = (uint16_t) sg->colony[i].buildings.carpenters_shop;
        j["colony_list"][i]["buildings"]["church"]["value"] = (uint16_t) sg->colony[i].buildings.church;
        j["colony_list"][i]["buildings"]["custom_house"]["value"] = (uint32_t) sg->colony[i].buildings.custom_house;
        j["colony_list"][i]["buildings"]["docks"]["value"] = (uint32_t) sg->colony[i].buildings.docks;
        j["colony_list"][i]["buildings"]["fur_traders_house"]["value"] = (uint16_t) sg->colony[i].buildings.fur_traders_house;
        j["colony_list"][i]["buildings"]["printing_press"]["value"] = (uint32_t) sg->colony[i].buildings.printing_press;
        j["colony_list"][i]["buildings"]["rum_distillers_house"]["value"] = (uint32_t) sg->colony[i].buildings.rum_distillers_house;
        j["colony_list"][i]["buildings"]["schoolhouse"]["value"] = (uint32_t) sg->colony[i].buildings.schoolhouse;
        j["colony_list"][i]["buildings"]["stables"]["value"] = (uint32_t) sg->colony[i].buildings.stables;
        j["colony_list"][i]["buildings"]["stockade"]["value"] = (uint32_t) sg->colony[i].buildings.stockade;
        j["colony_list"][i]["buildings"]["tobacconists_house"]["value"] = (uint32_t) sg->colony[i].buildings.tobacconists_house;
        j["colony_list"][i]["buildings"]["town_hall"]["value"] = (uint32_t) sg->colony[i].buildings.town_hall;
        j["colony_list"][i]["buildings"]["unused"]["value"] = (uint16_t) sg->colony[i].buildings.unused;
        j["colony_list"][i]["buildings"]["warehouse"]["value"] = (uint32_t) sg->colony[i].buildings.warehouse;
        j["colony_list"][i]["buildings"]["weavers_house"]["value"] = (uint32_t) sg->colony[i].buildings.weavers_house;
        j["colony_list"][i]["custom_house"]["cigars"]["value"] = (uint16_t) sg->colony[i].custom_house.cigars;
        j["colony_list"][i]["custom_house"]["cloth"]["value"] = (uint16_t) sg->colony[i].custom_house.cloth;
        j["colony_list"][i]["custom_house"]["coats"]["value"] = (uint16_t) sg->colony[i].custom_house.coats;
        j["colony_list"][i]["custom_house"]["cotton"]["value"] = (uint16_t) sg->colony[i].custom_house.cotton;
        j["colony_list"][i]["custom_house"]["food"]["value"] = (uint16_t) sg->colony[i].custom_house.food;
        j["colony_list"][i]["custom_house"]["furs"]["value"] = (uint16_t) sg->colony[i].custom_house.furs;
        j["colony_list"][i]["custom_house"]["horses"]["value"] = (uint16_t) sg->colony[i].custom_house.horses;
        j["colony_list"][i]["custom_house"]["lumber"]["value"] = (uint16_t) sg->colony[i].custom_house.lumber;
        j["colony_list"][i]["custom_house"]["muskets"]["value"] = (uint16_t) sg->colony[i].custom_house.muskets;
        j["colony_list"][i]["custom_house"]["ore"]["value"] = (uint16_t) sg->colony[i].custom_house.ore;
        j["colony_list"][i]["custom_house"]["rum"]["value"] = (uint16_t) sg->colony[i].custom_house.rum;
        j["colony_list"][i]["custom_house"]["silver"]["value"] = (uint16_t) sg->colony[i].custom_house.silver;
        j["colony_list"][i]["custom_house"]["sugar"]["value"] = (uint16_t) sg->colony[i].custom_house.sugar;
        j["colony_list"][i]["custom_house"]["tobacco"]["value"] = (uint16_t) sg->colony[i].custom_house.tobacco;
        j["colony_list"][i]["custom_house"]["tools"]["value"] = (uint16_t) sg->colony[i].custom_house.tools;
        j["colony_list"][i]["custom_house"]["trade_goods"]["value"] = (uint16_t) sg->colony[i].custom_house.trade_goods;
        j["colony_list"][i]["hammers"]["value"] = (uint16_t) sg->colony[i].hammers;
        j["colony_list"][i]["name"]["value"] = sg->colony[i].name;
        j["colony_list"][i]["nation"]["value"] = (uint8_t) sg->colony[i].nation;
        j["colony_list"][i]["occupation"]["value"] = sg->colony[i].occupation;
        j["colony_list"][i]["population"]["value"] = (uint8_t) sg->colony[i].population;
        j["colony_list"][i]["profession"]["value"] = sg->colony[i].profession;
        j["colony_list"][i]["rebel_dividend"]["value"] = (uint32_t) sg->colony[i].rebel_dividend;
        j["colony_list"][i]["rebel_divisor"]["value"] = (uint32_t) sg->colony[i].rebel_divisor;
        uint16_t sg_colony_stock[] = {
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
		j["colony_list"][i]["stock"]["value"] = sg_colony_stock;
        int8_t sg_colony_tiles[] = {
			sg->colony[i].tiles[0],
			sg->colony[i].tiles[1],
			sg->colony[i].tiles[2],
			sg->colony[i].tiles[3],
			sg->colony[i].tiles[4],
			sg->colony[i].tiles[5],
			sg->colony[i].tiles[6],
			sg->colony[i].tiles[7],
		};
		j["colony_list"][i]["tiles"]["value"] = sg_colony_tiles;
        uint8_t sg_colony_unk0[] = {
			sg->colony[i].unk0[0],
			sg->colony[i].unk0[1],
			sg->colony[i].unk0[2],
			sg->colony[i].unk0[3],
		};
		j["colony_list"][i]["unk0"]["value"] = sg_colony_unk0;
        uint8_t sg_colony_unk6[] = {
			sg->colony[i].unk6[0],
			sg->colony[i].unk6[1],
			sg->colony[i].unk6[2],
			sg->colony[i].unk6[3],
			sg->colony[i].unk6[4],
			sg->colony[i].unk6[5],
			sg->colony[i].unk6[6],
			sg->colony[i].unk6[7],
			sg->colony[i].unk6[8],
			sg->colony[i].unk6[9],
			sg->colony[i].unk6[10],
			sg->colony[i].unk6[11],
			sg->colony[i].unk6[12],
			sg->colony[i].unk6[13],
			sg->colony[i].unk6[14],
			sg->colony[i].unk6[15],
		};
		j["colony_list"][i]["unk6"]["value"] = sg_colony_unk6;
        uint8_t sg_colony_unk8[] = {
			sg->colony[i].unk8[0],
			sg->colony[i].unk8[1],
			sg->colony[i].unk8[2],
			sg->colony[i].unk8[3],
			sg->colony[i].unk8[4],
			sg->colony[i].unk8[5],
			sg->colony[i].unk8[6],
			sg->colony[i].unk8[7],
			sg->colony[i].unk8[8],
			sg->colony[i].unk8[9],
			sg->colony[i].unk8[10],
			sg->colony[i].unk8[11],
		};
		j["colony_list"][i]["unk8"]["value"] = sg_colony_unk8;
        uint8_t sg_colony_unka[] = {
			sg->colony[i].unka[0],
			sg->colony[i].unka[1],
			sg->colony[i].unka[2],
			sg->colony[i].unka[3],
			sg->colony[i].unka[4],
			sg->colony[i].unka[5],
		};
		j["colony_list"][i]["unka"]["value"] = sg_colony_unka;
        uint8_t sg_colony_unkb[] = {
			sg->colony[i].unkb[0],
			sg->colony[i].unkb[1],
			sg->colony[i].unkb[2],
			sg->colony[i].unkb[3],
			sg->colony[i].unkb[4],
		};
		j["colony_list"][i]["unkb"]["value"] = sg_colony_unkb;
        uint8_t sg_colony_unkd[] = {
			sg->colony[i].unkd[0],
			sg->colony[i].unkd[1],
			sg->colony[i].unkd[2],
			sg->colony[i].unkd[3],
			sg->colony[i].unkd[4],
			sg->colony[i].unkd[5],
			sg->colony[i].unkd[6],
			sg->colony[i].unkd[7],
		};
		j["colony_list"][i]["unkd"]["value"] = sg_colony_unkd;
        j["colony_list"][i]["x"]["value"] = (uint8_t) sg->colony[i].x;
        j["colony_list"][i]["y"]["value"] = (uint8_t) sg->colony[i].y;
    }
    return j;
}


json merge_json_unit_list(   const struct savegame *sg, json j )
{
    json base = j["unit"];

    for (int i = 0; i < sg->count.unit; ++i) {
        j["unit_list"][i] = base;
        
        uint8_t sg_unit_cargo_hold[] = {
			sg->unit[i].cargo_hold[0],
			sg->unit[i].cargo_hold[1],
			sg->unit[i].cargo_hold[2],
			sg->unit[i].cargo_hold[3],
			sg->unit[i].cargo_hold[4],
			sg->unit[i].cargo_hold[5],
		};
		j["unit_list"][i]["cargo_hold"]["value"] = sg_unit_cargo_hold;
        j["unit_list"][i]["cargo_item_0"]["value"] = (uint8_t) sg->unit[i].cargo_item_0;
        j["unit_list"][i]["cargo_item_1"]["value"] = (uint8_t) sg->unit[i].cargo_item_1;
        j["unit_list"][i]["cargo_item_2"]["value"] = (uint8_t) sg->unit[i].cargo_item_2;
        j["unit_list"][i]["cargo_item_3"]["value"] = (uint8_t) sg->unit[i].cargo_item_3;
        j["unit_list"][i]["cargo_item_4"]["value"] = (uint8_t) sg->unit[i].cargo_item_4;
        j["unit_list"][i]["cargo_item_5"]["value"] = (uint8_t) sg->unit[i].cargo_item_5;
        j["unit_list"][i]["holds_occupied"]["value"] = (uint8_t) sg->unit[i].holds_occupied;
        j["unit_list"][i]["moves"]["value"] = (uint8_t) sg->unit[i].moves;
        j["unit_list"][i]["nation"]["value"] = (uint8_t) sg->unit[i].nation;
        j["unit_list"][i]["order"]["value"] = (uint8_t) sg->unit[i].order;
        j["unit_list"][i]["profession"]["value"] = (uint8_t) sg->unit[i].profession;
        j["unit_list"][i]["transport_chain"]["next_unit_idx"]["value"] = (int16_t) sg->unit[i].transport_chain.next_unit_idx;
        j["unit_list"][i]["transport_chain"]["prev_unit_idx"]["value"] = (int16_t) sg->unit[i].transport_chain.prev_unit_idx;
        j["unit_list"][i]["turns_worked"]["value"] = (uint8_t) sg->unit[i].turns_worked;
        j["unit_list"][i]["type"]["value"] = (uint8_t) sg->unit[i].type;
        j["unit_list"][i]["unk04"]["value"] = (uint8_t) sg->unit[i].unk04;
        j["unit_list"][i]["unk05"]["value"] = (uint8_t) sg->unit[i].unk05;
        j["unit_list"][i]["unk06"]["value"] = (uint8_t) sg->unit[i].unk06;
        j["unit_list"][i]["unk07"]["value"] = (uint8_t) sg->unit[i].unk07;
        uint8_t sg_unit_unk08[] = {
			sg->unit[i].unk08[0],
			sg->unit[i].unk08[1],
			sg->unit[i].unk08[2],
		};
		j["unit_list"][i]["unk08"]["value"] = sg_unit_unk08;
        j["unit_list"][i]["x"]["value"] = (uint8_t) sg->unit[i].x;
        j["unit_list"][i]["y"]["value"] = (uint8_t) sg->unit[i].y;
    }
    return j;
}


json merge_json_tribe_list(   const struct savegame *sg, json j )
{
    json base = j["tribe"];

    for (int i = 0; i < sg->count.tribe; ++i) {
        j["tribe_list"][i] = base;
        
        j["tribe_list"][i]["mission"]["value"] = (int8_t) sg->tribe[i].mission;
        j["tribe_list"][i]["nation"]["value"] = (uint8_t) sg->tribe[i].nation;
        j["tribe_list"][i]["panic"]["value"] = (uint8_t) sg->tribe[i].panic;
        j["tribe_list"][i]["population"]["value"] = (uint8_t) sg->tribe[i].population;
        j["tribe_list"][i]["population_loss_in_current_turn"]["value"] = (uint8_t) sg->tribe[i].population_loss_in_current_turn;
        j["tribe_list"][i]["state"]["artillery"]["value"] = (uint8_t) sg->tribe[i].state.artillery;
        j["tribe_list"][i]["state"]["capital"]["value"] = (uint8_t) sg->tribe[i].state.capital;
        j["tribe_list"][i]["state"]["learned"]["value"] = (uint8_t) sg->tribe[i].state.learned;
        j["tribe_list"][i]["state"]["scouted"]["value"] = (uint8_t) sg->tribe[i].state.scouted;
        j["tribe_list"][i]["state"]["unk5"]["value"] = (uint8_t) sg->tribe[i].state.unk5;
        j["tribe_list"][i]["state"]["unk6"]["value"] = (uint8_t) sg->tribe[i].state.unk6;
        j["tribe_list"][i]["state"]["unk7"]["value"] = (uint8_t) sg->tribe[i].state.unk7;
        j["tribe_list"][i]["state"]["unk8"]["value"] = (uint8_t) sg->tribe[i].state.unk8;
        uint8_t sg_tribe_unk1[] = {
			sg->tribe[i].unk1[0],
			sg->tribe[i].unk1[1],
			sg->tribe[i].unk1[2],
			sg->tribe[i].unk1[3],
		};
		j["tribe_list"][i]["unk1"]["value"] = sg_tribe_unk1;
        uint8_t sg_tribe_unk2[] = {
			sg->tribe[i].unk2[0],
			sg->tribe[i].unk2[1],
			sg->tribe[i].unk2[2],
			sg->tribe[i].unk2[3],
			sg->tribe[i].unk2[4],
			sg->tribe[i].unk2[5],
		};
		j["tribe_list"][i]["unk2"]["value"] = sg_tribe_unk2;
        j["tribe_list"][i]["x"]["value"] = (uint8_t) sg->tribe[i].x;
        j["tribe_list"][i]["y"]["value"] = (uint8_t) sg->tribe[i].y;
    }
    return j;
}


json json_base() {
    auto j = R"(
{
   "player" : {
      "unk00" : {
         "hints" : "",
         "order" : 96,
         "bits" : {
            "type" : "uint8_t",
            "total" : "8",
            "array_items" : 0
         }
      },
      "diplomacy" : {
         "order" : 99,
         "bits" : {
            "total" : "8",
            "array_items" : 0,
            "type" : "uint8_t"
         },
         "hints" : ""
      },
      "control" : {
         "bits" : {
            "total" : "8",
            "array_items" : 0,
            "type" : "uint8_t"
         },
         "order" : 97,
         "hints" : " enum { PLAYER = 0, AI = 1 };"
      },
      "name" : {
         "hints" : "",
         "order" : 94,
         "bits" : {
            "type" : "char",
            "total" : 192,
            "array_items" : 24
         }
      },
      "founded_colonies" : {
         "order" : 98,
         "bits" : {
            "array_items" : 0,
            "total" : "8",
            "type" : "uint8_t"
         },
         "hints" : " // founded colonies, probably used pick next colony name"
      },
      "country" : {
         "hints" : "",
         "bits" : {
            "total" : 192,
            "array_items" : 24,
            "type" : "char"
         },
         "order" : 95
      }
   },
   "tribe" : {
      "x" : {
         "bits" : {
            "array_items" : 0,
            "total" : "8",
            "type" : "uint8_t"
         },
         "order" : 204,
         "hints" : ""
      },
      "mission" : {
         "hints" : " //ff if none, 0 1 2 3 = eng fra spa dut",
         "bits" : {
            "total" : "8",
            "array_items" : 0,
            "type" : "int8_t"
         },
         "order" : 216
      },
      "panic" : {
         "hints" : "",
         "bits" : {
            "array_items" : 0,
            "total" : "8",
            "type" : "uint8_t"
         },
         "order" : 218
      },
      "unk1" : {
         "bits" : {
            "type" : "uint8_t",
            "total" : 32,
            "array_items" : 4
         },
         "order" : 217,
         "hints" : ""
      },
      "population_loss_in_current_turn" : {
         "hints" : " //due to attacks",
         "bits" : {
            "total" : "8",
            "array_items" : 0,
            "type" : "uint8_t"
         },
         "order" : 220
      },
      "y" : {
         "order" : 205,
         "bits" : {
            "type" : "uint8_t",
            "total" : "8",
            "array_items" : 0
         },
         "hints" : ""
      },
      "state" : {
         "unk7" : {
            "order" : 213,
            "bits" : {
               "type" : "uint8_t",
               "total" : "1",
               "array_items" : 0
            },
            "hints" : ""
         },
         "capital" : {
            "hints" : "",
            "bits" : {
               "array_items" : 0,
               "total" : "1",
               "type" : "uint8_t"
            },
            "order" : 209
         },
         "artillery" : {
            "order" : 207,
            "bits" : {
               "type" : "uint8_t",
               "array_items" : 0,
               "total" : "1"
            },
            "hints" : " //artillery has been nearby?"
         },
         "unk5" : {
            "order" : 211,
            "bits" : {
               "type" : "uint8_t",
               "total" : "1",
               "array_items" : 0
            },
            "hints" : ""
         },
         "learned" : {
            "order" : 208,
            "bits" : {
               "array_items" : 0,
               "total" : "1",
               "type" : "uint8_t"
            },
            "hints" : " //visited and learned skill"
         },
         "unk6" : {
            "hints" : "",
            "order" : 212,
            "bits" : {
               "array_items" : 0,
               "total" : "1",
               "type" : "uint8_t"
            }
         },
         "scouted" : {
            "hints" : " //visited by scout",
            "bits" : {
               "type" : "uint8_t",
               "array_items" : 0,
               "total" : "1"
            },
            "order" : 210
         },
         "unk8" : {
            "hints" : "",
            "order" : 214,
            "bits" : {
               "type" : "uint8_t",
               "total" : "1",
               "array_items" : 0
            }
         }
      },
      "population" : {
         "hints" : "",
         "order" : 215,
         "bits" : {
            "type" : "uint8_t",
            "total" : "8",
            "array_items" : 0
         }
      },
      "unk2" : {
         "order" : 219,
         "bits" : {
            "type" : "uint8_t",
            "array_items" : 6,
            "total" : 48
         },
         "hints" : ""
      },
      "nation" : {
         "order" : 206,
         "bits" : {
            "type" : "uint8_t",
            "array_items" : 0,
            "total" : "8"
         },
         "hints" : ""
      }
   },
   "colony" : {
      "custom_house" : {
         "ore" : {
            "hints" : "",
            "order" : 136,
            "bits" : {
               "array_items" : 0,
               "total" : "1",
               "type" : "uint16_t"
            }
         },
         "cotton" : {
            "hints" : "",
            "order" : 133,
            "bits" : {
               "type" : "uint16_t",
               "total" : "1",
               "array_items" : 0
            }
         },
         "cloth" : {
            "order" : 141,
            "bits" : {
               "total" : "1",
               "array_items" : 0,
               "type" : "uint16_t"
            },
            "hints" : ""
         },
         "rum" : {
            "hints" : "",
            "bits" : {
               "type" : "uint16_t",
               "total" : "1",
               "array_items" : 0
            },
            "order" : 139
         },
         "muskets" : {
            "hints" : "",
            "bits" : {
               "array_items" : 0,
               "total" : "1",
               "type" : "uint16_t"
            },
            "order" : 145
         },
         "tools" : {
            "hints" : "",
            "order" : 144,
            "bits" : {
               "total" : "1",
               "array_items" : 0,
               "type" : "uint16_t"
            }
         },
         "silver" : {
            "hints" : "",
            "bits" : {
               "array_items" : 0,
               "total" : "1",
               "type" : "uint16_t"
            },
            "order" : 137
         },
         "coats" : {
            "hints" : "",
            "bits" : {
               "type" : "uint16_t",
               "array_items" : 0,
               "total" : "1"
            },
            "order" : 142
         },
         "horses" : {
            "bits" : {
               "type" : "uint16_t",
               "total" : "1",
               "array_items" : 0
            },
            "order" : 138,
            "hints" : ""
         },
         "sugar" : {
            "hints" : "",
            "bits" : {
               "type" : "uint16_t",
               "total" : "1",
               "array_items" : 0
            },
            "order" : 131
         },
         "tobacco" : {
            "bits" : {
               "type" : "uint16_t",
               "array_items" : 0,
               "total" : "1"
            },
            "order" : 132,
            "hints" : ""
         },
         "furs" : {
            "hints" : "",
            "order" : 134,
            "bits" : {
               "type" : "uint16_t",
               "array_items" : 0,
               "total" : "1"
            }
         },
         "cigars" : {
            "order" : 140,
            "bits" : {
               "type" : "uint16_t",
               "total" : "1",
               "array_items" : 0
            },
            "hints" : ""
         },
         "trade_goods" : {
            "bits" : {
               "type" : "uint16_t",
               "total" : "1",
               "array_items" : 0
            },
            "order" : 143,
            "hints" : ""
         },
         "lumber" : {
            "bits" : {
               "type" : "uint16_t",
               "total" : "1",
               "array_items" : 0
            },
            "order" : 135,
            "hints" : ""
         },
         "food" : {
            "bits" : {
               "array_items" : 0,
               "total" : "1",
               "type" : "uint16_t"
            },
            "order" : 130,
            "hints" : ""
         }
      },
      "buildings" : {
         "stables" : {
            "hints" : "",
            "order" : 118,
            "bits" : {
               "array_items" : 0,
               "total" : "1",
               "type" : "uint32_t"
            }
         },
         "blacksmiths_house" : {
            "hints" : "",
            "order" : 128,
            "bits" : {
               "type" : "uint16_t",
               "total" : "3",
               "array_items" : 0
            }
         },
         "town_hall" : {
            "hints" : "",
            "order" : 115,
            "bits" : {
               "type" : "uint32_t",
               "total" : "3",
               "array_items" : 0
            }
         },
         "docks" : {
            "hints" : "",
            "order" : 114,
            "bits" : {
               "array_items" : 0,
               "total" : "3",
               "type" : "uint32_t"
            }
         },
         "capitol" : {
            "hints" : " /* not really in use */",
            "order" : 124,
            "bits" : {
               "type" : "uint32_t",
               "array_items" : 0,
               "total" : "2"
            }
         },
         "printing_press" : {
            "hints" : "",
            "order" : 120,
            "bits" : {
               "array_items" : 0,
               "total" : "2",
               "type" : "uint32_t"
            }
         },
         "tobacconists_house" : {
            "order" : 122,
            "bits" : {
               "total" : "3",
               "array_items" : 0,
               "type" : "uint32_t"
            },
            "hints" : ""
         },
         "rum_distillers_house" : {
            "bits" : {
               "array_items" : 0,
               "total" : "3",
               "type" : "uint32_t"
            },
            "order" : 123,
            "hints" : ""
         },
         "stockade" : {
            "order" : 112,
            "bits" : {
               "total" : "3",
               "array_items" : 0,
               "type" : "uint32_t"
            },
            "hints" : ""
         },
         "carpenters_shop" : {
            "hints" : "",
            "order" : 126,
            "bits" : {
               "type" : "uint16_t",
               "array_items" : 0,
               "total" : "2"
            }
         },
         "schoolhouse" : {
            "hints" : "",
            "bits" : {
               "type" : "uint32_t",
               "array_items" : 0,
               "total" : "3"
            },
            "order" : 116
         },
         "unused" : {
            "order" : 129,
            "bits" : {
               "type" : "uint16_t",
               "total" : "6",
               "array_items" : 0
            },
            "hints" : ""
         },
         "fur_traders_house" : {
            "hints" : "",
            "order" : 125,
            "bits" : {
               "array_items" : 0,
               "total" : "3",
               "type" : "uint16_t"
            }
         },
         "church" : {
            "bits" : {
               "total" : "2",
               "array_items" : 0,
               "type" : "uint16_t"
            },
            "order" : 127,
            "hints" : ""
         },
         "warehouse" : {
            "hints" : "",
            "bits" : {
               "total" : "2",
               "array_items" : 0,
               "type" : "uint32_t"
            },
            "order" : 117
         },
         "weavers_house" : {
            "hints" : "",
            "bits" : {
               "total" : "3",
               "array_items" : 0,
               "type" : "uint32_t"
            },
            "order" : 121
         },
         "armory" : {
            "hints" : "",
            "bits" : {
               "type" : "uint32_t",
               "total" : "3",
               "array_items" : 0
            },
            "order" : 113
         },
         "custom_house" : {
            "bits" : {
               "type" : "uint32_t",
               "total" : "1",
               "array_items" : 0
            },
            "order" : 119,
            "hints" : ""
         }
      },
      "rebel_dividend" : {
         "hints" : "",
         "bits" : {
            "array_items" : 0,
            "total" : "32",
            "type" : "uint32_t"
         },
         "order" : 152
      },
      "y" : {
         "hints" : "",
         "order" : 102,
         "bits" : {
            "total" : "8",
            "array_items" : 0,
            "type" : "uint8_t"
         }
      },
      "unka" : {
         "order" : 146,
         "bits" : {
            "type" : "uint8_t",
            "total" : 48,
            "array_items" : 6
         },
         "hints" : ""
      },
      "unkd" : {
         "hints" : "",
         "bits" : {
            "type" : "uint8_t",
            "array_items" : 8,
            "total" : 64
         },
         "order" : 151
      },
      "rebel_divisor" : {
         "bits" : {
            "array_items" : 0,
            "total" : "32",
            "type" : "uint32_t"
         },
         "order" : 153,
         "hints" : ""
      },
      "unkb" : {
         "hints" : "",
         "order" : 149,
         "bits" : {
            "type" : "uint8_t",
            "array_items" : 5,
            "total" : 40
         }
      },
      "name" : {
         "bits" : {
            "type" : "char",
            "array_items" : 24,
            "total" : 192
         },
         "order" : 103,
         "hints" : ""
      },
      "x" : {
         "hints" : "",
         "bits" : {
            "total" : "8",
            "array_items" : 0,
            "type" : "uint8_t"
         },
         "order" : 101
      },
      "unk8" : {
         "hints" : "",
         "bits" : {
            "type" : "uint8_t",
            "array_items" : 12,
            "total" : 96
         },
         "order" : 111
      },
      "building_in_production" : {
         "order" : 148,
         "bits" : {
            "type" : "uint8_t",
            "array_items" : 0,
            "total" : "8"
         },
         "hints" : ""
      },
      "unk6" : {
         "hints" : "",
         "bits" : {
            "type" : "uint8_t",
            "total" : 128,
            "array_items" : 16
         },
         "order" : 109
      },
      "nation" : {
         "order" : 104,
         "bits" : {
            "type" : "uint8_t",
            "total" : "8",
            "array_items" : 0
         },
         "hints" : ""
      },
      "stock" : {
         "hints" : "",
         "bits" : {
            "total" : 256,
            "array_items" : 16,
            "type" : "uint16_t"
         },
         "order" : 150
      },
      "occupation" : {
         "hints" : "",
         "bits" : {
            "type" : "uint8_t",
            "array_items" : 32,
            "total" : 256
         },
         "order" : 107
      },
      "unk0" : {
         "hints" : "",
         "bits" : {
            "array_items" : 4,
            "total" : 32,
            "type" : "uint8_t"
         },
         "order" : 105
      },
      "hammers" : {
         "hints" : "",
         "order" : 147,
         "bits" : {
            "total" : "16",
            "array_items" : 0,
            "type" : "uint16_t"
         }
      },
      "profession" : {
         "bits" : {
            "type" : "uint8_t",
            "array_items" : 32,
            "total" : 256
         },
         "order" : 108,
         "hints" : ""
      },
      "population" : {
         "hints" : "",
         "bits" : {
            "array_items" : 0,
            "total" : "8",
            "type" : "uint8_t"
         },
         "order" : 106
      },
      "tiles" : {
         "hints" : " //represents tiles around the colony. idx to citizen.",
         "bits" : {
            "type" : "int8_t",
            "total" : 64,
            "array_items" : 8
         },
         "order" : 110
      }
   },
   "stuff" : {
      "viewport_y" : {
         "bits" : {
            "total" : "16",
            "array_items" : 0,
            "type" : "uint16_t"
         },
         "order" : 235,
         "hints" : ""
      },
      "counter_increasing_on_new_colony" : {
         "hints" : "",
         "bits" : {
            "total" : "16",
            "array_items" : 0,
            "type" : "uint16_t"
         },
         "order" : 228
      },
      "unk_short" : {
         "bits" : {
            "total" : "16",
            "array_items" : 0,
            "type" : "uint16_t"
         },
         "order" : 227,
         "hints" : ""
      },
      "x" : {
         "bits" : {
            "array_items" : 0,
            "total" : "16",
            "type" : "uint16_t"
         },
         "order" : 230,
         "hints" : ""
      },
      "unk7" : {
         "hints" : "",
         "bits" : {
            "total" : "8",
            "array_items" : 0,
            "type" : "uint8_t"
         },
         "order" : 233
      },
      "zoom_level" : {
         "hints" : "",
         "order" : 232,
         "bits" : {
            "type" : "uint8_t",
            "total" : "8",
            "array_items" : 0
         }
      },
      "unk_big" : {
         "bits" : {
            "type" : "uint8_t",
            "array_items" : 696,
            "total" : 5568
         },
         "order" : 229,
         "hints" : ""
      },
      "counter_decreasing_on_new_colony" : {
         "order" : 226,
         "bits" : {
            "array_items" : 0,
            "total" : "16",
            "type" : "uint16_t"
         },
         "hints" : ""
      },
      "unk15" : {
         "order" : 225,
         "bits" : {
            "array_items" : 15,
            "total" : 120,
            "type" : "uint8_t"
         },
         "hints" : ""
      },
      "y" : {
         "hints" : "",
         "bits" : {
            "total" : "16",
            "array_items" : 0,
            "type" : "uint16_t"
         },
         "order" : 231
      },
      "viewport_x" : {
         "order" : 234,
         "bits" : {
            "array_items" : 0,
            "total" : "16",
            "type" : "uint16_t"
         },
         "hints" : ""
      }
   },
   "nation" : {
      "tax_rate" : {
         "hints" : "",
         "order" : 178,
         "bits" : {
            "type" : "uint8_t",
            "total" : "8",
            "array_items" : 0
         }
      },
      "recruit_count" : {
         "hints" : " //recruit penalty 120 + (count * 20) (does not go above 180) ",
         "order" : 181,
         "bits" : {
            "total" : "8",
            "array_items" : 0,
            "type" : "uint8_t"
         }
      },
      "founding_father_count" : {
         "hints" : "",
         "order" : 187,
         "bits" : {
            "type" : "uint16_t",
            "total" : "16",
            "array_items" : 0
         }
      },
      "unk4" : {
         "order" : 190,
         "bits" : {
            "total" : 40,
            "array_items" : 5,
            "type" : "uint8_t"
         },
         "hints" : ""
      },
      "gold" : {
         "bits" : {
            "type" : "uint32_t",
            "total" : "32",
            "array_items" : 0
         },
         "order" : 194,
         "hints" : ""
      },
      "relation_by_indian" : {
         "bits" : {
            "type" : "uint8_t",
            "array_items" : 8,
            "total" : 64
         },
         "order" : 197,
         "hints" : " enum { NOT_MET = 0x00, WAR = 0x20, PEACE = 0x60};"
      },
      "unk0" : {
         "hints" : "",
         "order" : 177,
         "bits" : {
            "type" : "uint8_t",
            "total" : "8",
            "array_items" : 0
         }
      },
      "villages_burned" : {
         "hints" : "",
         "order" : 189,
         "bits" : {
            "type" : "uint8_t",
            "array_items" : 0,
            "total" : "8"
         }
      },
      "unk6" : {
         "hints" : "",
         "bits" : {
            "type" : "int16_t",
            "total" : 64,
            "array_items" : 4
         },
         "order" : 196
      },
      "recruit" : {
         "hints" : "",
         "bits" : {
            "type" : "uint8_t",
            "total" : 24,
            "array_items" : 3
         },
         "order" : 179
      },
      "unk3" : {
         "order" : 185,
         "bits" : {
            "array_items" : 2,
            "total" : 16,
            "type" : "uint8_t"
         },
         "hints" : ""
      },
      "unk7" : {
         "bits" : {
            "total" : 96,
            "array_items" : 12,
            "type" : "uint8_t"
         },
         "order" : 198,
         "hints" : ""
      },
      "ffc_high" : {
         "hints" : " //suspect founding_father_count is 32bit.",
         "bits" : {
            "type" : "uint16_t",
            "array_items" : 0,
            "total" : "16"
         },
         "order" : 188
      },
      "trade" : {
         "tons" : {
            "hints" : "",
            "order" : 202,
            "bits" : {
               "type" : "int32_t",
               "total" : 512,
               "array_items" : 16
            }
         },
         "nr" : {
            "hints" : "",
            "order" : 200,
            "bits" : {
               "type" : "int16_t",
               "total" : 256,
               "array_items" : 16
            }
         },
         "gold" : {
            "hints" : "",
            "order" : 201,
            "bits" : {
               "type" : "int32_t",
               "total" : 512,
               "array_items" : 16
            }
         },
         "tons2" : {
            "hints" : "",
            "order" : 203,
            "bits" : {
               "array_items" : 16,
               "total" : 512,
               "type" : "int32_t"
            }
         },
         "euro_price" : {
            "order" : 199,
            "bits" : {
               "type" : "uint8_t",
               "array_items" : 16,
               "total" : 128
            },
            "hints" : ""
         }
      },
      "unk2" : {
         "hints" : "",
         "bits" : {
            "type" : "uint8_t",
            "array_items" : 5,
            "total" : 40
         },
         "order" : 182
      },
      "liberty_bells_last_turn" : {
         "bits" : {
            "type" : "uint16_t",
            "array_items" : 0,
            "total" : "16"
         },
         "order" : 184,
         "hints" : ""
      },
      "next_founding_father" : {
         "bits" : {
            "array_items" : 0,
            "total" : "16",
            "type" : "int16_t"
         },
         "order" : 186,
         "hints" : ""
      },
      "artillery_count" : {
         "bits" : {
            "type" : "uint16_t",
            "total" : "16",
            "array_items" : 0
         },
         "order" : 191,
         "hints" : " //artillery purchased in europe. 500 + (count * 100) price penalty."
      },
      "unk1" : {
         "hints" : "",
         "order" : 180,
         "bits" : {
            "type" : "uint8_t",
            "total" : "8",
            "array_items" : 0
         }
      },
      "liberty_bells_total" : {
         "hints" : "",
         "bits" : {
            "total" : "16",
            "array_items" : 0,
            "type" : "uint16_t"
         },
         "order" : 183
      },
      "crosses" : {
         "order" : 195,
         "bits" : {
            "type" : "uint16_t",
            "total" : "16",
            "array_items" : 0
         },
         "hints" : ""
      },
      "boycott_bitmap" : {
         "hints" : "",
         "bits" : {
            "array_items" : 0,
            "total" : "16",
            "type" : "uint16_t"
         },
         "order" : 192
      },
      "unk5" : {
         "bits" : {
            "type" : "uint8_t",
            "array_items" : 8,
            "total" : 64
         },
         "order" : 193,
         "hints" : ""
      }
   },
   "other" : {
      "unkXX_xx" : {
         "bits" : {
            "type" : "uint8_t",
            "array_items" : 24,
            "total" : 192
         },
         "order" : 100,
         "hints" : ""
      }
   },
   "tail" : {
      "unk" : {
         "order" : 237,
         "bits" : {
            "type" : "uint8_t",
            "array_items" : 1502,
            "total" : 12016
         },
         "hints" : ""
      }
   },
   "map" : {
      "order" : 236,
      "bits" : {
         "type" : "uint8_t",
         "array_items" : 4176,
         "total" : 33408
      },
      "hints" : "// 56*70 visible + border, = 58*72 = 4176,"
   },
   "indian" : {
      "unk0" : {
         "hints" : "",
         "order" : 221,
         "bits" : {
            "total" : 464,
            "array_items" : 58,
            "type" : "uint8_t"
         }
      },
      "met_by_player" : {
         "bits" : {
            "type" : "uint8_t",
            "total" : 32,
            "array_items" : 4
         },
         "order" : 222,
         "hints" : ""
      },
      "alarm_by_player" : {
         "bits" : {
            "type" : "uint16_t",
            "array_items" : 4,
            "total" : 64
         },
         "order" : 224,
         "hints" : ""
      },
      "unk1" : {
         "bits" : {
            "type" : "uint8_t",
            "total" : 64,
            "array_items" : 8
         },
         "order" : 223,
         "hints" : " "
      }
   },
   "unit" : {
      "order" : {
         "order" : 163,
         "bits" : {
            "array_items" : 0,
            "total" : "8",
            "type" : "uint8_t"
         },
         "hints" : " enum { PLOW = 8, ROAD = 9 };"
      },
      "unk07" : {
         "hints" : "",
         "bits" : {
            "array_items" : 0,
            "total" : "8",
            "type" : "uint8_t"
         },
         "order" : 162
      },
      "cargo_item_5" : {
         "order" : 171,
         "bits" : {
            "type" : "uint8_t",
            "total" : "4",
            "array_items" : 0
         },
         "hints" : ""
      },
      "cargo_item_0" : {
         "hints" : "",
         "order" : 166,
         "bits" : {
            "type" : "uint8_t",
            "array_items" : 0,
            "total" : "4"
         }
      },
      "unk08" : {
         "hints" : "",
         "bits" : {
            "array_items" : 3,
            "total" : 24,
            "type" : "uint8_t"
         },
         "order" : 164
      },
      "profession" : {
         "order" : 174,
         "bits" : {
            "array_items" : 0,
            "total" : "8",
            "type" : "uint8_t"
         },
         "hints" : ""
      },
      "unk04" : {
         "hints" : "",
         "bits" : {
            "total" : "4",
            "array_items" : 0,
            "type" : "uint8_t"
         },
         "order" : 158
      },
      "cargo_item_1" : {
         "hints" : "",
         "bits" : {
            "type" : "uint8_t",
            "total" : "4",
            "array_items" : 0
         },
         "order" : 167
      },
      "nation" : {
         "hints" : " /* likely to be owner of unit, eng, fra, spa, dut, indian tribes, etc. */",
         "order" : 157,
         "bits" : {
            "type" : "uint8_t",
            "array_items" : 0,
            "total" : "4"
         }
      },
      "transport_chain" : {
         "prev_unit_idx" : {
            "hints" : " // index to unit being transported? (treasure) ",
            "bits" : {
               "type" : "int16_t",
               "array_items" : 0,
               "total" : "16"
            },
            "order" : 176
         },
         "next_unit_idx" : {
            "hints" : "",
            "bits" : {
               "type" : "int16_t",
               "total" : "16",
               "array_items" : 0
            },
            "order" : 175
         }
      },
      "unk05" : {
         "hints" : "",
         "bits" : {
            "type" : "uint8_t",
            "array_items" : 0,
            "total" : "8"
         },
         "order" : 159
      },
      "holds_occupied" : {
         "hints" : "",
         "order" : 165,
         "bits" : {
            "type" : "uint8_t",
            "total" : "8",
            "array_items" : 0
         }
      },
      "turns_worked" : {
         "hints" : "",
         "order" : 173,
         "bits" : {
            "total" : "8",
            "array_items" : 0,
            "type" : "uint8_t"
         }
      },
      "cargo_item_4" : {
         "order" : 170,
         "bits" : {
            "array_items" : 0,
            "total" : "4",
            "type" : "uint8_t"
         },
         "hints" : ""
      },
      "x" : {
         "bits" : {
            "type" : "uint8_t",
            "total" : "8",
            "array_items" : 0
         },
         "order" : 154,
         "hints" : ""
      },
      "cargo_item_3" : {
         "bits" : {
            "type" : "uint8_t",
            "array_items" : 0,
            "total" : "4"
         },
         "order" : 169,
         "hints" : ""
      },
      "unk06" : {
         "order" : 161,
         "bits" : {
            "total" : "8",
            "array_items" : 0,
            "type" : "uint8_t"
         },
         "hints" : ""
      },
      "y" : {
         "hints" : "",
         "order" : 155,
         "bits" : {
            "array_items" : 0,
            "total" : "8",
            "type" : "uint8_t"
         }
      },
      "moves" : {
         "order" : 160,
         "bits" : {
            "type" : "uint8_t",
            "array_items" : 0,
            "total" : "8"
         },
         "hints" : " /* Accumulated moves (3 between land, 1 on roads, etc.) */"
      },
      "cargo_hold" : {
         "order" : 172,
         "bits" : {
            "type" : "uint8_t",
            "total" : 48,
            "array_items" : 6
         },
         "hints" : ""
      },
      "cargo_item_2" : {
         "order" : 168,
         "bits" : {
            "type" : "uint8_t",
            "array_items" : 0,
            "total" : "4"
         },
         "hints" : ""
      },
      "type" : {
         "hints" : "",
         "order" : 156,
         "bits" : {
            "total" : "8",
            "array_items" : 0,
            "type" : "uint8_t"
         }
      }
   },
   "head" : {
      "numbers02" : {
         "hints" : "",
         "order" : 63,
         "bits" : {
            "total" : 48,
            "array_items" : 3,
            "type" : "int16_t"
         }
      },
      "unk1" : {
         "hints" : "",
         "order" : 19,
         "bits" : {
            "array_items" : 1,
            "total" : 8,
            "type" : "uint8_t"
         }
      },
      "numbers01" : {
         "bits" : {
            "array_items" : 0,
            "total" : "16",
            "type" : "int16_t"
         },
         "order" : 61,
         "hints" : ""
      },
      "colony_report_options" : {
         "report_food_shortages" : {
            "hints" : "",
            "bits" : {
               "type" : "uint16_t",
               "array_items" : 0,
               "total" : "1"
            },
            "order" : 36
         },
         "unused" : {
            "hints" : "",
            "order" : 40,
            "bits" : {
               "type" : "uint16_t",
               "total" : "6",
               "array_items" : 0
            }
         },
         "report_when_colonists_trained" : {
            "hints" : "",
            "bits" : {
               "array_items" : 0,
               "total" : "1",
               "type" : "uint16_t"
            },
            "order" : 37
         },
         "report_new_cargos_available" : {
            "hints" : "",
            "order" : 32,
            "bits" : {
               "type" : "uint16_t",
               "total" : "1",
               "array_items" : 0
            }
         },
         "report_inefficient_government" : {
            "bits" : {
               "type" : "uint16_t",
               "array_items" : 0,
               "total" : "1"
            },
            "order" : 33,
            "hints" : ""
         },
         "report_rebel_majorities" : {
            "order" : 39,
            "bits" : {
               "type" : "uint16_t",
               "total" : "1",
               "array_items" : 0
            },
            "hints" : ""
         },
         "labels_on_cargo_and_terrain" : {
            "order" : 30,
            "bits" : {
               "type" : "uint16_t",
               "total" : "1",
               "array_items" : 0
            },
            "hints" : ""
         },
         "labels_on_buildings" : {
            "hints" : "",
            "bits" : {
               "type" : "uint16_t",
               "total" : "1",
               "array_items" : 0
            },
            "order" : 31
         },
         "report_tools_needed_for_production" : {
            "hints" : "",
            "bits" : {
               "type" : "uint16_t",
               "total" : "1",
               "array_items" : 0
            },
            "order" : 34
         },
         "report_raw_materials_shortages" : {
            "hints" : "",
            "bits" : {
               "type" : "uint16_t",
               "array_items" : 0,
               "total" : "1"
            },
            "order" : 35
         },
         "report_sons_of_liberty_membership" : {
            "hints" : "",
            "bits" : {
               "array_items" : 0,
               "total" : "1",
               "type" : "uint16_t"
            },
            "order" : 38
         }
      },
      "numbers05" : {
         "bits" : {
            "type" : "uint16_t",
            "total" : 48,
            "array_items" : 3
         },
         "order" : 71,
         "hints" : ""
      },
      "founding_father" : {
         "hints" : "",
         "bits" : {
            "array_items" : 25,
            "total" : 200,
            "type" : "int8_t"
         },
         "order" : 70
      },
      "active_unit" : {
         "order" : 62,
         "bits" : {
            "type" : "uint16_t",
            "array_items" : 0,
            "total" : "16"
         },
         "hints" : ""
      },
      "count_down" : {
         "order" : 76,
         "bits" : {
            "type" : "uint16_t",
            "total" : 256,
            "array_items" : 16
         },
         "hints" : ""
      },
      "autumn" : {
         "bits" : {
            "type" : "uint16_t",
            "total" : "16",
            "array_items" : 0
         },
         "order" : 59,
         "hints" : " //boolean, true if autumn"
      },
      "map_size_y" : {
         "hints" : "",
         "order" : 10,
         "bits" : {
            "type" : "uint16_t",
            "total" : "16",
            "array_items" : 0
         }
      },
      "numbers00" : {
         "order" : 57,
         "bits" : {
            "type" : "int16_t",
            "array_items" : 0,
            "total" : "16"
         },
         "hints" : ""
      },
      "colony_count" : {
         "hints" : "",
         "order" : 66,
         "bits" : {
            "array_items" : 0,
            "total" : "16",
            "type" : "uint16_t"
         }
      },
      "numbers07" : {
         "hints" : " //backup force, once you produce enough bells.",
         "bits" : {
            "type" : "uint16_t",
            "array_items" : 4,
            "total" : 64
         },
         "order" : 75
      },
      "tut3" : {
         "nr8" : {
            "bits" : {
               "type" : "uint8_t",
               "total" : "1",
               "array_items" : 0
            },
            "order" : 52,
            "hints" : ""
         },
         "nr12" : {
            "hints" : "",
            "order" : 56,
            "bits" : {
               "total" : "1",
               "array_items" : 0,
               "type" : "uint8_t"
            }
         },
         "nr10" : {
            "order" : 54,
            "bits" : {
               "type" : "uint8_t",
               "total" : "1",
               "array_items" : 0
            },
            "hints" : ""
         },
         "nr7" : {
            "order" : 51,
            "bits" : {
               "array_items" : 0,
               "total" : "1",
               "type" : "uint8_t"
            },
            "hints" : ""
         },
         "nr6" : {
            "hints" : "",
            "bits" : {
               "total" : "1",
               "array_items" : 0,
               "type" : "uint8_t"
            },
            "order" : 50
         },
         "nr9" : {
            "bits" : {
               "array_items" : 0,
               "total" : "1",
               "type" : "uint8_t"
            },
            "order" : 53,
            "hints" : ""
         },
         "nr11" : {
            "bits" : {
               "array_items" : 0,
               "total" : "1",
               "type" : "uint8_t"
            },
            "order" : 55,
            "hints" : ""
         },
         "nr5" : {
            "hints" : "",
            "order" : 49,
            "bits" : {
               "array_items" : 0,
               "total" : "1",
               "type" : "uint8_t"
            }
         }
      },
      "unit_count" : {
         "hints" : "",
         "order" : 65,
         "bits" : {
            "type" : "uint16_t",
            "array_items" : 0,
            "total" : "16"
         }
      },
      "nation_relation" : {
         "hints" : "",
         "bits" : {
            "type" : "int16_t",
            "total" : 64,
            "array_items" : 4
         },
         "order" : 72
      },
      "tut1" : {
         "unk3" : {
            "hints" : "",
            "order" : 13,
            "bits" : {
               "array_items" : 0,
               "total" : "1",
               "type" : "uint8_t"
            }
         },
         "nr17" : {
            "hints" : "",
            "bits" : {
               "array_items" : 0,
               "total" : "1",
               "type" : "uint8_t"
            },
            "order" : 16
         },
         "nr14" : {
            "bits" : {
               "array_items" : 0,
               "total" : "1",
               "type" : "uint8_t"
            },
            "order" : 12,
            "hints" : ""
         },
         "nr15" : {
            "order" : 14,
            "bits" : {
               "type" : "uint8_t",
               "array_items" : 0,
               "total" : "1"
            },
            "hints" : ""
         },
         "unk7" : {
            "hints" : "",
            "order" : 17,
            "bits" : {
               "array_items" : 0,
               "total" : "1",
               "type" : "uint8_t"
            }
         },
         "nr13" : {
            "hints" : "",
            "bits" : {
               "array_items" : 0,
               "total" : "1",
               "type" : "uint8_t"
            },
            "order" : 11
         },
         "nr16" : {
            "order" : 15,
            "bits" : {
               "type" : "uint8_t",
               "array_items" : 0,
               "total" : "1"
            },
            "hints" : ""
         },
         "nr19" : {
            "hints" : "",
            "bits" : {
               "type" : "uint8_t",
               "total" : "1",
               "array_items" : 0
            },
            "order" : 18
         }
      },
      "unkb" : {
         "bits" : {
            "type" : "uint8_t",
            "array_items" : 2,
            "total" : 16
         },
         "order" : 93,
         "hints" : ""
      },
      "numbers04" : {
         "hints" : "",
         "bits" : {
            "array_items" : 0,
            "total" : "16",
            "type" : "int16_t"
         },
         "order" : 69
      },
      "year" : {
         "order" : 58,
         "bits" : {
            "total" : "16",
            "array_items" : 0,
            "type" : "uint16_t"
         },
         "hints" : ""
      },
      "turn" : {
         "hints" : "",
         "bits" : {
            "total" : "16",
            "array_items" : 0,
            "type" : "uint16_t"
         },
         "order" : 60
      },
      "tribe_count" : {
         "hints" : "",
         "bits" : {
            "type" : "uint16_t",
            "array_items" : 0,
            "total" : "16"
         },
         "order" : 64
      },
      "difficulty" : {
         "bits" : {
            "type" : "uint8_t",
            "array_items" : 0,
            "total" : "8"
         },
         "order" : 68,
         "hints" : " enum { DISCOVERER = 0, EXPLORER = 1, CONQUISTADOR = 2, GOVERNOR = 3, VICEROY = 4 }; //36"
      },
      "expeditionary_force" : {
         "bits" : {
            "array_items" : 4,
            "total" : 64,
            "type" : "uint16_t"
         },
         "order" : 74,
         "hints" : ""
      },
      "map_size_x" : {
         "hints" : "",
         "bits" : {
            "array_items" : 0,
            "total" : "16",
            "type" : "uint16_t"
         },
         "order" : 9
      },
      "tut2" : {
         "nr1" : {
            "order" : 45,
            "bits" : {
               "type" : "uint8_t",
               "total" : "1",
               "array_items" : 0
            },
            "hints" : " // shown immediately on game-start"
         },
         "nr3" : {
            "bits" : {
               "array_items" : 0,
               "total" : "1",
               "type" : "uint8_t"
            },
            "order" : 47,
            "hints" : ""
         },
         "event_music" : {
            "hints" : "",
            "order" : 43,
            "bits" : {
               "total" : "1",
               "array_items" : 0,
               "type" : "uint8_t"
            }
         },
         "sound_effects" : {
            "hints" : "",
            "order" : 44,
            "bits" : {
               "total" : "1",
               "array_items" : 0,
               "type" : "uint8_t"
            }
         },
         "background_music" : {
            "bits" : {
               "type" : "uint8_t",
               "total" : "1",
               "array_items" : 0
            },
            "order" : 42,
            "hints" : ""
         },
         "nr2" : {
            "hints" : " // probably not used, also triggers event_discovery_of_the_new_world",
            "bits" : {
               "type" : "uint8_t",
               "total" : "1",
               "array_items" : 0
            },
            "order" : 46
         },
         "nr4" : {
            "bits" : {
               "type" : "uint8_t",
               "total" : "1",
               "array_items" : 0
            },
            "order" : 48,
            "hints" : ""
         },
         "howtowin" : {
            "hints" : "",
            "order" : 41,
            "bits" : {
               "type" : "uint8_t",
               "array_items" : 0,
               "total" : "1"
            }
         }
      },
      "numbers03" : {
         "hints" : "",
         "bits" : {
            "total" : 48,
            "array_items" : 3,
            "type" : "int16_t"
         },
         "order" : 67
      },
      "numbers06" : {
         "order" : 73,
         "bits" : {
            "type" : "int16_t",
            "total" : 80,
            "array_items" : 5
         },
         "hints" : ""
      },
      "game_options" : {
         "unknown7" : {
            "hints" : "",
            "bits" : {
               "type" : "uint16_t",
               "total" : "7",
               "array_items" : 0
            },
            "order" : 20
         },
         "show_foreign_moves" : {
            "bits" : {
               "total" : "1",
               "array_items" : 0,
               "type" : "uint16_t"
            },
            "order" : 28,
            "hints" : ""
         },
         "show_indian_moves" : {
            "hints" : "",
            "order" : 29,
            "bits" : {
               "total" : "1",
               "array_items" : 0,
               "type" : "uint16_t"
            }
         },
         "autosave" : {
            "order" : 24,
            "bits" : {
               "type" : "uint16_t",
               "array_items" : 0,
               "total" : "1"
            },
            "hints" : ""
         },
         "water_color_cycling" : {
            "hints" : "",
            "bits" : {
               "type" : "uint16_t",
               "array_items" : 0,
               "total" : "1"
            },
            "order" : 22
         },
         "tutorial_hints" : {
            "bits" : {
               "type" : "uint16_t",
               "total" : "1",
               "array_items" : 0
            },
            "order" : 21,
            "hints" : ""
         },
         "end_of_turn" : {
            "bits" : {
               "type" : "uint16_t",
               "total" : "1",
               "array_items" : 0
            },
            "order" : 25,
            "hints" : ""
         },
         "fast_piece_slide" : {
            "order" : 26,
            "bits" : {
               "total" : "1",
               "array_items" : 0,
               "type" : "uint16_t"
            },
            "hints" : ""
         },
         "unknown" : {
            "hints" : "",
            "bits" : {
               "type" : "uint16_t",
               "total" : "1",
               "array_items" : 0
            },
            "order" : 27
         },
         "combat_analysis" : {
            "order" : 23,
            "bits" : {
               "array_items" : 0,
               "total" : "1",
               "type" : "uint16_t"
            },
            "hints" : ""
         }
      },
      "event" : {
         "entering_indian_village" : {
            "hints" : "",
            "order" : 83,
            "bits" : {
               "type" : "uint16_t",
               "total" : "1",
               "array_items" : 0
            }
         },
         "the_aztec_empire" : {
            "hints" : "",
            "bits" : {
               "type" : "uint16_t",
               "array_items" : 0,
               "total" : "1"
            },
            "order" : 80
         },
         "woodcut15" : {
            "order" : 91,
            "bits" : {
               "type" : "uint16_t",
               "total" : "1",
               "array_items" : 0
            },
            "hints" : ""
         },
         "building_a_colony" : {
            "hints" : "",
            "order" : 78,
            "bits" : {
               "array_items" : 0,
               "total" : "1",
               "type" : "uint16_t"
            }
         },
         "woodcut14" : {
            "hints" : "",
            "bits" : {
               "type" : "uint16_t",
               "array_items" : 0,
               "total" : "1"
            },
            "order" : 90
         },
         "the_fountain_of_youth" : {
            "order" : 84,
            "bits" : {
               "array_items" : 0,
               "total" : "1",
               "type" : "uint16_t"
            },
            "hints" : ""
         },
         "the_inca_nation" : {
            "order" : 81,
            "bits" : {
               "type" : "uint16_t",
               "array_items" : 0,
               "total" : "1"
            },
            "hints" : ""
         },
         "colony_destroyed" : {
            "order" : 88,
            "bits" : {
               "type" : "uint16_t",
               "total" : "1",
               "array_items" : 0
            },
            "hints" : ""
         },
         "discovery_of_the_pacific_ocean" : {
            "bits" : {
               "total" : "1",
               "array_items" : 0,
               "type" : "uint16_t"
            },
            "order" : 82,
            "hints" : ""
         },
         "cargo_from_the_new_world" : {
            "hints" : "",
            "order" : 85,
            "bits" : {
               "array_items" : 0,
               "total" : "1",
               "type" : "uint16_t"
            }
         },
         "meeting_the_natives" : {
            "hints" : "",
            "bits" : {
               "type" : "uint16_t",
               "array_items" : 0,
               "total" : "1"
            },
            "order" : 79
         },
         "meeting_fellow_europeans" : {
            "hints" : "",
            "bits" : {
               "type" : "uint16_t",
               "total" : "1",
               "array_items" : 0
            },
            "order" : 86
         },
         "indian_raid" : {
            "order" : 89,
            "bits" : {
               "total" : "1",
               "array_items" : 0,
               "type" : "uint16_t"
            },
            "hints" : ""
         },
         "colony_burning" : {
            "bits" : {
               "total" : "1",
               "array_items" : 0,
               "type" : "uint16_t"
            },
            "order" : 87,
            "hints" : ""
         },
         "woodcut16" : {
            "bits" : {
               "total" : "1",
               "array_items" : 0,
               "type" : "uint16_t"
            },
            "order" : 92,
            "hints" : ""
         },
         "discovery_of_the_new_world" : {
            "hints" : "",
            "bits" : {
               "type" : "uint16_t",
               "total" : "1",
               "array_items" : 0
            },
            "order" : 77
         }
      },
      "sig_colonize" : {
         "hints" : "",
         "order" : 7,
         "bits" : {
            "type" : "char",
            "total" : 72,
            "array_items" : 9
         }
      },
      "unk0" : {
         "bits" : {
            "type" : "uint8_t",
            "total" : 24,
            "array_items" : 3
         },
         "order" : 8,
         "hints" : ""
      }
   },
   "count" : {
      "nation" : {
         "hints" : "",
         "order" : 5,
         "bits" : {
            "type" : "uint16_t",
            "total" : "16",
            "array_items" : 0
         }
      },
      "unit" : {
         "bits" : {
            "array_items" : 0,
            "total" : "16",
            "type" : "uint16_t"
         },
         "order" : 2,
         "hints" : ""
      },
      "indian" : {
         "hints" : "",
         "bits" : {
            "array_items" : 0,
            "total" : "16",
            "type" : "uint16_t"
         },
         "order" : 6
      },
      "colony" : {
         "order" : 1,
         "bits" : {
            "type" : "uint16_t",
            "total" : "16",
            "array_items" : 0
         },
         "hints" : ""
      },
      "tribe" : {
         "hints" : "",
         "bits" : {
            "type" : "uint16_t",
            "total" : "16",
            "array_items" : 0
         },
         "order" : 3
      },
      "player" : {
         "hints" : "",
         "order" : 4,
         "bits" : {
            "total" : "16",
            "array_items" : 0,
            "type" : "uint16_t"
         }
      }
   }
}

    )"_json;
    return j;
}
