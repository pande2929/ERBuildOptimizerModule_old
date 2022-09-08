#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "pymodels.h"
#include "SubsetSum.h"
#include "ERBuildOptimizer.h"

namespace py = pybind11;

PYBIND11_MODULE(ERBuildOptimizerModule, m) {
	py::class_<ERBuildOptimizer>(m, "ERBuildOptimizer", py::dynamic_attr())
		.def(py::init<const int, const bool, const py::dict&>())
		.def("SetWeapon", &ERBuildOptimizer::SetWeapon)
		.def_readwrite("mh_weapon", &ERBuildOptimizer::mh_weapon)
		.def_readwrite("oh_weapon", &ERBuildOptimizer::oh_weapon)
		.def_readwrite("optimal_character", &ERBuildOptimizer::optimal_character)
		.def("Optimize", &ERBuildOptimizer::Optimize)
		.def_property_readonly("calculation_result", &ERBuildOptimizer::GetCalculationResult);

	py::class_<Tarnished>(m, "TarnishedCPP", py::dynamic_attr())
		.def(py::init<>())
		.def_readwrite("name", &Tarnished::name)
		.def_readwrite("base_strength", &Tarnished::base_strength)
		.def_readwrite("base_dexterity", &Tarnished::base_dexterity)
		.def_readwrite("base_intelligence", &Tarnished::base_intelligence)
		.def_readwrite("base_faith", &Tarnished::base_faith)
		.def_readwrite("base_arcane", &Tarnished::base_arcane)
		.def_readwrite("base_vigor", &Tarnished::base_vigor)
		.def_readwrite("base_mind", &Tarnished::base_mind)
		.def_readwrite("base_endurance", &Tarnished::base_endurance)
		.def_readwrite("vigor", &Tarnished::vigor)
		.def_readwrite("mind", &Tarnished::mind)
		.def_readwrite("endurance", &Tarnished::endurance)
		.def_readwrite("opt_strength", &Tarnished::opt_strength)
		.def_readwrite("opt_dexterity", &Tarnished::opt_dexterity)
		.def_readwrite("opt_intelligence", &Tarnished::opt_intelligence)
		.def_readwrite("opt_faith", &Tarnished::opt_faith)
		.def_readwrite("opt_arcane", &Tarnished::opt_arcane);

	py::class_<Weapon>(m, "WeaponCPP", py::dynamic_attr())
		.def(py::init<>())
		.def_readwrite("id", &Weapon::id)
		.def_readwrite("name", &Weapon::name)
		.def_readwrite("weapon_type", &Weapon::weapon_type)
		.def_readwrite("origin_weapon", &Weapon::origin_weapon)
		.def_readwrite("damage_physical", &Weapon::damage_physical)
		.def_readwrite("damage_magic", &Weapon::damage_magic)
		.def_readwrite("damage_fire", &Weapon::damage_fire)
		.def_readwrite("damage_lightning", &Weapon::damage_lightning)
		.def_readwrite("damage_holy", &Weapon::damage_holy)
		.def_readwrite("required_str", &Weapon::required_str)
		.def_readwrite("required_dex", &Weapon::required_dex)
		.def_readwrite("required_int", &Weapon::required_int)
		.def_readwrite("required_fai", &Weapon::required_fai)
		.def_readwrite("required_arc", &Weapon::required_arc)
		.def_readwrite("correction_str", &Weapon::correction_str)
		.def_readwrite("correction_dex", &Weapon::correction_dex)
		.def_readwrite("correction_int", &Weapon::correction_int)
		.def_readwrite("correction_fai", &Weapon::correction_fai)
		.def_readwrite("correction_arc", &Weapon::correction_arc)
		.def_readwrite("attack_element_correct_bitmask_str", &Weapon::attack_element_correct_bitmask_str)
		.def_readwrite("attack_element_correct_bitmask", &Weapon::attack_element_correct_bitmask)
		.def_readwrite("damage_pct_physical", &Weapon::damage_pct_physical)
		.def_readwrite("damage_pct_magic", &Weapon::damage_pct_magic)
		.def_readwrite("damage_pct_fire", &Weapon::damage_pct_fire)
		.def_readwrite("damage_pct_lightning", &Weapon::damage_pct_lightning)
		.def_readwrite("damage_pct_holy", &Weapon::damage_pct_holy)
		.def_readwrite("damage_pct_stamina", &Weapon::damage_pct_stamina)
		.def_readwrite("damage_pct_poise", &Weapon::damage_pct_poise)
		.def_readwrite("correction_pct_str", &Weapon::correction_pct_str)
		.def_readwrite("correction_pct_dex", &Weapon::correction_pct_dex)
		.def_readwrite("correction_pct_int", &Weapon::correction_pct_int)
		.def_readwrite("correction_pct_fai", &Weapon::correction_pct_fai)
		.def_readwrite("correction_pct_arc", &Weapon::correction_pct_arc)
		.def_readwrite("base_damage_pct_overall", &Weapon::base_damage_pct_overall)
		.def_readwrite("physical_calc_correct_id", &Weapon::physical_calc_correct_id)
		.def_readwrite("physical_stat_max_0", &Weapon::physical_stat_max_0)
		.def_readwrite("physical_stat_max_1", &Weapon::physical_stat_max_1)
		.def_readwrite("physical_stat_max_2", &Weapon::physical_stat_max_2)
		.def_readwrite("physical_stat_max_3", &Weapon::physical_stat_max_3)
		.def_readwrite("physical_stat_max_4", &Weapon::physical_stat_max_4)
		.def_readwrite("physical_grow_0", &Weapon::physical_grow_0)
		.def_readwrite("physical_grow_1", &Weapon::physical_grow_1)
		.def_readwrite("physical_grow_2", &Weapon::physical_grow_2)
		.def_readwrite("physical_grow_3", &Weapon::physical_grow_3)
		.def_readwrite("physical_grow_4", &Weapon::physical_grow_4)
		.def_readwrite("physical_adjustment_pt_grow_0", &Weapon::physical_adjustment_pt_grow_0)
		.def_readwrite("physical_adjustment_pt_grow_1", &Weapon::physical_adjustment_pt_grow_1)
		.def_readwrite("physical_adjustment_pt_grow_2", &Weapon::physical_adjustment_pt_grow_2)
		.def_readwrite("physical_adjustment_pt_grow_3", &Weapon::physical_adjustment_pt_grow_3)
		.def_readwrite("physical_adjustment_pt_grow_4", &Weapon::physical_adjustment_pt_grow_4)
		.def_readwrite("magic_calc_correct_id", &Weapon::magic_calc_correct_id)
		.def_readwrite("magic_stat_max_0", &Weapon::magic_stat_max_0)
		.def_readwrite("magic_stat_max_1", &Weapon::magic_stat_max_1)
		.def_readwrite("magic_stat_max_2", &Weapon::magic_stat_max_2)
		.def_readwrite("magic_stat_max_3", &Weapon::magic_stat_max_3)
		.def_readwrite("magic_stat_max_4", &Weapon::magic_stat_max_4)
		.def_readwrite("magic_grow_0", &Weapon::magic_grow_0)
		.def_readwrite("magic_grow_1", &Weapon::magic_grow_1)
		.def_readwrite("magic_grow_2", &Weapon::magic_grow_2)
		.def_readwrite("magic_grow_3", &Weapon::magic_grow_3)
		.def_readwrite("magic_grow_4", &Weapon::magic_grow_4)
		.def_readwrite("magic_adjustment_pt_grow_0", &Weapon::magic_adjustment_pt_grow_0)
		.def_readwrite("magic_adjustment_pt_grow_1", &Weapon::magic_adjustment_pt_grow_1)
		.def_readwrite("magic_adjustment_pt_grow_2", &Weapon::magic_adjustment_pt_grow_2)
		.def_readwrite("magic_adjustment_pt_grow_3", &Weapon::magic_adjustment_pt_grow_3)
		.def_readwrite("magic_adjustment_pt_grow_4", &Weapon::magic_adjustment_pt_grow_4)
		.def_readwrite("fire_calc_correct_id", &Weapon::fire_calc_correct_id)
		.def_readwrite("fire_stat_max_0", &Weapon::fire_stat_max_0)
		.def_readwrite("fire_stat_max_1", &Weapon::fire_stat_max_1)
		.def_readwrite("fire_stat_max_2", &Weapon::fire_stat_max_2)
		.def_readwrite("fire_stat_max_3", &Weapon::fire_stat_max_3)
		.def_readwrite("fire_stat_max_4", &Weapon::fire_stat_max_4)
		.def_readwrite("fire_grow_0", &Weapon::fire_grow_0)
		.def_readwrite("fire_grow_1", &Weapon::fire_grow_1)
		.def_readwrite("fire_grow_2", &Weapon::fire_grow_2)
		.def_readwrite("fire_grow_3", &Weapon::fire_grow_3)
		.def_readwrite("fire_grow_4", &Weapon::fire_grow_4)
		.def_readwrite("fire_adjustment_pt_grow_0", &Weapon::fire_adjustment_pt_grow_0)
		.def_readwrite("fire_adjustment_pt_grow_1", &Weapon::fire_adjustment_pt_grow_1)
		.def_readwrite("fire_adjustment_pt_grow_2", &Weapon::fire_adjustment_pt_grow_2)
		.def_readwrite("fire_adjustment_pt_grow_3", &Weapon::fire_adjustment_pt_grow_3)
		.def_readwrite("fire_adjustment_pt_grow_4", &Weapon::fire_adjustment_pt_grow_4)
		.def_readwrite("lightning_calc_correct_id", &Weapon::lightning_calc_correct_id)
		.def_readwrite("lightning_stat_max_0", &Weapon::lightning_stat_max_0)
		.def_readwrite("lightning_stat_max_1", &Weapon::lightning_stat_max_1)
		.def_readwrite("lightning_stat_max_2", &Weapon::lightning_stat_max_2)
		.def_readwrite("lightning_stat_max_3", &Weapon::lightning_stat_max_3)
		.def_readwrite("lightning_stat_max_4", &Weapon::lightning_stat_max_4)
		.def_readwrite("lightning_grow_0", &Weapon::lightning_grow_0)
		.def_readwrite("lightning_grow_1", &Weapon::lightning_grow_1)
		.def_readwrite("lightning_grow_2", &Weapon::lightning_grow_2)
		.def_readwrite("lightning_grow_3", &Weapon::lightning_grow_3)
		.def_readwrite("lightning_grow_4", &Weapon::lightning_grow_4)
		.def_readwrite("lightning_adjustment_pt_grow_0", &Weapon::lightning_adjustment_pt_grow_0)
		.def_readwrite("lightning_adjustment_pt_grow_1", &Weapon::lightning_adjustment_pt_grow_1)
		.def_readwrite("lightning_adjustment_pt_grow_2", &Weapon::lightning_adjustment_pt_grow_2)
		.def_readwrite("lightning_adjustment_pt_grow_3", &Weapon::lightning_adjustment_pt_grow_3)
		.def_readwrite("lightning_adjustment_pt_grow_4", &Weapon::lightning_adjustment_pt_grow_4)
		.def_readwrite("holy_calc_correct_id", &Weapon::holy_calc_correct_id)
		.def_readwrite("holy_stat_max_0", &Weapon::holy_stat_max_0)
		.def_readwrite("holy_stat_max_1", &Weapon::holy_stat_max_1)
		.def_readwrite("holy_stat_max_2", &Weapon::holy_stat_max_2)
		.def_readwrite("holy_stat_max_3", &Weapon::holy_stat_max_3)
		.def_readwrite("holy_stat_max_4", &Weapon::holy_stat_max_4)
		.def_readwrite("holy_grow_0", &Weapon::holy_grow_0)
		.def_readwrite("holy_grow_1", &Weapon::holy_grow_1)
		.def_readwrite("holy_grow_2", &Weapon::holy_grow_2)
		.def_readwrite("holy_grow_3", &Weapon::holy_grow_3)
		.def_readwrite("holy_grow_4", &Weapon::holy_grow_4)
		.def_readwrite("holy_adjustment_pt_grow_0", &Weapon::holy_adjustment_pt_grow_0)
		.def_readwrite("holy_adjustment_pt_grow_1", &Weapon::holy_adjustment_pt_grow_1)
		.def_readwrite("holy_adjustment_pt_grow_2", &Weapon::holy_adjustment_pt_grow_2)
		.def_readwrite("holy_adjustment_pt_grow_3", &Weapon::holy_adjustment_pt_grow_3)
		.def_readwrite("holy_adjustment_pt_grow_4", &Weapon::holy_adjustment_pt_grow_4)
		.def_readwrite("poison_calc_correct_id", &Weapon::poison_calc_correct_id)
		.def_readwrite("poison_stat_max_0", &Weapon::poison_stat_max_0)
		.def_readwrite("poison_stat_max_1", &Weapon::poison_stat_max_1)
		.def_readwrite("poison_stat_max_2", &Weapon::poison_stat_max_2)
		.def_readwrite("poison_stat_max_3", &Weapon::poison_stat_max_3)
		.def_readwrite("poison_stat_max_4", &Weapon::poison_stat_max_4)
		.def_readwrite("poison_grow_0", &Weapon::poison_grow_0)
		.def_readwrite("poison_grow_1", &Weapon::poison_grow_1)
		.def_readwrite("poison_grow_2", &Weapon::poison_grow_2)
		.def_readwrite("poison_grow_3", &Weapon::poison_grow_3)
		.def_readwrite("poison_grow_4", &Weapon::poison_grow_4)
		.def_readwrite("poison_adjustment_pt_grow_0", &Weapon::poison_adjustment_pt_grow_0)
		.def_readwrite("poison_adjustment_pt_grow_1", &Weapon::poison_adjustment_pt_grow_1)
		.def_readwrite("poison_adjustment_pt_grow_2", &Weapon::poison_adjustment_pt_grow_2)
		.def_readwrite("poison_adjustment_pt_grow_3", &Weapon::poison_adjustment_pt_grow_3)
		.def_readwrite("poison_adjustment_pt_grow_4", &Weapon::poison_adjustment_pt_grow_4)
		.def_readwrite("bleed_calc_correct_id", &Weapon::bleed_calc_correct_id)
		.def_readwrite("bleed_stat_max_0", &Weapon::bleed_stat_max_0)
		.def_readwrite("bleed_stat_max_1", &Weapon::bleed_stat_max_1)
		.def_readwrite("bleed_stat_max_2", &Weapon::bleed_stat_max_2)
		.def_readwrite("bleed_stat_max_3", &Weapon::bleed_stat_max_3)
		.def_readwrite("bleed_stat_max_4", &Weapon::bleed_stat_max_4)
		.def_readwrite("bleed_grow_0", &Weapon::bleed_grow_0)
		.def_readwrite("bleed_grow_1", &Weapon::bleed_grow_1)
		.def_readwrite("bleed_grow_2", &Weapon::bleed_grow_2)
		.def_readwrite("bleed_grow_3", &Weapon::bleed_grow_3)
		.def_readwrite("bleed_grow_4", &Weapon::bleed_grow_4)
		.def_readwrite("bleed_adjustment_pt_grow_0", &Weapon::bleed_adjustment_pt_grow_0)
		.def_readwrite("bleed_adjustment_pt_grow_1", &Weapon::bleed_adjustment_pt_grow_1)
		.def_readwrite("bleed_adjustment_pt_grow_2", &Weapon::bleed_adjustment_pt_grow_2)
		.def_readwrite("bleed_adjustment_pt_grow_3", &Weapon::bleed_adjustment_pt_grow_3)
		.def_readwrite("bleed_adjustment_pt_grow_4", &Weapon::bleed_adjustment_pt_grow_4)
		.def_readwrite("pass1_poison", &Weapon::pass1_poison)
		.def_readwrite("pass1_scarlet_rot", &Weapon::pass1_scarlet_rot)
		.def_readwrite("pass1_bleed", &Weapon::pass1_bleed)
		.def_readwrite("pass1_death", &Weapon::pass1_death)
		.def_readwrite("pass1_frost", &Weapon::pass1_frost)
		.def_readwrite("pass1_sleep", &Weapon::pass1_sleep)
		.def_readwrite("pass1_madness", &Weapon::pass1_madness)
		.def_readwrite("pass2_poison", &Weapon::pass2_poison)
		.def_readwrite("pass2_scarlet_rot", &Weapon::pass2_scarlet_rot)
		.def_readwrite("pass2_bleed", &Weapon::pass2_bleed)
		.def_readwrite("pass2_death", &Weapon::pass2_death)
		.def_readwrite("pass2_frost", &Weapon::pass2_frost)
		.def_readwrite("pass2_sleep", &Weapon::pass2_sleep)
		.def_readwrite("pass2_madness", &Weapon::pass2_madness)
		.def_readwrite("pass3_poison", &Weapon::pass3_poison)
		.def_readwrite("pass3_scarlet_rot", &Weapon::pass3_scarlet_rot)
		.def_readwrite("pass3_bleed", &Weapon::pass3_bleed)
		.def_readwrite("pass3_death", &Weapon::pass3_death)
		.def_readwrite("pass3_frost", &Weapon::pass3_frost)
		.def_readwrite("pass3_sleep", &Weapon::pass3_sleep)
		.def_readwrite("pass3_madness", &Weapon::pass3_madness)
		.def_readwrite("max_physical_dmg", &Weapon::max_physical_dmg)
		.def_readwrite("max_magic_dmg", &Weapon::max_magic_dmg)
		.def_readwrite("max_fire_dmg", &Weapon::max_fire_dmg)
		.def_readwrite("max_lightning_dmg", &Weapon::max_lightning_dmg)
		.def_readwrite("max_holy_dmg", &Weapon::max_holy_dmg)
		.def_readwrite("max_total_dmg", &Weapon::max_total_dmg)
		.def_readwrite("max_poison", &Weapon::max_poison)
		.def_readwrite("max_bleed", &Weapon::max_bleed)
		.def_readwrite("max_frostbite", &Weapon::max_frostbite)
		.def_readwrite("max_sleep", &Weapon::max_sleep)
		.def_readwrite("max_madness", &Weapon::max_madness)
		.def_readwrite("max_scarlet_rot", &Weapon::max_scarlet_rot);


#ifdef VERSION_INFO
	m.attr("__version__") = VERSION_INFO;
#else
	m.attr("__version__") = "dev";
#endif
}