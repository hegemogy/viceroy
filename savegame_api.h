#include <iostream>
#include <string>
#include <stdio.h>
void set_value( struct savegame *sg, std::string input, int i, int new_value) {
    if (input.compare("sg->head.active_unit") == 0)
    	sg->head.active_unit = new_value;
    if (input.compare("sg->head.autumn") == 0)
    	sg->head.autumn = new_value;
    if (input.compare("sg->head.colony_count") == 0)
    	sg->head.colony_count = new_value;
    if (input.compare("sg->head.colony_report_options.labels_on_buildings") == 0)
    	sg->head.colony_report_options.labels_on_buildings = new_value;
    if (input.compare("sg->head.colony_report_options.labels_on_cargo_and_terrain") == 0)
    	sg->head.colony_report_options.labels_on_cargo_and_terrain = new_value;
    if (input.compare("sg->head.colony_report_options.report_food_shortages") == 0)
    	sg->head.colony_report_options.report_food_shortages = new_value;
    if (input.compare("sg->head.colony_report_options.report_inefficient_government") == 0)
    	sg->head.colony_report_options.report_inefficient_government = new_value;
    if (input.compare("sg->head.colony_report_options.report_new_cargos_available") == 0)
    	sg->head.colony_report_options.report_new_cargos_available = new_value;
    if (input.compare("sg->head.colony_report_options.report_raw_materials_shortages") == 0)
    	sg->head.colony_report_options.report_raw_materials_shortages = new_value;
    if (input.compare("sg->head.colony_report_options.report_rebel_majorities") == 0) {
    	sg->head.colony_report_options.report_rebel_majorities = new_value;
        fprintf(stderr,"rebel majorities %d",sg->head.colony_report_options.report_rebel_majorities);
    }
    if (input.compare("sg->head.colony_report_options.report_sons_of_liberty_membership") == 0)
    	sg->head.colony_report_options.report_sons_of_liberty_membership = new_value;
    if (input.compare("sg->head.colony_report_options.report_tools_needed_for_production") == 0)
    	sg->head.colony_report_options.report_tools_needed_for_production = new_value;
    if (input.compare("sg->head.colony_report_options.report_when_colonists_trained") == 0)
    	sg->head.colony_report_options.report_when_colonists_trained = new_value;
    if (input.compare("sg->head.colony_report_options.unused") == 0)
    	sg->head.colony_report_options.unused = new_value;
    if (input.compare("sg->head.count_down[0]") == 0)
    	sg->head.count_down[0] = new_value;
    if (input.compare("sg->head.count_down[1]") == 0)
    	sg->head.count_down[1] = new_value;
    if (input.compare("sg->head.count_down[2]") == 0)
    	sg->head.count_down[2] = new_value;
    if (input.compare("sg->head.count_down[3]") == 0)
    	sg->head.count_down[3] = new_value;
    if (input.compare("sg->head.count_down[4]") == 0)
    	sg->head.count_down[4] = new_value;
    if (input.compare("sg->head.count_down[5]") == 0)
    	sg->head.count_down[5] = new_value;
    if (input.compare("sg->head.count_down[6]") == 0)
    	sg->head.count_down[6] = new_value;
    if (input.compare("sg->head.count_down[7]") == 0)
    	sg->head.count_down[7] = new_value;
    if (input.compare("sg->head.count_down[8]") == 0)
    	sg->head.count_down[8] = new_value;
    if (input.compare("sg->head.count_down[9]") == 0)
    	sg->head.count_down[9] = new_value;
    if (input.compare("sg->head.count_down[10]") == 0)
    	sg->head.count_down[10] = new_value;
    if (input.compare("sg->head.count_down[11]") == 0)
    	sg->head.count_down[11] = new_value;
    if (input.compare("sg->head.count_down[12]") == 0)
    	sg->head.count_down[12] = new_value;
    if (input.compare("sg->head.count_down[13]") == 0)
    	sg->head.count_down[13] = new_value;
    if (input.compare("sg->head.count_down[14]") == 0)
    	sg->head.count_down[14] = new_value;
    if (input.compare("sg->head.count_down[15]") == 0)
    	sg->head.count_down[15] = new_value;
    if (input.compare("sg->head.difficulty") == 0)
    	sg->head.difficulty = new_value;
    if (input.compare("sg->head.event.building_a_colony") == 0)
    	sg->head.event.building_a_colony = new_value;
    if (input.compare("sg->head.event.cargo_from_the_new_world") == 0)
    	sg->head.event.cargo_from_the_new_world = new_value;
    if (input.compare("sg->head.event.colony_burning") == 0)
    	sg->head.event.colony_burning = new_value;
    if (input.compare("sg->head.event.colony_destroyed") == 0)
    	sg->head.event.colony_destroyed = new_value;
    if (input.compare("sg->head.event.discovery_of_the_new_world") == 0)
    	sg->head.event.discovery_of_the_new_world = new_value;
    if (input.compare("sg->head.event.discovery_of_the_pacific_ocean") == 0)
    	sg->head.event.discovery_of_the_pacific_ocean = new_value;
    if (input.compare("sg->head.event.entering_indian_village") == 0)
    	sg->head.event.entering_indian_village = new_value;
    if (input.compare("sg->head.event.indian_raid") == 0)
    	sg->head.event.indian_raid = new_value;
    if (input.compare("sg->head.event.meeting_fellow_europeans") == 0)
    	sg->head.event.meeting_fellow_europeans = new_value;
    if (input.compare("sg->head.event.meeting_the_natives") == 0)
    	sg->head.event.meeting_the_natives = new_value;
    if (input.compare("sg->head.event.the_aztec_empire") == 0)
    	sg->head.event.the_aztec_empire = new_value;
    if (input.compare("sg->head.event.the_fountain_of_youth") == 0)
    	sg->head.event.the_fountain_of_youth = new_value;
    if (input.compare("sg->head.event.the_inca_nation") == 0)
    	sg->head.event.the_inca_nation = new_value;
    if (input.compare("sg->head.event.woodcut14") == 0)
    	sg->head.event.woodcut14 = new_value;
    if (input.compare("sg->head.event.woodcut15") == 0)
    	sg->head.event.woodcut15 = new_value;
    if (input.compare("sg->head.event.woodcut16") == 0)
    	sg->head.event.woodcut16 = new_value;
    if (input.compare("sg->head.expeditionary_force[0]") == 0)
    	sg->head.expeditionary_force[0] = new_value;
    if (input.compare("sg->head.expeditionary_force[1]") == 0)
    	sg->head.expeditionary_force[1] = new_value;
    if (input.compare("sg->head.expeditionary_force[2]") == 0)
    	sg->head.expeditionary_force[2] = new_value;
    if (input.compare("sg->head.expeditionary_force[3]") == 0)
    	sg->head.expeditionary_force[3] = new_value;
//    if (input.compare("sg->head.founding_father") == 0)
//    	sg->head.founding_father = new_value;
    if (input.compare("sg->head.game_options.autosave") == 0)
    	sg->head.game_options.autosave = new_value;
    if (input.compare("sg->head.game_options.combat_analysis") == 0)
    	sg->head.game_options.combat_analysis = new_value;
    if (input.compare("sg->head.game_options.end_of_turn") == 0)
    	sg->head.game_options.end_of_turn = new_value;
    if (input.compare("sg->head.game_options.fast_piece_slide") == 0)
    	sg->head.game_options.fast_piece_slide = new_value;
    if (input.compare("sg->head.game_options.show_foreign_moves") == 0)
    	sg->head.game_options.show_foreign_moves = new_value;
    if (input.compare("sg->head.game_options.show_indian_moves") == 0)
    	sg->head.game_options.show_indian_moves = new_value;
    if (input.compare("sg->head.game_options.tutorial_hints") == 0)
    	sg->head.game_options.tutorial_hints = new_value;
    if (input.compare("sg->head.game_options.unknown") == 0)
    	sg->head.game_options.unknown = new_value;
    if (input.compare("sg->head.game_options.unknown7") == 0)
    	sg->head.game_options.unknown7 = new_value;
    if (input.compare("sg->head.game_options.water_color_cycling") == 0)
    	sg->head.game_options.water_color_cycling = new_value;
    if (input.compare("sg->head.map_size_x") == 0)
    	sg->head.map_size_x = new_value;
    if (input.compare("sg->head.map_size_y") == 0)
    	sg->head.map_size_y = new_value;
    if (input.compare("sg->head.nation_relation[0]") == 0)
    	sg->head.nation_relation[0] = new_value;
    if (input.compare("sg->head.nation_relation[1]") == 0)
    	sg->head.nation_relation[1] = new_value;
    if (input.compare("sg->head.nation_relation[2]") == 0)
    	sg->head.nation_relation[2] = new_value;
    if (input.compare("sg->head.nation_relation[3]") == 0)
    	sg->head.nation_relation[3] = new_value;
    if (input.compare("sg->head.numbers00") == 0)
    	sg->head.numbers00 = new_value;
    if (input.compare("sg->head.numbers01") == 0)
    	sg->head.numbers01 = new_value;
    if (input.compare("sg->head.numbers02[0]") == 0)
    	sg->head.numbers02[0] = new_value;
    if (input.compare("sg->head.numbers02[1]") == 0)
    	sg->head.numbers02[1] = new_value;
    if (input.compare("sg->head.numbers02[2]") == 0)
    	sg->head.numbers02[2] = new_value;
    if (input.compare("sg->head.numbers03[0]") == 0)
    	sg->head.numbers03[0] = new_value;
    if (input.compare("sg->head.numbers03[1]") == 0)
    	sg->head.numbers03[1] = new_value;
    if (input.compare("sg->head.numbers03[2]") == 0)
    	sg->head.numbers03[2] = new_value;
    if (input.compare("sg->head.numbers04") == 0)
    	sg->head.numbers04 = new_value;
    if (input.compare("sg->head.numbers05[0]") == 0)
    	sg->head.numbers05[0] = new_value;
    if (input.compare("sg->head.numbers05[1]") == 0)
    	sg->head.numbers05[1] = new_value;
    if (input.compare("sg->head.numbers05[2]") == 0)
    	sg->head.numbers05[2] = new_value;
    if (input.compare("sg->head.numbers06[0]") == 0)
    	sg->head.numbers06[0] = new_value;
    if (input.compare("sg->head.numbers06[1]") == 0)
    	sg->head.numbers06[1] = new_value;
    if (input.compare("sg->head.numbers06[2]") == 0)
    	sg->head.numbers06[2] = new_value;
    if (input.compare("sg->head.numbers06[3]") == 0)
    	sg->head.numbers06[3] = new_value;
    if (input.compare("sg->head.numbers06[4]") == 0)
    	sg->head.numbers06[4] = new_value;
    if (input.compare("sg->head.numbers07[0]") == 0)
    	sg->head.numbers07[0] = new_value;
    if (input.compare("sg->head.numbers07[1]") == 0)
    	sg->head.numbers07[1] = new_value;
    if (input.compare("sg->head.numbers07[2]") == 0)
    	sg->head.numbers07[2] = new_value;
    if (input.compare("sg->head.numbers07[3]") == 0)
    	sg->head.numbers07[3] = new_value;
    if (input.compare("sg->head.sig_colonize[0]") == 0)
    	sg->head.sig_colonize[0] = new_value;
    if (input.compare("sg->head.sig_colonize[1]") == 0)
    	sg->head.sig_colonize[1] = new_value;
    if (input.compare("sg->head.sig_colonize[2]") == 0)
    	sg->head.sig_colonize[2] = new_value;
    if (input.compare("sg->head.sig_colonize[3]") == 0)
    	sg->head.sig_colonize[3] = new_value;
    if (input.compare("sg->head.sig_colonize[4]") == 0)
    	sg->head.sig_colonize[4] = new_value;
    if (input.compare("sg->head.sig_colonize[5]") == 0)
    	sg->head.sig_colonize[5] = new_value;
    if (input.compare("sg->head.sig_colonize[6]") == 0)
    	sg->head.sig_colonize[6] = new_value;
    if (input.compare("sg->head.sig_colonize[7]") == 0)
    	sg->head.sig_colonize[7] = new_value;
    if (input.compare("sg->head.sig_colonize[8]") == 0)
    	sg->head.sig_colonize[8] = new_value;
    if (input.compare("sg->head.tribe_count") == 0)
    	sg->head.tribe_count = new_value;
    if (input.compare("sg->head.turn") == 0)
    	sg->head.turn = new_value;
    if (input.compare("sg->head.tut1.nr13") == 0)
    	sg->head.tut1.nr13 = new_value;
    if (input.compare("sg->head.tut1.nr14") == 0)
    	sg->head.tut1.nr14 = new_value;
    if (input.compare("sg->head.tut1.nr15") == 0)
    	sg->head.tut1.nr15 = new_value;
    if (input.compare("sg->head.tut1.nr16") == 0)
    	sg->head.tut1.nr16 = new_value;
    if (input.compare("sg->head.tut1.nr17") == 0)
    	sg->head.tut1.nr17 = new_value;
    if (input.compare("sg->head.tut1.nr19") == 0)
    	sg->head.tut1.nr19 = new_value;
    if (input.compare("sg->head.tut1.unk3") == 0)
    	sg->head.tut1.unk3 = new_value;
    if (input.compare("sg->head.tut1.unk7") == 0)
    	sg->head.tut1.unk7 = new_value;
    if (input.compare("sg->head.tut2.background_music") == 0)
    	sg->head.tut2.background_music = new_value;
    if (input.compare("sg->head.tut2.event_music") == 0)
    	sg->head.tut2.event_music = new_value;
    if (input.compare("sg->head.tut2.howtowin") == 0)
    	sg->head.tut2.howtowin = new_value;
    if (input.compare("sg->head.tut2.nr1") == 0)
    	sg->head.tut2.nr1 = new_value;
    if (input.compare("sg->head.tut2.nr2") == 0)
    	sg->head.tut2.nr2 = new_value;
    if (input.compare("sg->head.tut2.nr3") == 0)
    	sg->head.tut2.nr3 = new_value;
    if (input.compare("sg->head.tut2.nr4") == 0)
    	sg->head.tut2.nr4 = new_value;
    if (input.compare("sg->head.tut2.sound_effects") == 0)
    	sg->head.tut2.sound_effects = new_value;
    if (input.compare("sg->head.tut3.nr10") == 0)
    	sg->head.tut3.nr10 = new_value;
    if (input.compare("sg->head.tut3.nr11") == 0)
    	sg->head.tut3.nr11 = new_value;
    if (input.compare("sg->head.tut3.nr12") == 0)
    	sg->head.tut3.nr12 = new_value;
    if (input.compare("sg->head.tut3.nr5") == 0)
    	sg->head.tut3.nr5 = new_value;
    if (input.compare("sg->head.tut3.nr6") == 0)
    	sg->head.tut3.nr6 = new_value;
    if (input.compare("sg->head.tut3.nr7") == 0)
    	sg->head.tut3.nr7 = new_value;
    if (input.compare("sg->head.tut3.nr8") == 0)
    	sg->head.tut3.nr8 = new_value;
    if (input.compare("sg->head.tut3.nr9") == 0)
    	sg->head.tut3.nr9 = new_value;
    if (input.compare("sg->head.unit_count") == 0)
    	sg->head.unit_count = new_value;
    if (input.compare("sg->head.unk0[0]") == 0)
    	sg->head.unk0[0] = new_value;
    if (input.compare("sg->head.unk0[1]") == 0)
    	sg->head.unk0[1] = new_value;
    if (input.compare("sg->head.unk0[2]") == 0)
    	sg->head.unk0[2] = new_value;
//    if (input.compare("sg->head.unk1") == 0)
//    	sg->head.unk1 = new_value;
    if (input.compare("sg->head.unkb[0]") == 0)
    	sg->head.unkb[0] = new_value;
    if (input.compare("sg->head.unkb[1]") == 0)
    	sg->head.unkb[1] = new_value;
    if (input.compare("sg->head.year") == 0)
    	sg->head.year = new_value;
    if (input.compare("sg->colony[i].building_in_production") == 0)
    	sg->colony[i].building_in_production = new_value;
    if (input.compare("sg->colony[i].buildings.armory") == 0)
    	sg->colony[i].buildings.armory = new_value;
    if (input.compare("sg->colony[i].buildings.blacksmiths_house") == 0)
    	sg->colony[i].buildings.blacksmiths_house = new_value;
    if (input.compare("sg->colony[i].buildings.capitol") == 0)
    	sg->colony[i].buildings.capitol = new_value;
    if (input.compare("sg->colony[i].buildings.carpenters_shop") == 0)
    	sg->colony[i].buildings.carpenters_shop = new_value;
    if (input.compare("sg->colony[i].buildings.church") == 0)
    	sg->colony[i].buildings.church = new_value;
    if (input.compare("sg->colony[i].buildings.custom_house") == 0)
    	sg->colony[i].buildings.custom_house = new_value;
    if (input.compare("sg->colony[i].buildings.docks") == 0)
    	sg->colony[i].buildings.docks = new_value;
    if (input.compare("sg->colony[i].buildings.fur_traders_house") == 0)
    	sg->colony[i].buildings.fur_traders_house = new_value;
    if (input.compare("sg->colony[i].buildings.printing_press") == 0)
    	sg->colony[i].buildings.printing_press = new_value;
    if (input.compare("sg->colony[i].buildings.rum_distillers_house") == 0)
    	sg->colony[i].buildings.rum_distillers_house = new_value;
    if (input.compare("sg->colony[i].buildings.schoolhouse") == 0)
    	sg->colony[i].buildings.schoolhouse = new_value;
    if (input.compare("sg->colony[i].buildings.stables") == 0)
    	sg->colony[i].buildings.stables = new_value;
    if (input.compare("sg->colony[i].buildings.stockade") == 0)
    	sg->colony[i].buildings.stockade = new_value;
    if (input.compare("sg->colony[i].buildings.tobacconists_house") == 0)
    	sg->colony[i].buildings.tobacconists_house = new_value;
    if (input.compare("sg->colony[i].buildings.town_hall") == 0)
    	sg->colony[i].buildings.town_hall = new_value;
    if (input.compare("sg->colony[i].buildings.unused") == 0)
    	sg->colony[i].buildings.unused = new_value;
    if (input.compare("sg->colony[i].buildings.warehouse") == 0)
    	sg->colony[i].buildings.warehouse = new_value;
    if (input.compare("sg->colony[i].buildings.weavers_house") == 0)
    	sg->colony[i].buildings.weavers_house = new_value;
    if (input.compare("sg->colony[i].custom_house.cigars") == 0)
    	sg->colony[i].custom_house.cigars = new_value;
    if (input.compare("sg->colony[i].custom_house.cloth") == 0)
    	sg->colony[i].custom_house.cloth = new_value;
    if (input.compare("sg->colony[i].custom_house.coats") == 0)
    	sg->colony[i].custom_house.coats = new_value;
    if (input.compare("sg->colony[i].custom_house.cotton") == 0)
    	sg->colony[i].custom_house.cotton = new_value;
    if (input.compare("sg->colony[i].custom_house.food") == 0)
    	sg->colony[i].custom_house.food = new_value;
    if (input.compare("sg->colony[i].custom_house.furs") == 0)
    	sg->colony[i].custom_house.furs = new_value;
    if (input.compare("sg->colony[i].custom_house.horses") == 0)
    	sg->colony[i].custom_house.horses = new_value;
    if (input.compare("sg->colony[i].custom_house.lumber") == 0)
    	sg->colony[i].custom_house.lumber = new_value;
    if (input.compare("sg->colony[i].custom_house.muskets") == 0)
    	sg->colony[i].custom_house.muskets = new_value;
    if (input.compare("sg->colony[i].custom_house.ore") == 0)
    	sg->colony[i].custom_house.ore = new_value;
    if (input.compare("sg->colony[i].custom_house.rum") == 0)
    	sg->colony[i].custom_house.rum = new_value;
    if (input.compare("sg->colony[i].custom_house.silver") == 0)
    	sg->colony[i].custom_house.silver = new_value;
    if (input.compare("sg->colony[i].custom_house.sugar") == 0)
    	sg->colony[i].custom_house.sugar = new_value;
    if (input.compare("sg->colony[i].custom_house.tobacco") == 0)
    	sg->colony[i].custom_house.tobacco = new_value;
    if (input.compare("sg->colony[i].custom_house.tools") == 0)
    	sg->colony[i].custom_house.tools = new_value;
    if (input.compare("sg->colony[i].custom_house.trade_goods") == 0)
    	sg->colony[i].custom_house.trade_goods = new_value;
    if (input.compare("sg->colony[i].hammers") == 0)
    	sg->colony[i].hammers = new_value;
//    if (input.compare("sg->colony[i].name") == 0)
//    	sg->colony[i].name = new_value;
    if (input.compare("sg->colony[i].nation") == 0)
    	sg->colony[i].nation = new_value;
//    if (input.compare("sg->colony[i].occupation") == 0)
//    	sg->colony[i].occupation = new_value;
    if (input.compare("sg->colony[i].population") == 0)
    	sg->colony[i].population = new_value;
//    if (input.compare("sg->colony[i].profession") == 0)
//    	sg->colony[i].profession = new_value;
    if (input.compare("sg->colony[i].rebel_dividend") == 0)
    	sg->colony[i].rebel_dividend = new_value;
    if (input.compare("sg->colony[i].rebel_divisor") == 0)
    	sg->colony[i].rebel_divisor = new_value;
    if (input.compare("sg->colony[i].stock[0]") == 0)
    	sg->colony[i].stock[0] = new_value;
    if (input.compare("sg->colony[i].stock[1]") == 0)
    	sg->colony[i].stock[1] = new_value;
    if (input.compare("sg->colony[i].stock[2]") == 0)
    	sg->colony[i].stock[2] = new_value;
    if (input.compare("sg->colony[i].stock[3]") == 0)
    	sg->colony[i].stock[3] = new_value;
    if (input.compare("sg->colony[i].stock[4]") == 0)
    	sg->colony[i].stock[4] = new_value;
    if (input.compare("sg->colony[i].stock[5]") == 0)
    	sg->colony[i].stock[5] = new_value;
    if (input.compare("sg->colony[i].stock[6]") == 0)
    	sg->colony[i].stock[6] = new_value;
    if (input.compare("sg->colony[i].stock[7]") == 0)
    	sg->colony[i].stock[7] = new_value;
    if (input.compare("sg->colony[i].stock[8]") == 0)
    	sg->colony[i].stock[8] = new_value;
    if (input.compare("sg->colony[i].stock[9]") == 0)
    	sg->colony[i].stock[9] = new_value;
    if (input.compare("sg->colony[i].stock[10]") == 0)
    	sg->colony[i].stock[10] = new_value;
    if (input.compare("sg->colony[i].stock[11]") == 0)
    	sg->colony[i].stock[11] = new_value;
    if (input.compare("sg->colony[i].stock[12]") == 0)
    	sg->colony[i].stock[12] = new_value;
    if (input.compare("sg->colony[i].stock[13]") == 0)
    	sg->colony[i].stock[13] = new_value;
    if (input.compare("sg->colony[i].stock[14]") == 0)
    	sg->colony[i].stock[14] = new_value;
    if (input.compare("sg->colony[i].stock[15]") == 0)
    	sg->colony[i].stock[15] = new_value;
    if (input.compare("sg->colony[i].tiles[0]") == 0)
    	sg->colony[i].tiles[0] = new_value;
    if (input.compare("sg->colony[i].tiles[1]") == 0)
    	sg->colony[i].tiles[1] = new_value;
    if (input.compare("sg->colony[i].tiles[2]") == 0)
    	sg->colony[i].tiles[2] = new_value;
    if (input.compare("sg->colony[i].tiles[3]") == 0)
    	sg->colony[i].tiles[3] = new_value;
    if (input.compare("sg->colony[i].tiles[4]") == 0)
    	sg->colony[i].tiles[4] = new_value;
    if (input.compare("sg->colony[i].tiles[5]") == 0)
    	sg->colony[i].tiles[5] = new_value;
    if (input.compare("sg->colony[i].tiles[6]") == 0)
    	sg->colony[i].tiles[6] = new_value;
    if (input.compare("sg->colony[i].tiles[7]") == 0)
    	sg->colony[i].tiles[7] = new_value;
    if (input.compare("sg->colony[i].unk0[0]") == 0)
    	sg->colony[i].unk0[0] = new_value;
    if (input.compare("sg->colony[i].unk0[1]") == 0)
    	sg->colony[i].unk0[1] = new_value;
    if (input.compare("sg->colony[i].unk0[2]") == 0)
    	sg->colony[i].unk0[2] = new_value;
    if (input.compare("sg->colony[i].unk0[3]") == 0)
    	sg->colony[i].unk0[3] = new_value;
    if (input.compare("sg->colony[i].unk6[0]") == 0)
    	sg->colony[i].unk6[0] = new_value;
    if (input.compare("sg->colony[i].unk6[1]") == 0)
    	sg->colony[i].unk6[1] = new_value;
    if (input.compare("sg->colony[i].unk6[2]") == 0)
    	sg->colony[i].unk6[2] = new_value;
    if (input.compare("sg->colony[i].unk6[3]") == 0)
    	sg->colony[i].unk6[3] = new_value;
    if (input.compare("sg->colony[i].unk6[4]") == 0)
    	sg->colony[i].unk6[4] = new_value;
    if (input.compare("sg->colony[i].unk6[5]") == 0)
    	sg->colony[i].unk6[5] = new_value;
    if (input.compare("sg->colony[i].unk6[6]") == 0)
    	sg->colony[i].unk6[6] = new_value;
    if (input.compare("sg->colony[i].unk6[7]") == 0)
    	sg->colony[i].unk6[7] = new_value;
    if (input.compare("sg->colony[i].unk6[8]") == 0)
    	sg->colony[i].unk6[8] = new_value;
    if (input.compare("sg->colony[i].unk6[9]") == 0)
    	sg->colony[i].unk6[9] = new_value;
    if (input.compare("sg->colony[i].unk6[10]") == 0)
    	sg->colony[i].unk6[10] = new_value;
    if (input.compare("sg->colony[i].unk6[11]") == 0)
    	sg->colony[i].unk6[11] = new_value;
    if (input.compare("sg->colony[i].unk6[12]") == 0)
    	sg->colony[i].unk6[12] = new_value;
    if (input.compare("sg->colony[i].unk6[13]") == 0)
    	sg->colony[i].unk6[13] = new_value;
    if (input.compare("sg->colony[i].unk6[14]") == 0)
    	sg->colony[i].unk6[14] = new_value;
    if (input.compare("sg->colony[i].unk6[15]") == 0)
    	sg->colony[i].unk6[15] = new_value;
    if (input.compare("sg->colony[i].unk8[0]") == 0)
    	sg->colony[i].unk8[0] = new_value;
    if (input.compare("sg->colony[i].unk8[1]") == 0)
    	sg->colony[i].unk8[1] = new_value;
    if (input.compare("sg->colony[i].unk8[2]") == 0)
    	sg->colony[i].unk8[2] = new_value;
    if (input.compare("sg->colony[i].unk8[3]") == 0)
    	sg->colony[i].unk8[3] = new_value;
    if (input.compare("sg->colony[i].unk8[4]") == 0)
    	sg->colony[i].unk8[4] = new_value;
    if (input.compare("sg->colony[i].unk8[5]") == 0)
    	sg->colony[i].unk8[5] = new_value;
    if (input.compare("sg->colony[i].unk8[6]") == 0)
    	sg->colony[i].unk8[6] = new_value;
    if (input.compare("sg->colony[i].unk8[7]") == 0)
    	sg->colony[i].unk8[7] = new_value;
    if (input.compare("sg->colony[i].unk8[8]") == 0)
    	sg->colony[i].unk8[8] = new_value;
    if (input.compare("sg->colony[i].unk8[9]") == 0)
    	sg->colony[i].unk8[9] = new_value;
    if (input.compare("sg->colony[i].unk8[10]") == 0)
    	sg->colony[i].unk8[10] = new_value;
    if (input.compare("sg->colony[i].unk8[11]") == 0)
    	sg->colony[i].unk8[11] = new_value;
    if (input.compare("sg->colony[i].unka[0]") == 0)
    	sg->colony[i].unka[0] = new_value;
    if (input.compare("sg->colony[i].unka[1]") == 0)
    	sg->colony[i].unka[1] = new_value;
    if (input.compare("sg->colony[i].unka[2]") == 0)
    	sg->colony[i].unka[2] = new_value;
    if (input.compare("sg->colony[i].unka[3]") == 0)
    	sg->colony[i].unka[3] = new_value;
    if (input.compare("sg->colony[i].unka[4]") == 0)
    	sg->colony[i].unka[4] = new_value;
    if (input.compare("sg->colony[i].unka[5]") == 0)
    	sg->colony[i].unka[5] = new_value;
    if (input.compare("sg->colony[i].unkb[0]") == 0)
    	sg->colony[i].unkb[0] = new_value;
    if (input.compare("sg->colony[i].unkb[1]") == 0)
    	sg->colony[i].unkb[1] = new_value;
    if (input.compare("sg->colony[i].unkb[2]") == 0)
    	sg->colony[i].unkb[2] = new_value;
    if (input.compare("sg->colony[i].unkb[3]") == 0)
    	sg->colony[i].unkb[3] = new_value;
    if (input.compare("sg->colony[i].unkb[4]") == 0)
    	sg->colony[i].unkb[4] = new_value;
    if (input.compare("sg->colony[i].unkd[0]") == 0)
    	sg->colony[i].unkd[0] = new_value;
    if (input.compare("sg->colony[i].unkd[1]") == 0)
    	sg->colony[i].unkd[1] = new_value;
    if (input.compare("sg->colony[i].unkd[2]") == 0)
    	sg->colony[i].unkd[2] = new_value;
    if (input.compare("sg->colony[i].unkd[3]") == 0)
    	sg->colony[i].unkd[3] = new_value;
    if (input.compare("sg->colony[i].unkd[4]") == 0)
    	sg->colony[i].unkd[4] = new_value;
    if (input.compare("sg->colony[i].unkd[5]") == 0)
    	sg->colony[i].unkd[5] = new_value;
    if (input.compare("sg->colony[i].unkd[6]") == 0)
    	sg->colony[i].unkd[6] = new_value;
    if (input.compare("sg->colony[i].unkd[7]") == 0)
    	sg->colony[i].unkd[7] = new_value;
    if (input.compare("sg->colony[i].x") == 0)
    	sg->colony[i].x = new_value;
    if (input.compare("sg->colony[i].y") == 0)
    	sg->colony[i].y = new_value;
}
