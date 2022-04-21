static int inst_add_a_a(Machine::State& cpu) {
	op_add8(cpu, cpu.reg.a, cpu.reg.a);
	return 2;
}

static int inst_add_a_inddix(Machine::State& cpu) {
	const auto addr1 = calc_indDIX(cpu);
	const uint8_t data1 = Machine::read8(cpu, addr1);
	op_add8(cpu, cpu.reg.a, data1);
	return 4;
}

static int inst_add_ba_ba(Machine::State& cpu) {
	op_add16(cpu, cpu.reg.ba, cpu.reg.ba);
	return 4;
}

static int inst_add_a_b(Machine::State& cpu) {
	op_add8(cpu, cpu.reg.a, cpu.reg.b);
	return 2;
}

static int inst_add_a_inddiy(Machine::State& cpu) {
	const auto addr1 = calc_indDIY(cpu);
	const uint8_t data1 = Machine::read8(cpu, addr1);
	op_add8(cpu, cpu.reg.a, data1);
	return 4;
}

static int inst_add_ba_hl(Machine::State& cpu) {
	op_add16(cpu, cpu.reg.ba, cpu.reg.hl);
	return 4;
}

static int inst_add_a_imm8(Machine::State& cpu) {
	const uint8_t data1 = Machine::imm8(cpu);
	op_add8(cpu, cpu.reg.a, data1);
	return 2;
}

static int inst_add_a_indiix(Machine::State& cpu) {
	const auto addr1 = calc_indIIX(cpu);
	const uint8_t data1 = Machine::read8(cpu, addr1);
	op_add8(cpu, cpu.reg.a, data1);
	return 4;
}

static int inst_add_ba_ix(Machine::State& cpu) {
	op_add16(cpu, cpu.reg.ba, cpu.reg.ix);
	return 4;
}

static int inst_add_a_abshl(Machine::State& cpu) {
	const auto addr1 = calc_absHL(cpu);
	const uint8_t data1 = Machine::read8(cpu, addr1);
	op_add8(cpu, cpu.reg.a, data1);
	return 2;
}

static int inst_add_a_indiiy(Machine::State& cpu) {
	const auto addr1 = calc_indIIY(cpu);
	const uint8_t data1 = Machine::read8(cpu, addr1);
	op_add8(cpu, cpu.reg.a, data1);
	return 4;
}

static int inst_add_ba_iy(Machine::State& cpu) {
	op_add16(cpu, cpu.reg.ba, cpu.reg.iy);
	return 4;
}

static int inst_add_a_absbr(Machine::State& cpu) {
	const auto addr1 = calc_absBR(cpu);
	const uint8_t data1 = Machine::read8(cpu, addr1);
	op_add8(cpu, cpu.reg.a, data1);
	return 3;
}

static int inst_add_abshl_a(Machine::State& cpu) {
	const auto addr0 = calc_absHL(cpu);
	uint8_t data0 = Machine::read8(cpu, addr0);
	op_add8(cpu, data0, cpu.reg.a);
	Machine::write8(cpu, data0, addr0);
	return 4;
}

static int inst_adc_ba_ba(Machine::State& cpu) {
	op_adc16(cpu, cpu.reg.ba, cpu.reg.ba);
	return 4;
}

static int inst_add_a_ind16(Machine::State& cpu) {
	const auto addr1 = calc_ind16(cpu);
	const uint8_t data1 = Machine::read8(cpu, addr1);
	op_add8(cpu, cpu.reg.a, data1);
	return 4;
}

static int inst_add_abshl_imm8(Machine::State& cpu) {
	const auto addr0 = calc_absHL(cpu);
	uint8_t data0 = Machine::read8(cpu, addr0);
	const uint8_t data1 = Machine::imm8(cpu);
	op_add8(cpu, data0, data1);
	Machine::write8(cpu, data0, addr0);
	return 5;
}

static int inst_adc_ba_hl(Machine::State& cpu) {
	op_adc16(cpu, cpu.reg.ba, cpu.reg.hl);
	return 4;
}

static int inst_add_a_absix(Machine::State& cpu) {
	const auto addr1 = calc_absIX(cpu);
	const uint8_t data1 = Machine::read8(cpu, addr1);
	op_add8(cpu, cpu.reg.a, data1);
	return 2;
}

static int inst_add_abshl_absix(Machine::State& cpu) {
	const auto addr0 = calc_absHL(cpu);
	uint8_t data0 = Machine::read8(cpu, addr0);
	const auto addr1 = calc_absIX(cpu);
	const uint8_t data1 = Machine::read8(cpu, addr1);
	op_add8(cpu, data0, data1);
	Machine::write8(cpu, data0, addr0);
	return 5;
}

static int inst_adc_ba_ix(Machine::State& cpu) {
	op_adc16(cpu, cpu.reg.ba, cpu.reg.ix);
	return 4;
}

static int inst_add_a_absiy(Machine::State& cpu) {
	const auto addr1 = calc_absIY(cpu);
	const uint8_t data1 = Machine::read8(cpu, addr1);
	op_add8(cpu, cpu.reg.a, data1);
	return 2;
}

static int inst_add_abshl_absiy(Machine::State& cpu) {
	const auto addr0 = calc_absHL(cpu);
	uint8_t data0 = Machine::read8(cpu, addr0);
	const auto addr1 = calc_absIY(cpu);
	const uint8_t data1 = Machine::read8(cpu, addr1);
	op_add8(cpu, data0, data1);
	Machine::write8(cpu, data0, addr0);
	return 5;
}

static int inst_adc_ba_iy(Machine::State& cpu) {
	op_adc16(cpu, cpu.reg.ba, cpu.reg.iy);
	return 4;
}

static int inst_adc_a_a(Machine::State& cpu) {
	op_adc8(cpu, cpu.reg.a, cpu.reg.a);
	return 2;
}

static int inst_adc_a_inddix(Machine::State& cpu) {
	const auto addr1 = calc_indDIX(cpu);
	const uint8_t data1 = Machine::read8(cpu, addr1);
	op_adc8(cpu, cpu.reg.a, data1);
	return 4;
}

static int inst_sub_ba_ba(Machine::State& cpu) {
	op_sub16(cpu, cpu.reg.ba, cpu.reg.ba);
	return 4;
}

static int inst_adc_a_b(Machine::State& cpu) {
	op_adc8(cpu, cpu.reg.a, cpu.reg.b);
	return 2;
}

static int inst_adc_a_inddiy(Machine::State& cpu) {
	const auto addr1 = calc_indDIY(cpu);
	const uint8_t data1 = Machine::read8(cpu, addr1);
	op_adc8(cpu, cpu.reg.a, data1);
	return 4;
}

static int inst_sub_ba_hl(Machine::State& cpu) {
	op_sub16(cpu, cpu.reg.ba, cpu.reg.hl);
	return 4;
}

static int inst_adc_a_imm8(Machine::State& cpu) {
	const uint8_t data1 = Machine::imm8(cpu);
	op_adc8(cpu, cpu.reg.a, data1);
	return 2;
}

static int inst_adc_a_indiix(Machine::State& cpu) {
	const auto addr1 = calc_indIIX(cpu);
	const uint8_t data1 = Machine::read8(cpu, addr1);
	op_adc8(cpu, cpu.reg.a, data1);
	return 4;
}

static int inst_sub_ba_ix(Machine::State& cpu) {
	op_sub16(cpu, cpu.reg.ba, cpu.reg.ix);
	return 4;
}

static int inst_adc_a_abshl(Machine::State& cpu) {
	const auto addr1 = calc_absHL(cpu);
	const uint8_t data1 = Machine::read8(cpu, addr1);
	op_adc8(cpu, cpu.reg.a, data1);
	return 2;
}

static int inst_adc_a_indiiy(Machine::State& cpu) {
	const auto addr1 = calc_indIIY(cpu);
	const uint8_t data1 = Machine::read8(cpu, addr1);
	op_adc8(cpu, cpu.reg.a, data1);
	return 4;
}

static int inst_sub_ba_iy(Machine::State& cpu) {
	op_sub16(cpu, cpu.reg.ba, cpu.reg.iy);
	return 4;
}

static int inst_adc_a_absbr(Machine::State& cpu) {
	const auto addr1 = calc_absBR(cpu);
	const uint8_t data1 = Machine::read8(cpu, addr1);
	op_adc8(cpu, cpu.reg.a, data1);
	return 3;
}

static int inst_adc_abshl_a(Machine::State& cpu) {
	const auto addr0 = calc_absHL(cpu);
	uint8_t data0 = Machine::read8(cpu, addr0);
	op_adc8(cpu, data0, cpu.reg.a);
	Machine::write8(cpu, data0, addr0);
	return 4;
}

static int inst_sbc_ba_ba(Machine::State& cpu) {
	op_sbc16(cpu, cpu.reg.ba, cpu.reg.ba);
	return 4;
}

static int inst_adc_a_ind16(Machine::State& cpu) {
	const auto addr1 = calc_ind16(cpu);
	const uint8_t data1 = Machine::read8(cpu, addr1);
	op_adc8(cpu, cpu.reg.a, data1);
	return 4;
}

static int inst_adc_abshl_imm8(Machine::State& cpu) {
	const auto addr0 = calc_absHL(cpu);
	uint8_t data0 = Machine::read8(cpu, addr0);
	const uint8_t data1 = Machine::imm8(cpu);
	op_adc8(cpu, data0, data1);
	Machine::write8(cpu, data0, addr0);
	return 5;
}

static int inst_sbc_ba_hl(Machine::State& cpu) {
	op_sbc16(cpu, cpu.reg.ba, cpu.reg.hl);
	return 4;
}

static int inst_adc_a_absix(Machine::State& cpu) {
	const auto addr1 = calc_absIX(cpu);
	const uint8_t data1 = Machine::read8(cpu, addr1);
	op_adc8(cpu, cpu.reg.a, data1);
	return 2;
}

static int inst_adc_abshl_absix(Machine::State& cpu) {
	const auto addr0 = calc_absHL(cpu);
	uint8_t data0 = Machine::read8(cpu, addr0);
	const auto addr1 = calc_absIX(cpu);
	const uint8_t data1 = Machine::read8(cpu, addr1);
	op_adc8(cpu, data0, data1);
	Machine::write8(cpu, data0, addr0);
	return 5;
}

static int inst_sbc_ba_ix(Machine::State& cpu) {
	op_sbc16(cpu, cpu.reg.ba, cpu.reg.ix);
	return 4;
}

static int inst_adc_a_absiy(Machine::State& cpu) {
	const auto addr1 = calc_absIY(cpu);
	const uint8_t data1 = Machine::read8(cpu, addr1);
	op_adc8(cpu, cpu.reg.a, data1);
	return 2;
}

static int inst_adc_abshl_absiy(Machine::State& cpu) {
	const auto addr0 = calc_absHL(cpu);
	uint8_t data0 = Machine::read8(cpu, addr0);
	const auto addr1 = calc_absIY(cpu);
	const uint8_t data1 = Machine::read8(cpu, addr1);
	op_adc8(cpu, data0, data1);
	Machine::write8(cpu, data0, addr0);
	return 5;
}

static int inst_sbc_ba_iy(Machine::State& cpu) {
	op_sbc16(cpu, cpu.reg.ba, cpu.reg.iy);
	return 4;
}

static int inst_sub_a_a(Machine::State& cpu) {
	op_sub8(cpu, cpu.reg.a, cpu.reg.a);
	return 2;
}

static int inst_sub_a_inddix(Machine::State& cpu) {
	const auto addr1 = calc_indDIX(cpu);
	const uint8_t data1 = Machine::read8(cpu, addr1);
	op_sub8(cpu, cpu.reg.a, data1);
	return 4;
}

static int inst_sub_a_b(Machine::State& cpu) {
	op_sub8(cpu, cpu.reg.a, cpu.reg.b);
	return 2;
}

static int inst_sub_a_inddiy(Machine::State& cpu) {
	const auto addr1 = calc_indDIY(cpu);
	const uint8_t data1 = Machine::read8(cpu, addr1);
	op_sub8(cpu, cpu.reg.a, data1);
	return 4;
}

static int inst_sub_a_imm8(Machine::State& cpu) {
	const uint8_t data1 = Machine::imm8(cpu);
	op_sub8(cpu, cpu.reg.a, data1);
	return 2;
}

static int inst_sub_a_indiix(Machine::State& cpu) {
	const auto addr1 = calc_indIIX(cpu);
	const uint8_t data1 = Machine::read8(cpu, addr1);
	op_sub8(cpu, cpu.reg.a, data1);
	return 4;
}

static int inst_sub_a_abshl(Machine::State& cpu) {
	const auto addr1 = calc_absHL(cpu);
	const uint8_t data1 = Machine::read8(cpu, addr1);
	op_sub8(cpu, cpu.reg.a, data1);
	return 2;
}

static int inst_sub_a_indiiy(Machine::State& cpu) {
	const auto addr1 = calc_indIIY(cpu);
	const uint8_t data1 = Machine::read8(cpu, addr1);
	op_sub8(cpu, cpu.reg.a, data1);
	return 4;
}

static int inst_sub_a_absbr(Machine::State& cpu) {
	const auto addr1 = calc_absBR(cpu);
	const uint8_t data1 = Machine::read8(cpu, addr1);
	op_sub8(cpu, cpu.reg.a, data1);
	return 3;
}

static int inst_sub_abshl_a(Machine::State& cpu) {
	const auto addr0 = calc_absHL(cpu);
	uint8_t data0 = Machine::read8(cpu, addr0);
	op_sub8(cpu, data0, cpu.reg.a);
	Machine::write8(cpu, data0, addr0);
	return 4;
}

static int inst_sub_a_ind16(Machine::State& cpu) {
	const auto addr1 = calc_ind16(cpu);
	const uint8_t data1 = Machine::read8(cpu, addr1);
	op_sub8(cpu, cpu.reg.a, data1);
	return 4;
}

static int inst_sub_abshl_imm8(Machine::State& cpu) {
	const auto addr0 = calc_absHL(cpu);
	uint8_t data0 = Machine::read8(cpu, addr0);
	const uint8_t data1 = Machine::imm8(cpu);
	op_sub8(cpu, data0, data1);
	Machine::write8(cpu, data0, addr0);
	return 5;
}

static int inst_sub_a_absix(Machine::State& cpu) {
	const auto addr1 = calc_absIX(cpu);
	const uint8_t data1 = Machine::read8(cpu, addr1);
	op_sub8(cpu, cpu.reg.a, data1);
	return 2;
}

static int inst_sub_abshl_absix(Machine::State& cpu) {
	const auto addr0 = calc_absHL(cpu);
	uint8_t data0 = Machine::read8(cpu, addr0);
	const auto addr1 = calc_absIX(cpu);
	const uint8_t data1 = Machine::read8(cpu, addr1);
	op_sub8(cpu, data0, data1);
	Machine::write8(cpu, data0, addr0);
	return 5;
}

static int inst_sub_a_absiy(Machine::State& cpu) {
	const auto addr1 = calc_absIY(cpu);
	const uint8_t data1 = Machine::read8(cpu, addr1);
	op_sub8(cpu, cpu.reg.a, data1);
	return 2;
}

static int inst_sub_abshl_absiy(Machine::State& cpu) {
	const auto addr0 = calc_absHL(cpu);
	uint8_t data0 = Machine::read8(cpu, addr0);
	const auto addr1 = calc_absIY(cpu);
	const uint8_t data1 = Machine::read8(cpu, addr1);
	op_sub8(cpu, data0, data1);
	Machine::write8(cpu, data0, addr0);
	return 5;
}

static int inst_sbc_a_a(Machine::State& cpu) {
	op_sbc8(cpu, cpu.reg.a, cpu.reg.a);
	return 2;
}

static int inst_sbc_a_inddix(Machine::State& cpu) {
	const auto addr1 = calc_indDIX(cpu);
	const uint8_t data1 = Machine::read8(cpu, addr1);
	op_sbc8(cpu, cpu.reg.a, data1);
	return 4;
}

static int inst_cp_ba_ba(Machine::State& cpu) {
	op_cp16(cpu, cpu.reg.ba, cpu.reg.ba);
	return 4;
}

static int inst_sbc_a_b(Machine::State& cpu) {
	op_sbc8(cpu, cpu.reg.a, cpu.reg.b);
	return 2;
}

static int inst_sbc_a_inddiy(Machine::State& cpu) {
	const auto addr1 = calc_indDIY(cpu);
	const uint8_t data1 = Machine::read8(cpu, addr1);
	op_sbc8(cpu, cpu.reg.a, data1);
	return 4;
}

static int inst_cp_ba_hl(Machine::State& cpu) {
	op_cp16(cpu, cpu.reg.ba, cpu.reg.hl);
	return 4;
}

static int inst_sbc_a_imm8(Machine::State& cpu) {
	const uint8_t data1 = Machine::imm8(cpu);
	op_sbc8(cpu, cpu.reg.a, data1);
	return 2;
}

static int inst_sbc_a_indiix(Machine::State& cpu) {
	const auto addr1 = calc_indIIX(cpu);
	const uint8_t data1 = Machine::read8(cpu, addr1);
	op_sbc8(cpu, cpu.reg.a, data1);
	return 4;
}

static int inst_cp_ba_ix(Machine::State& cpu) {
	op_cp16(cpu, cpu.reg.ba, cpu.reg.ix);
	return 4;
}

static int inst_sbc_a_abshl(Machine::State& cpu) {
	const auto addr1 = calc_absHL(cpu);
	const uint8_t data1 = Machine::read8(cpu, addr1);
	op_sbc8(cpu, cpu.reg.a, data1);
	return 2;
}

static int inst_sbc_a_indiiy(Machine::State& cpu) {
	const auto addr1 = calc_indIIY(cpu);
	const uint8_t data1 = Machine::read8(cpu, addr1);
	op_sbc8(cpu, cpu.reg.a, data1);
	return 4;
}

static int inst_cp_ba_iy(Machine::State& cpu) {
	op_cp16(cpu, cpu.reg.ba, cpu.reg.iy);
	return 4;
}

static int inst_sbc_a_absbr(Machine::State& cpu) {
	const auto addr1 = calc_absBR(cpu);
	const uint8_t data1 = Machine::read8(cpu, addr1);
	op_sbc8(cpu, cpu.reg.a, data1);
	return 3;
}

static int inst_sbc_abshl_a(Machine::State& cpu) {
	const auto addr0 = calc_absHL(cpu);
	uint8_t data0 = Machine::read8(cpu, addr0);
	op_sbc8(cpu, data0, cpu.reg.a);
	Machine::write8(cpu, data0, addr0);
	return 4;
}

static int inst_sbc_a_ind16(Machine::State& cpu) {
	const auto addr1 = calc_ind16(cpu);
	const uint8_t data1 = Machine::read8(cpu, addr1);
	op_sbc8(cpu, cpu.reg.a, data1);
	return 4;
}

static int inst_sbc_abshl_imm8(Machine::State& cpu) {
	const auto addr0 = calc_absHL(cpu);
	uint8_t data0 = Machine::read8(cpu, addr0);
	const uint8_t data1 = Machine::imm8(cpu);
	op_sbc8(cpu, data0, data1);
	Machine::write8(cpu, data0, addr0);
	return 5;
}

static int inst_sbc_a_absix(Machine::State& cpu) {
	const auto addr1 = calc_absIX(cpu);
	const uint8_t data1 = Machine::read8(cpu, addr1);
	op_sbc8(cpu, cpu.reg.a, data1);
	return 2;
}

static int inst_sbc_abshl_absix(Machine::State& cpu) {
	const auto addr0 = calc_absHL(cpu);
	uint8_t data0 = Machine::read8(cpu, addr0);
	const auto addr1 = calc_absIX(cpu);
	const uint8_t data1 = Machine::read8(cpu, addr1);
	op_sbc8(cpu, data0, data1);
	Machine::write8(cpu, data0, addr0);
	return 5;
}

static int inst_sbc_a_absiy(Machine::State& cpu) {
	const auto addr1 = calc_absIY(cpu);
	const uint8_t data1 = Machine::read8(cpu, addr1);
	op_sbc8(cpu, cpu.reg.a, data1);
	return 2;
}

static int inst_sbc_abshl_absiy(Machine::State& cpu) {
	const auto addr0 = calc_absHL(cpu);
	uint8_t data0 = Machine::read8(cpu, addr0);
	const auto addr1 = calc_absIY(cpu);
	const uint8_t data1 = Machine::read8(cpu, addr1);
	op_sbc8(cpu, data0, data1);
	Machine::write8(cpu, data0, addr0);
	return 5;
}

static int inst_and_a_a(Machine::State& cpu) {
	op_and8(cpu, cpu.reg.a, cpu.reg.a);
	return 2;
}

static int inst_and_a_inddix(Machine::State& cpu) {
	const auto addr1 = calc_indDIX(cpu);
	const uint8_t data1 = Machine::read8(cpu, addr1);
	op_and8(cpu, cpu.reg.a, data1);
	return 4;
}

static int inst_add_hl_ba(Machine::State& cpu) {
	op_add16(cpu, cpu.reg.hl, cpu.reg.ba);
	return 4;
}

static int inst_and_a_b(Machine::State& cpu) {
	op_and8(cpu, cpu.reg.a, cpu.reg.b);
	return 2;
}

static int inst_and_a_inddiy(Machine::State& cpu) {
	const auto addr1 = calc_indDIY(cpu);
	const uint8_t data1 = Machine::read8(cpu, addr1);
	op_and8(cpu, cpu.reg.a, data1);
	return 4;
}

static int inst_add_hl_hl(Machine::State& cpu) {
	op_add16(cpu, cpu.reg.hl, cpu.reg.hl);
	return 4;
}

static int inst_and_a_imm8(Machine::State& cpu) {
	const uint8_t data1 = Machine::imm8(cpu);
	op_and8(cpu, cpu.reg.a, data1);
	return 2;
}

static int inst_and_a_indiix(Machine::State& cpu) {
	const auto addr1 = calc_indIIX(cpu);
	const uint8_t data1 = Machine::read8(cpu, addr1);
	op_and8(cpu, cpu.reg.a, data1);
	return 4;
}

static int inst_add_hl_ix(Machine::State& cpu) {
	op_add16(cpu, cpu.reg.hl, cpu.reg.ix);
	return 4;
}

static int inst_and_a_abshl(Machine::State& cpu) {
	const auto addr1 = calc_absHL(cpu);
	const uint8_t data1 = Machine::read8(cpu, addr1);
	op_and8(cpu, cpu.reg.a, data1);
	return 2;
}

static int inst_and_a_indiiy(Machine::State& cpu) {
	const auto addr1 = calc_indIIY(cpu);
	const uint8_t data1 = Machine::read8(cpu, addr1);
	op_and8(cpu, cpu.reg.a, data1);
	return 4;
}

static int inst_add_hl_iy(Machine::State& cpu) {
	op_add16(cpu, cpu.reg.hl, cpu.reg.iy);
	return 4;
}

static int inst_and_a_absbr(Machine::State& cpu) {
	const auto addr1 = calc_absBR(cpu);
	const uint8_t data1 = Machine::read8(cpu, addr1);
	op_and8(cpu, cpu.reg.a, data1);
	return 3;
}

static int inst_and_abshl_a(Machine::State& cpu) {
	const auto addr0 = calc_absHL(cpu);
	uint8_t data0 = Machine::read8(cpu, addr0);
	op_and8(cpu, data0, cpu.reg.a);
	Machine::write8(cpu, data0, addr0);
	return 4;
}

static int inst_adc_hl_ba(Machine::State& cpu) {
	op_adc16(cpu, cpu.reg.hl, cpu.reg.ba);
	return 4;
}

static int inst_and_a_ind16(Machine::State& cpu) {
	const auto addr1 = calc_ind16(cpu);
	const uint8_t data1 = Machine::read8(cpu, addr1);
	op_and8(cpu, cpu.reg.a, data1);
	return 4;
}

static int inst_and_abshl_imm8(Machine::State& cpu) {
	const auto addr0 = calc_absHL(cpu);
	uint8_t data0 = Machine::read8(cpu, addr0);
	const uint8_t data1 = Machine::imm8(cpu);
	op_and8(cpu, data0, data1);
	Machine::write8(cpu, data0, addr0);
	return 5;
}

static int inst_adc_hl_hl(Machine::State& cpu) {
	op_adc16(cpu, cpu.reg.hl, cpu.reg.hl);
	return 4;
}

static int inst_and_a_absix(Machine::State& cpu) {
	const auto addr1 = calc_absIX(cpu);
	const uint8_t data1 = Machine::read8(cpu, addr1);
	op_and8(cpu, cpu.reg.a, data1);
	return 2;
}

static int inst_and_abshl_absix(Machine::State& cpu) {
	const auto addr0 = calc_absHL(cpu);
	uint8_t data0 = Machine::read8(cpu, addr0);
	const auto addr1 = calc_absIX(cpu);
	const uint8_t data1 = Machine::read8(cpu, addr1);
	op_and8(cpu, data0, data1);
	Machine::write8(cpu, data0, addr0);
	return 5;
}

static int inst_adc_hl_ix(Machine::State& cpu) {
	op_adc16(cpu, cpu.reg.hl, cpu.reg.ix);
	return 4;
}

static int inst_and_a_absiy(Machine::State& cpu) {
	const auto addr1 = calc_absIY(cpu);
	const uint8_t data1 = Machine::read8(cpu, addr1);
	op_and8(cpu, cpu.reg.a, data1);
	return 2;
}

static int inst_and_abshl_absiy(Machine::State& cpu) {
	const auto addr0 = calc_absHL(cpu);
	uint8_t data0 = Machine::read8(cpu, addr0);
	const auto addr1 = calc_absIY(cpu);
	const uint8_t data1 = Machine::read8(cpu, addr1);
	op_and8(cpu, data0, data1);
	Machine::write8(cpu, data0, addr0);
	return 5;
}

static int inst_adc_hl_iy(Machine::State& cpu) {
	op_adc16(cpu, cpu.reg.hl, cpu.reg.iy);
	return 4;
}

static int inst_or_a_a(Machine::State& cpu) {
	op_or8(cpu, cpu.reg.a, cpu.reg.a);
	return 2;
}

static int inst_or_a_inddix(Machine::State& cpu) {
	const auto addr1 = calc_indDIX(cpu);
	const uint8_t data1 = Machine::read8(cpu, addr1);
	op_or8(cpu, cpu.reg.a, data1);
	return 4;
}

static int inst_sub_hl_ba(Machine::State& cpu) {
	op_sub16(cpu, cpu.reg.hl, cpu.reg.ba);
	return 4;
}

static int inst_or_a_b(Machine::State& cpu) {
	op_or8(cpu, cpu.reg.a, cpu.reg.b);
	return 2;
}

static int inst_or_a_inddiy(Machine::State& cpu) {
	const auto addr1 = calc_indDIY(cpu);
	const uint8_t data1 = Machine::read8(cpu, addr1);
	op_or8(cpu, cpu.reg.a, data1);
	return 4;
}

static int inst_sub_hl_hl(Machine::State& cpu) {
	op_sub16(cpu, cpu.reg.hl, cpu.reg.hl);
	return 4;
}

static int inst_or_a_imm8(Machine::State& cpu) {
	const uint8_t data1 = Machine::imm8(cpu);
	op_or8(cpu, cpu.reg.a, data1);
	return 2;
}

static int inst_or_a_indiix(Machine::State& cpu) {
	const auto addr1 = calc_indIIX(cpu);
	const uint8_t data1 = Machine::read8(cpu, addr1);
	op_or8(cpu, cpu.reg.a, data1);
	return 4;
}

static int inst_sub_hl_ix(Machine::State& cpu) {
	op_sub16(cpu, cpu.reg.hl, cpu.reg.ix);
	return 4;
}

static int inst_or_a_abshl(Machine::State& cpu) {
	const auto addr1 = calc_absHL(cpu);
	const uint8_t data1 = Machine::read8(cpu, addr1);
	op_or8(cpu, cpu.reg.a, data1);
	return 2;
}

static int inst_or_a_indiiy(Machine::State& cpu) {
	const auto addr1 = calc_indIIY(cpu);
	const uint8_t data1 = Machine::read8(cpu, addr1);
	op_or8(cpu, cpu.reg.a, data1);
	return 4;
}

static int inst_sub_hl_iy(Machine::State& cpu) {
	op_sub16(cpu, cpu.reg.hl, cpu.reg.iy);
	return 4;
}

static int inst_or_a_absbr(Machine::State& cpu) {
	const auto addr1 = calc_absBR(cpu);
	const uint8_t data1 = Machine::read8(cpu, addr1);
	op_or8(cpu, cpu.reg.a, data1);
	return 3;
}

static int inst_or_abshl_a(Machine::State& cpu) {
	const auto addr0 = calc_absHL(cpu);
	uint8_t data0 = Machine::read8(cpu, addr0);
	op_or8(cpu, data0, cpu.reg.a);
	Machine::write8(cpu, data0, addr0);
	return 4;
}

static int inst_sbc_hl_ba(Machine::State& cpu) {
	op_sbc16(cpu, cpu.reg.hl, cpu.reg.ba);
	return 4;
}

static int inst_or_a_ind16(Machine::State& cpu) {
	const auto addr1 = calc_ind16(cpu);
	const uint8_t data1 = Machine::read8(cpu, addr1);
	op_or8(cpu, cpu.reg.a, data1);
	return 4;
}

static int inst_or_abshl_imm8(Machine::State& cpu) {
	const auto addr0 = calc_absHL(cpu);
	uint8_t data0 = Machine::read8(cpu, addr0);
	const uint8_t data1 = Machine::imm8(cpu);
	op_or8(cpu, data0, data1);
	Machine::write8(cpu, data0, addr0);
	return 5;
}

static int inst_sbc_hl_hl(Machine::State& cpu) {
	op_sbc16(cpu, cpu.reg.hl, cpu.reg.hl);
	return 4;
}

static int inst_or_a_absix(Machine::State& cpu) {
	const auto addr1 = calc_absIX(cpu);
	const uint8_t data1 = Machine::read8(cpu, addr1);
	op_or8(cpu, cpu.reg.a, data1);
	return 2;
}

static int inst_or_abshl_absix(Machine::State& cpu) {
	const auto addr0 = calc_absHL(cpu);
	uint8_t data0 = Machine::read8(cpu, addr0);
	const auto addr1 = calc_absIX(cpu);
	const uint8_t data1 = Machine::read8(cpu, addr1);
	op_or8(cpu, data0, data1);
	Machine::write8(cpu, data0, addr0);
	return 5;
}

static int inst_sbc_hl_ix(Machine::State& cpu) {
	op_sbc16(cpu, cpu.reg.hl, cpu.reg.ix);
	return 4;
}

static int inst_or_a_absiy(Machine::State& cpu) {
	const auto addr1 = calc_absIY(cpu);
	const uint8_t data1 = Machine::read8(cpu, addr1);
	op_or8(cpu, cpu.reg.a, data1);
	return 2;
}

static int inst_or_abshl_absiy(Machine::State& cpu) {
	const auto addr0 = calc_absHL(cpu);
	uint8_t data0 = Machine::read8(cpu, addr0);
	const auto addr1 = calc_absIY(cpu);
	const uint8_t data1 = Machine::read8(cpu, addr1);
	op_or8(cpu, data0, data1);
	Machine::write8(cpu, data0, addr0);
	return 5;
}

static int inst_sbc_hl_iy(Machine::State& cpu) {
	op_sbc16(cpu, cpu.reg.hl, cpu.reg.iy);
	return 4;
}

static int inst_cp_a_a(Machine::State& cpu) {
	op_cp8(cpu, cpu.reg.a, cpu.reg.a);
	return 2;
}

static int inst_cp_a_inddix(Machine::State& cpu) {
	const auto addr1 = calc_indDIX(cpu);
	const uint8_t data1 = Machine::read8(cpu, addr1);
	op_cp8(cpu, cpu.reg.a, data1);
	return 4;
}

static int inst_cp_a_b(Machine::State& cpu) {
	op_cp8(cpu, cpu.reg.a, cpu.reg.b);
	return 2;
}

static int inst_cp_a_inddiy(Machine::State& cpu) {
	const auto addr1 = calc_indDIY(cpu);
	const uint8_t data1 = Machine::read8(cpu, addr1);
	op_cp8(cpu, cpu.reg.a, data1);
	return 4;
}

static int inst_cp_a_imm8(Machine::State& cpu) {
	const uint8_t data1 = Machine::imm8(cpu);
	op_cp8(cpu, cpu.reg.a, data1);
	return 2;
}

static int inst_cp_a_indiix(Machine::State& cpu) {
	const auto addr1 = calc_indIIX(cpu);
	const uint8_t data1 = Machine::read8(cpu, addr1);
	op_cp8(cpu, cpu.reg.a, data1);
	return 4;
}

static int inst_cp_a_abshl(Machine::State& cpu) {
	const auto addr1 = calc_absHL(cpu);
	const uint8_t data1 = Machine::read8(cpu, addr1);
	op_cp8(cpu, cpu.reg.a, data1);
	return 2;
}

static int inst_cp_a_indiiy(Machine::State& cpu) {
	const auto addr1 = calc_indIIY(cpu);
	const uint8_t data1 = Machine::read8(cpu, addr1);
	op_cp8(cpu, cpu.reg.a, data1);
	return 4;
}

static int inst_cp_a_absbr(Machine::State& cpu) {
	const auto addr1 = calc_absBR(cpu);
	const uint8_t data1 = Machine::read8(cpu, addr1);
	op_cp8(cpu, cpu.reg.a, data1);
	return 3;
}

static int inst_cp_abshl_a(Machine::State& cpu) {
	const auto addr0 = calc_absHL(cpu);
	const uint8_t data0 = Machine::read8(cpu, addr0);
	op_cp8(cpu, data0, cpu.reg.a);
	return 3;
}

static int inst_cp_a_ind16(Machine::State& cpu) {
	const auto addr1 = calc_ind16(cpu);
	const uint8_t data1 = Machine::read8(cpu, addr1);
	op_cp8(cpu, cpu.reg.a, data1);
	return 4;
}

static int inst_cp_abshl_imm8(Machine::State& cpu) {
	const auto addr0 = calc_absHL(cpu);
	const uint8_t data0 = Machine::read8(cpu, addr0);
	const uint8_t data1 = Machine::imm8(cpu);
	op_cp8(cpu, data0, data1);
	return 4;
}

static int inst_cp_a_absix(Machine::State& cpu) {
	const auto addr1 = calc_absIX(cpu);
	const uint8_t data1 = Machine::read8(cpu, addr1);
	op_cp8(cpu, cpu.reg.a, data1);
	return 2;
}

static int inst_cp_abshl_absix(Machine::State& cpu) {
	const auto addr0 = calc_absHL(cpu);
	const uint8_t data0 = Machine::read8(cpu, addr0);
	const auto addr1 = calc_absIX(cpu);
	const uint8_t data1 = Machine::read8(cpu, addr1);
	op_cp8(cpu, data0, data1);
	return 4;
}

static int inst_cp_a_absiy(Machine::State& cpu) {
	const auto addr1 = calc_absIY(cpu);
	const uint8_t data1 = Machine::read8(cpu, addr1);
	op_cp8(cpu, cpu.reg.a, data1);
	return 2;
}

static int inst_cp_abshl_absiy(Machine::State& cpu) {
	const auto addr0 = calc_absHL(cpu);
	const uint8_t data0 = Machine::read8(cpu, addr0);
	const auto addr1 = calc_absIY(cpu);
	const uint8_t data1 = Machine::read8(cpu, addr1);
	op_cp8(cpu, data0, data1);
	return 4;
}

static int inst_xor_a_a(Machine::State& cpu) {
	op_xor8(cpu, cpu.reg.a, cpu.reg.a);
	return 2;
}

static int inst_xor_a_inddix(Machine::State& cpu) {
	const auto addr1 = calc_indDIX(cpu);
	const uint8_t data1 = Machine::read8(cpu, addr1);
	op_xor8(cpu, cpu.reg.a, data1);
	return 4;
}

static int inst_cp_hl_ba(Machine::State& cpu) {
	op_cp16(cpu, cpu.reg.hl, cpu.reg.ba);
	return 4;
}

static int inst_xor_a_b(Machine::State& cpu) {
	op_xor8(cpu, cpu.reg.a, cpu.reg.b);
	return 2;
}

static int inst_xor_a_inddiy(Machine::State& cpu) {
	const auto addr1 = calc_indDIY(cpu);
	const uint8_t data1 = Machine::read8(cpu, addr1);
	op_xor8(cpu, cpu.reg.a, data1);
	return 4;
}

static int inst_cp_hl_hl(Machine::State& cpu) {
	op_cp16(cpu, cpu.reg.hl, cpu.reg.hl);
	return 4;
}

static int inst_xor_a_imm8(Machine::State& cpu) {
	const uint8_t data1 = Machine::imm8(cpu);
	op_xor8(cpu, cpu.reg.a, data1);
	return 2;
}

static int inst_xor_a_indiix(Machine::State& cpu) {
	const auto addr1 = calc_indIIX(cpu);
	const uint8_t data1 = Machine::read8(cpu, addr1);
	op_xor8(cpu, cpu.reg.a, data1);
	return 4;
}

static int inst_cp_hl_ix(Machine::State& cpu) {
	op_cp16(cpu, cpu.reg.hl, cpu.reg.ix);
	return 4;
}

static int inst_xor_a_abshl(Machine::State& cpu) {
	const auto addr1 = calc_absHL(cpu);
	const uint8_t data1 = Machine::read8(cpu, addr1);
	op_xor8(cpu, cpu.reg.a, data1);
	return 2;
}

static int inst_xor_a_indiiy(Machine::State& cpu) {
	const auto addr1 = calc_indIIY(cpu);
	const uint8_t data1 = Machine::read8(cpu, addr1);
	op_xor8(cpu, cpu.reg.a, data1);
	return 4;
}

static int inst_cp_hl_iy(Machine::State& cpu) {
	op_cp16(cpu, cpu.reg.hl, cpu.reg.iy);
	return 4;
}

static int inst_xor_a_absbr(Machine::State& cpu) {
	const auto addr1 = calc_absBR(cpu);
	const uint8_t data1 = Machine::read8(cpu, addr1);
	op_xor8(cpu, cpu.reg.a, data1);
	return 3;
}

static int inst_xor_abshl_a(Machine::State& cpu) {
	const auto addr0 = calc_absHL(cpu);
	uint8_t data0 = Machine::read8(cpu, addr0);
	op_xor8(cpu, data0, cpu.reg.a);
	Machine::write8(cpu, data0, addr0);
	return 4;
}

static int inst_xor_a_ind16(Machine::State& cpu) {
	const auto addr1 = calc_ind16(cpu);
	const uint8_t data1 = Machine::read8(cpu, addr1);
	op_xor8(cpu, cpu.reg.a, data1);
	return 4;
}

static int inst_xor_abshl_imm8(Machine::State& cpu) {
	const auto addr0 = calc_absHL(cpu);
	uint8_t data0 = Machine::read8(cpu, addr0);
	const uint8_t data1 = Machine::imm8(cpu);
	op_xor8(cpu, data0, data1);
	Machine::write8(cpu, data0, addr0);
	return 5;
}

static int inst_xor_a_absix(Machine::State& cpu) {
	const auto addr1 = calc_absIX(cpu);
	const uint8_t data1 = Machine::read8(cpu, addr1);
	op_xor8(cpu, cpu.reg.a, data1);
	return 2;
}

static int inst_xor_abshl_absix(Machine::State& cpu) {
	const auto addr0 = calc_absHL(cpu);
	uint8_t data0 = Machine::read8(cpu, addr0);
	const auto addr1 = calc_absIX(cpu);
	const uint8_t data1 = Machine::read8(cpu, addr1);
	op_xor8(cpu, data0, data1);
	Machine::write8(cpu, data0, addr0);
	return 5;
}

static int inst_xor_a_absiy(Machine::State& cpu) {
	const auto addr1 = calc_absIY(cpu);
	const uint8_t data1 = Machine::read8(cpu, addr1);
	op_xor8(cpu, cpu.reg.a, data1);
	return 2;
}

static int inst_xor_abshl_absiy(Machine::State& cpu) {
	const auto addr0 = calc_absHL(cpu);
	uint8_t data0 = Machine::read8(cpu, addr0);
	const auto addr1 = calc_absIY(cpu);
	const uint8_t data1 = Machine::read8(cpu, addr1);
	op_xor8(cpu, data0, data1);
	Machine::write8(cpu, data0, addr0);
	return 5;
}

static int inst_ld_a_a(Machine::State& cpu) {
	op_ld8(cpu, cpu.reg.a, cpu.reg.a);
	return 1;
}

static int inst_ld_a_inddix(Machine::State& cpu) {
	const auto addr1 = calc_indDIX(cpu);
	const uint8_t data1 = Machine::read8(cpu, addr1);
	op_ld8(cpu, cpu.reg.a, data1);
	return 4;
}

static int inst_add_ix_ba(Machine::State& cpu) {
	op_add16(cpu, cpu.reg.ix, cpu.reg.ba);
	return 4;
}

static int inst_ld_a_b(Machine::State& cpu) {
	op_ld8(cpu, cpu.reg.a, cpu.reg.b);
	return 1;
}

static int inst_ld_a_inddiy(Machine::State& cpu) {
	const auto addr1 = calc_indDIY(cpu);
	const uint8_t data1 = Machine::read8(cpu, addr1);
	op_ld8(cpu, cpu.reg.a, data1);
	return 4;
}

static int inst_add_ix_hl(Machine::State& cpu) {
	op_add16(cpu, cpu.reg.ix, cpu.reg.hl);
	return 4;
}

static int inst_ld_a_l(Machine::State& cpu) {
	op_ld8(cpu, cpu.reg.a, cpu.reg.l);
	return 1;
}

static int inst_ld_a_indiix(Machine::State& cpu) {
	const auto addr1 = calc_indIIX(cpu);
	const uint8_t data1 = Machine::read8(cpu, addr1);
	op_ld8(cpu, cpu.reg.a, data1);
	return 4;
}

static int inst_add_iy_ba(Machine::State& cpu) {
	op_add16(cpu, cpu.reg.iy, cpu.reg.ba);
	return 4;
}

static int inst_ld_a_h(Machine::State& cpu) {
	op_ld8(cpu, cpu.reg.a, cpu.reg.h);
	return 1;
}

static int inst_ld_a_indiiy(Machine::State& cpu) {
	const auto addr1 = calc_indIIY(cpu);
	const uint8_t data1 = Machine::read8(cpu, addr1);
	op_ld8(cpu, cpu.reg.a, data1);
	return 4;
}

static int inst_add_iy_hl(Machine::State& cpu) {
	op_add16(cpu, cpu.reg.iy, cpu.reg.hl);
	return 4;
}

static int inst_ld_a_absbr(Machine::State& cpu) {
	const auto addr1 = calc_absBR(cpu);
	const uint8_t data1 = Machine::read8(cpu, addr1);
	op_ld8(cpu, cpu.reg.a, data1);
	return 3;
}

static int inst_ld_inddix_a(Machine::State& cpu) {
	const auto addr0 = calc_indDIX(cpu);
	uint8_t data0;
	op_ld8(cpu, data0, cpu.reg.a);
	Machine::write8(cpu, data0, addr0);
	return 4;
}

static int inst_add_sp_ba(Machine::State& cpu) {
	op_add16(cpu, cpu.reg.sp, cpu.reg.ba);
	return 4;
}

static int inst_ld_a_abshl(Machine::State& cpu) {
	const auto addr1 = calc_absHL(cpu);
	const uint8_t data1 = Machine::read8(cpu, addr1);
	op_ld8(cpu, cpu.reg.a, data1);
	return 2;
}

static int inst_ld_inddiy_a(Machine::State& cpu) {
	const auto addr0 = calc_indDIY(cpu);
	uint8_t data0;
	op_ld8(cpu, data0, cpu.reg.a);
	Machine::write8(cpu, data0, addr0);
	return 4;
}

static int inst_add_sp_hl(Machine::State& cpu) {
	op_add16(cpu, cpu.reg.sp, cpu.reg.hl);
	return 4;
}

static int inst_ld_a_absix(Machine::State& cpu) {
	const auto addr1 = calc_absIX(cpu);
	const uint8_t data1 = Machine::read8(cpu, addr1);
	op_ld8(cpu, cpu.reg.a, data1);
	return 2;
}

static int inst_ld_indiix_a(Machine::State& cpu) {
	const auto addr0 = calc_indIIX(cpu);
	uint8_t data0;
	op_ld8(cpu, data0, cpu.reg.a);
	Machine::write8(cpu, data0, addr0);
	return 4;
}

static int inst_ld_a_absiy(Machine::State& cpu) {
	const auto addr1 = calc_absIY(cpu);
	const uint8_t data1 = Machine::read8(cpu, addr1);
	op_ld8(cpu, cpu.reg.a, data1);
	return 2;
}

static int inst_ld_indiiy_a(Machine::State& cpu) {
	const auto addr0 = calc_indIIY(cpu);
	uint8_t data0;
	op_ld8(cpu, data0, cpu.reg.a);
	Machine::write8(cpu, data0, addr0);
	return 4;
}

static int inst_ld_b_a(Machine::State& cpu) {
	op_ld8(cpu, cpu.reg.b, cpu.reg.a);
	return 1;
}

static int inst_ld_b_inddix(Machine::State& cpu) {
	const auto addr1 = calc_indDIX(cpu);
	const uint8_t data1 = Machine::read8(cpu, addr1);
	op_ld8(cpu, cpu.reg.b, data1);
	return 4;
}

static int inst_sub_ix_ba(Machine::State& cpu) {
	op_sub16(cpu, cpu.reg.ix, cpu.reg.ba);
	return 4;
}

static int inst_ld_b_b(Machine::State& cpu) {
	op_ld8(cpu, cpu.reg.b, cpu.reg.b);
	return 1;
}

static int inst_ld_b_inddiy(Machine::State& cpu) {
	const auto addr1 = calc_indDIY(cpu);
	const uint8_t data1 = Machine::read8(cpu, addr1);
	op_ld8(cpu, cpu.reg.b, data1);
	return 4;
}

static int inst_sub_ix_hl(Machine::State& cpu) {
	op_sub16(cpu, cpu.reg.ix, cpu.reg.hl);
	return 4;
}

static int inst_ld_b_l(Machine::State& cpu) {
	op_ld8(cpu, cpu.reg.b, cpu.reg.l);
	return 1;
}

static int inst_ld_b_indiix(Machine::State& cpu) {
	const auto addr1 = calc_indIIX(cpu);
	const uint8_t data1 = Machine::read8(cpu, addr1);
	op_ld8(cpu, cpu.reg.b, data1);
	return 4;
}

static int inst_sub_iy_ba(Machine::State& cpu) {
	op_sub16(cpu, cpu.reg.iy, cpu.reg.ba);
	return 4;
}

static int inst_ld_b_h(Machine::State& cpu) {
	op_ld8(cpu, cpu.reg.b, cpu.reg.h);
	return 1;
}

static int inst_ld_b_indiiy(Machine::State& cpu) {
	const auto addr1 = calc_indIIY(cpu);
	const uint8_t data1 = Machine::read8(cpu, addr1);
	op_ld8(cpu, cpu.reg.b, data1);
	return 4;
}

static int inst_sub_iy_hl(Machine::State& cpu) {
	op_sub16(cpu, cpu.reg.iy, cpu.reg.hl);
	return 4;
}

static int inst_ld_b_absbr(Machine::State& cpu) {
	const auto addr1 = calc_absBR(cpu);
	const uint8_t data1 = Machine::read8(cpu, addr1);
	op_ld8(cpu, cpu.reg.b, data1);
	return 3;
}

static int inst_ld_inddix_b(Machine::State& cpu) {
	const auto addr0 = calc_indDIX(cpu);
	uint8_t data0;
	op_ld8(cpu, data0, cpu.reg.b);
	Machine::write8(cpu, data0, addr0);
	return 4;
}

static int inst_sub_sp_ba(Machine::State& cpu) {
	op_sub16(cpu, cpu.reg.sp, cpu.reg.ba);
	return 4;
}

static int inst_ld_b_abshl(Machine::State& cpu) {
	const auto addr1 = calc_absHL(cpu);
	const uint8_t data1 = Machine::read8(cpu, addr1);
	op_ld8(cpu, cpu.reg.b, data1);
	return 2;
}

static int inst_ld_inddiy_b(Machine::State& cpu) {
	const auto addr0 = calc_indDIY(cpu);
	uint8_t data0;
	op_ld8(cpu, data0, cpu.reg.b);
	Machine::write8(cpu, data0, addr0);
	return 4;
}

static int inst_sub_sp_hl(Machine::State& cpu) {
	op_sub16(cpu, cpu.reg.sp, cpu.reg.hl);
	return 4;
}

static int inst_ld_b_absix(Machine::State& cpu) {
	const auto addr1 = calc_absIX(cpu);
	const uint8_t data1 = Machine::read8(cpu, addr1);
	op_ld8(cpu, cpu.reg.b, data1);
	return 2;
}

static int inst_ld_indiix_b(Machine::State& cpu) {
	const auto addr0 = calc_indIIX(cpu);
	uint8_t data0;
	op_ld8(cpu, data0, cpu.reg.b);
	Machine::write8(cpu, data0, addr0);
	return 4;
}

static int inst_ld_b_absiy(Machine::State& cpu) {
	const auto addr1 = calc_absIY(cpu);
	const uint8_t data1 = Machine::read8(cpu, addr1);
	op_ld8(cpu, cpu.reg.b, data1);
	return 2;
}

static int inst_ld_indiiy_b(Machine::State& cpu) {
	const auto addr0 = calc_indIIY(cpu);
	uint8_t data0;
	op_ld8(cpu, data0, cpu.reg.b);
	Machine::write8(cpu, data0, addr0);
	return 4;
}

static int inst_ld_l_a(Machine::State& cpu) {
	op_ld8(cpu, cpu.reg.l, cpu.reg.a);
	return 1;
}

static int inst_ld_l_inddix(Machine::State& cpu) {
	const auto addr1 = calc_indDIX(cpu);
	const uint8_t data1 = Machine::read8(cpu, addr1);
	op_ld8(cpu, cpu.reg.l, data1);
	return 4;
}

static int inst_ld_l_b(Machine::State& cpu) {
	op_ld8(cpu, cpu.reg.l, cpu.reg.b);
	return 1;
}

static int inst_ld_l_inddiy(Machine::State& cpu) {
	const auto addr1 = calc_indDIY(cpu);
	const uint8_t data1 = Machine::read8(cpu, addr1);
	op_ld8(cpu, cpu.reg.l, data1);
	return 4;
}

static int inst_ld_l_l(Machine::State& cpu) {
	op_ld8(cpu, cpu.reg.l, cpu.reg.l);
	return 1;
}

static int inst_ld_l_indiix(Machine::State& cpu) {
	const auto addr1 = calc_indIIX(cpu);
	const uint8_t data1 = Machine::read8(cpu, addr1);
	op_ld8(cpu, cpu.reg.l, data1);
	return 4;
}

static int inst_ld_l_h(Machine::State& cpu) {
	op_ld8(cpu, cpu.reg.l, cpu.reg.h);
	return 1;
}

static int inst_ld_l_indiiy(Machine::State& cpu) {
	const auto addr1 = calc_indIIY(cpu);
	const uint8_t data1 = Machine::read8(cpu, addr1);
	op_ld8(cpu, cpu.reg.l, data1);
	return 4;
}

static int inst_ld_l_absbr(Machine::State& cpu) {
	const auto addr1 = calc_absBR(cpu);
	const uint8_t data1 = Machine::read8(cpu, addr1);
	op_ld8(cpu, cpu.reg.l, data1);
	return 3;
}

static int inst_ld_inddix_l(Machine::State& cpu) {
	const auto addr0 = calc_indDIX(cpu);
	uint8_t data0;
	op_ld8(cpu, data0, cpu.reg.l);
	Machine::write8(cpu, data0, addr0);
	return 4;
}

static int inst_ld_l_abshl(Machine::State& cpu) {
	const auto addr1 = calc_absHL(cpu);
	const uint8_t data1 = Machine::read8(cpu, addr1);
	op_ld8(cpu, cpu.reg.l, data1);
	return 2;
}

static int inst_ld_inddiy_l(Machine::State& cpu) {
	const auto addr0 = calc_indDIY(cpu);
	uint8_t data0;
	op_ld8(cpu, data0, cpu.reg.l);
	Machine::write8(cpu, data0, addr0);
	return 4;
}

static int inst_ld_l_absix(Machine::State& cpu) {
	const auto addr1 = calc_absIX(cpu);
	const uint8_t data1 = Machine::read8(cpu, addr1);
	op_ld8(cpu, cpu.reg.l, data1);
	return 2;
}

static int inst_ld_indiix_l(Machine::State& cpu) {
	const auto addr0 = calc_indIIX(cpu);
	uint8_t data0;
	op_ld8(cpu, data0, cpu.reg.l);
	Machine::write8(cpu, data0, addr0);
	return 4;
}

static int inst_ld_l_absiy(Machine::State& cpu) {
	const auto addr1 = calc_absIY(cpu);
	const uint8_t data1 = Machine::read8(cpu, addr1);
	op_ld8(cpu, cpu.reg.l, data1);
	return 2;
}

static int inst_ld_indiiy_l(Machine::State& cpu) {
	const auto addr0 = calc_indIIY(cpu);
	uint8_t data0;
	op_ld8(cpu, data0, cpu.reg.l);
	Machine::write8(cpu, data0, addr0);
	return 4;
}

static int inst_ld_h_a(Machine::State& cpu) {
	op_ld8(cpu, cpu.reg.h, cpu.reg.a);
	return 1;
}

static int inst_ld_h_inddix(Machine::State& cpu) {
	const auto addr1 = calc_indDIX(cpu);
	const uint8_t data1 = Machine::read8(cpu, addr1);
	op_ld8(cpu, cpu.reg.h, data1);
	return 4;
}

static int inst_ld_h_b(Machine::State& cpu) {
	op_ld8(cpu, cpu.reg.h, cpu.reg.b);
	return 1;
}

static int inst_ld_h_inddiy(Machine::State& cpu) {
	const auto addr1 = calc_indDIY(cpu);
	const uint8_t data1 = Machine::read8(cpu, addr1);
	op_ld8(cpu, cpu.reg.h, data1);
	return 4;
}

static int inst_ld_h_l(Machine::State& cpu) {
	op_ld8(cpu, cpu.reg.h, cpu.reg.l);
	return 1;
}

static int inst_ld_h_indiix(Machine::State& cpu) {
	const auto addr1 = calc_indIIX(cpu);
	const uint8_t data1 = Machine::read8(cpu, addr1);
	op_ld8(cpu, cpu.reg.h, data1);
	return 4;
}

static int inst_ld_h_h(Machine::State& cpu) {
	op_ld8(cpu, cpu.reg.h, cpu.reg.h);
	return 1;
}

static int inst_ld_h_indiiy(Machine::State& cpu) {
	const auto addr1 = calc_indIIY(cpu);
	const uint8_t data1 = Machine::read8(cpu, addr1);
	op_ld8(cpu, cpu.reg.h, data1);
	return 4;
}

static int inst_ld_h_absbr(Machine::State& cpu) {
	const auto addr1 = calc_absBR(cpu);
	const uint8_t data1 = Machine::read8(cpu, addr1);
	op_ld8(cpu, cpu.reg.h, data1);
	return 3;
}

static int inst_ld_inddix_h(Machine::State& cpu) {
	const auto addr0 = calc_indDIX(cpu);
	uint8_t data0;
	op_ld8(cpu, data0, cpu.reg.h);
	Machine::write8(cpu, data0, addr0);
	return 4;
}

static int inst_cp_sp_ba(Machine::State& cpu) {
	op_cp16(cpu, cpu.reg.sp, cpu.reg.ba);
	return 4;
}

static int inst_ld_h_abshl(Machine::State& cpu) {
	const auto addr1 = calc_absHL(cpu);
	const uint8_t data1 = Machine::read8(cpu, addr1);
	op_ld8(cpu, cpu.reg.h, data1);
	return 2;
}

static int inst_ld_inddiy_h(Machine::State& cpu) {
	const auto addr0 = calc_indDIY(cpu);
	uint8_t data0;
	op_ld8(cpu, data0, cpu.reg.h);
	Machine::write8(cpu, data0, addr0);
	return 4;
}

static int inst_cp_sp_hl(Machine::State& cpu) {
	op_cp16(cpu, cpu.reg.sp, cpu.reg.hl);
	return 4;
}

static int inst_ld_h_absix(Machine::State& cpu) {
	const auto addr1 = calc_absIX(cpu);
	const uint8_t data1 = Machine::read8(cpu, addr1);
	op_ld8(cpu, cpu.reg.h, data1);
	return 2;
}

static int inst_ld_indiix_h(Machine::State& cpu) {
	const auto addr0 = calc_indIIX(cpu);
	uint8_t data0;
	op_ld8(cpu, data0, cpu.reg.h);
	Machine::write8(cpu, data0, addr0);
	return 4;
}

static int inst_ld_h_absiy(Machine::State& cpu) {
	const auto addr1 = calc_absIY(cpu);
	const uint8_t data1 = Machine::read8(cpu, addr1);
	op_ld8(cpu, cpu.reg.h, data1);
	return 2;
}

static int inst_ld_indiiy_h(Machine::State& cpu) {
	const auto addr0 = calc_indIIY(cpu);
	uint8_t data0;
	op_ld8(cpu, data0, cpu.reg.h);
	Machine::write8(cpu, data0, addr0);
	return 4;
}

static int inst_ld_absix_a(Machine::State& cpu) {
	const auto addr0 = calc_absIX(cpu);
	uint8_t data0;
	op_ld8(cpu, data0, cpu.reg.a);
	Machine::write8(cpu, data0, addr0);
	return 2;
}

static int inst_ld_abshl_inddix(Machine::State& cpu) {
	const auto addr0 = calc_absHL(cpu);
	uint8_t data0;
	const auto addr1 = calc_indDIX(cpu);
	const uint8_t data1 = Machine::read8(cpu, addr1);
	op_ld8(cpu, data0, data1);
	Machine::write8(cpu, data0, addr0);
	return 5;
}

static int inst_adc_ba_imm16(Machine::State& cpu) {
	const uint16_t data1 = Machine::imm16(cpu);
	op_adc16(cpu, cpu.reg.ba, data1);
	return 4;
}

static int inst_ld_absix_b(Machine::State& cpu) {
	const auto addr0 = calc_absIX(cpu);
	uint8_t data0;
	op_ld8(cpu, data0, cpu.reg.b);
	Machine::write8(cpu, data0, addr0);
	return 2;
}

static int inst_ld_abshl_inddiy(Machine::State& cpu) {
	const auto addr0 = calc_absHL(cpu);
	uint8_t data0;
	const auto addr1 = calc_indDIY(cpu);
	const uint8_t data1 = Machine::read8(cpu, addr1);
	op_ld8(cpu, data0, data1);
	Machine::write8(cpu, data0, addr0);
	return 5;
}

static int inst_adc_hl_imm16(Machine::State& cpu) {
	const uint16_t data1 = Machine::imm16(cpu);
	op_adc16(cpu, cpu.reg.hl, data1);
	return 4;
}

static int inst_ld_absix_l(Machine::State& cpu) {
	const auto addr0 = calc_absIX(cpu);
	uint8_t data0;
	op_ld8(cpu, data0, cpu.reg.l);
	Machine::write8(cpu, data0, addr0);
	return 2;
}

static int inst_ld_abshl_indiix(Machine::State& cpu) {
	const auto addr0 = calc_absHL(cpu);
	uint8_t data0;
	const auto addr1 = calc_indIIX(cpu);
	const uint8_t data1 = Machine::read8(cpu, addr1);
	op_ld8(cpu, data0, data1);
	Machine::write8(cpu, data0, addr0);
	return 5;
}

static int inst_sbc_ba_imm16(Machine::State& cpu) {
	const uint16_t data1 = Machine::imm16(cpu);
	op_sbc16(cpu, cpu.reg.ba, data1);
	return 4;
}

static int inst_ld_absix_h(Machine::State& cpu) {
	const auto addr0 = calc_absIX(cpu);
	uint8_t data0;
	op_ld8(cpu, data0, cpu.reg.h);
	Machine::write8(cpu, data0, addr0);
	return 2;
}

static int inst_ld_abshl_indiiy(Machine::State& cpu) {
	const auto addr0 = calc_absHL(cpu);
	uint8_t data0;
	const auto addr1 = calc_indIIY(cpu);
	const uint8_t data1 = Machine::read8(cpu, addr1);
	op_ld8(cpu, data0, data1);
	Machine::write8(cpu, data0, addr0);
	return 5;
}

static int inst_sbc_hl_imm16(Machine::State& cpu) {
	const uint16_t data1 = Machine::imm16(cpu);
	op_sbc16(cpu, cpu.reg.hl, data1);
	return 4;
}

static int inst_ld_absix_absbr(Machine::State& cpu) {
	const auto addr0 = calc_absIX(cpu);
	uint8_t data0;
	const auto addr1 = calc_absBR(cpu);
	const uint8_t data1 = Machine::read8(cpu, addr1);
	op_ld8(cpu, data0, data1);
	Machine::write8(cpu, data0, addr0);
	return 4;
}

static int inst_ld_absix_abshl(Machine::State& cpu) {
	const auto addr0 = calc_absIX(cpu);
	uint8_t data0;
	const auto addr1 = calc_absHL(cpu);
	const uint8_t data1 = Machine::read8(cpu, addr1);
	op_ld8(cpu, data0, data1);
	Machine::write8(cpu, data0, addr0);
	return 3;
}

static int inst_ld_absix_absix(Machine::State& cpu) {
	const auto addr0 = calc_absIX(cpu);
	uint8_t data0;
	const auto addr1 = calc_absIX(cpu);
	const uint8_t data1 = Machine::read8(cpu, addr1);
	op_ld8(cpu, data0, data1);
	Machine::write8(cpu, data0, addr0);
	return 3;
}

static int inst_ld_absix_absiy(Machine::State& cpu) {
	const auto addr0 = calc_absIX(cpu);
	uint8_t data0;
	const auto addr1 = calc_absIY(cpu);
	const uint8_t data1 = Machine::read8(cpu, addr1);
	op_ld8(cpu, data0, data1);
	Machine::write8(cpu, data0, addr0);
	return 3;
}

static int inst_ld_abshl_a(Machine::State& cpu) {
	const auto addr0 = calc_absHL(cpu);
	uint8_t data0;
	op_ld8(cpu, data0, cpu.reg.a);
	Machine::write8(cpu, data0, addr0);
	return 2;
}

static int inst_ld_absix_inddix(Machine::State& cpu) {
	const auto addr0 = calc_absIX(cpu);
	uint8_t data0;
	const auto addr1 = calc_indDIX(cpu);
	const uint8_t data1 = Machine::read8(cpu, addr1);
	op_ld8(cpu, data0, data1);
	Machine::write8(cpu, data0, addr0);
	return 5;
}

static int inst_add_sp_imm16(Machine::State& cpu) {
	const uint16_t data1 = Machine::imm16(cpu);
	op_add16(cpu, cpu.reg.sp, data1);
	return 4;
}

static int inst_ld_abshl_b(Machine::State& cpu) {
	const auto addr0 = calc_absHL(cpu);
	uint8_t data0;
	op_ld8(cpu, data0, cpu.reg.b);
	Machine::write8(cpu, data0, addr0);
	return 2;
}

static int inst_ld_absix_inddiy(Machine::State& cpu) {
	const auto addr0 = calc_absIX(cpu);
	uint8_t data0;
	const auto addr1 = calc_indDIY(cpu);
	const uint8_t data1 = Machine::read8(cpu, addr1);
	op_ld8(cpu, data0, data1);
	Machine::write8(cpu, data0, addr0);
	return 5;
}

static int inst_ld_abshl_l(Machine::State& cpu) {
	const auto addr0 = calc_absHL(cpu);
	uint8_t data0;
	op_ld8(cpu, data0, cpu.reg.l);
	Machine::write8(cpu, data0, addr0);
	return 2;
}

static int inst_ld_absix_indiix(Machine::State& cpu) {
	const auto addr0 = calc_absIX(cpu);
	uint8_t data0;
	const auto addr1 = calc_indIIX(cpu);
	const uint8_t data1 = Machine::read8(cpu, addr1);
	op_ld8(cpu, data0, data1);
	Machine::write8(cpu, data0, addr0);
	return 5;
}

static int inst_sub_sp_imm16(Machine::State& cpu) {
	const uint16_t data1 = Machine::imm16(cpu);
	op_sub16(cpu, cpu.reg.sp, data1);
	return 4;
}

static int inst_ld_abshl_h(Machine::State& cpu) {
	const auto addr0 = calc_absHL(cpu);
	uint8_t data0;
	op_ld8(cpu, data0, cpu.reg.h);
	Machine::write8(cpu, data0, addr0);
	return 2;
}

static int inst_ld_absix_indiiy(Machine::State& cpu) {
	const auto addr0 = calc_absIX(cpu);
	uint8_t data0;
	const auto addr1 = calc_indIIY(cpu);
	const uint8_t data1 = Machine::read8(cpu, addr1);
	op_ld8(cpu, data0, data1);
	Machine::write8(cpu, data0, addr0);
	return 5;
}

static int inst_ld_abshl_absbr(Machine::State& cpu) {
	const auto addr0 = calc_absHL(cpu);
	uint8_t data0;
	const auto addr1 = calc_absBR(cpu);
	const uint8_t data1 = Machine::read8(cpu, addr1);
	op_ld8(cpu, data0, data1);
	Machine::write8(cpu, data0, addr0);
	return 4;
}

static int inst_cp_sp_imm16(Machine::State& cpu) {
	const uint16_t data1 = Machine::imm16(cpu);
	op_cp16(cpu, cpu.reg.sp, data1);
	return 4;
}

static int inst_ld_abshl_abshl(Machine::State& cpu) {
	const auto addr0 = calc_absHL(cpu);
	uint8_t data0;
	const auto addr1 = calc_absHL(cpu);
	const uint8_t data1 = Machine::read8(cpu, addr1);
	op_ld8(cpu, data0, data1);
	Machine::write8(cpu, data0, addr0);
	return 3;
}

static int inst_ld_abshl_absix(Machine::State& cpu) {
	const auto addr0 = calc_absHL(cpu);
	uint8_t data0;
	const auto addr1 = calc_absIX(cpu);
	const uint8_t data1 = Machine::read8(cpu, addr1);
	op_ld8(cpu, data0, data1);
	Machine::write8(cpu, data0, addr0);
	return 3;
}

static int inst_ld_sp_imm16(Machine::State& cpu) {
	const uint16_t data1 = Machine::imm16(cpu);
	op_ld16(cpu, cpu.reg.sp, data1);
	return 4;
}

static int inst_ld_abshl_absiy(Machine::State& cpu) {
	const auto addr0 = calc_absHL(cpu);
	uint8_t data0;
	const auto addr1 = calc_absIY(cpu);
	const uint8_t data1 = Machine::read8(cpu, addr1);
	op_ld8(cpu, data0, data1);
	Machine::write8(cpu, data0, addr0);
	return 3;
}

static int inst_ld_absiy_a(Machine::State& cpu) {
	const auto addr0 = calc_absIY(cpu);
	uint8_t data0;
	op_ld8(cpu, data0, cpu.reg.a);
	Machine::write8(cpu, data0, addr0);
	return 2;
}

static int inst_ld_ba_inddsp(Machine::State& cpu) {
	const auto addr1 = calc_indDSP(cpu);
	const uint16_t data1 = Machine::read16(cpu, addr1);
	op_ld16(cpu, cpu.reg.ba, data1);
	return 6;
}

static int inst_ld_absiy_b(Machine::State& cpu) {
	const auto addr0 = calc_absIY(cpu);
	uint8_t data0;
	op_ld8(cpu, data0, cpu.reg.b);
	Machine::write8(cpu, data0, addr0);
	return 2;
}

static int inst_ld_hl_inddsp(Machine::State& cpu) {
	const auto addr1 = calc_indDSP(cpu);
	const uint16_t data1 = Machine::read16(cpu, addr1);
	op_ld16(cpu, cpu.reg.hl, data1);
	return 6;
}

static int inst_ld_absiy_l(Machine::State& cpu) {
	const auto addr0 = calc_absIY(cpu);
	uint8_t data0;
	op_ld8(cpu, data0, cpu.reg.l);
	Machine::write8(cpu, data0, addr0);
	return 2;
}

static int inst_ld_ix_inddsp(Machine::State& cpu) {
	const auto addr1 = calc_indDSP(cpu);
	const uint16_t data1 = Machine::read16(cpu, addr1);
	op_ld16(cpu, cpu.reg.ix, data1);
	return 6;
}

static int inst_ld_absiy_h(Machine::State& cpu) {
	const auto addr0 = calc_absIY(cpu);
	uint8_t data0;
	op_ld8(cpu, data0, cpu.reg.h);
	Machine::write8(cpu, data0, addr0);
	return 2;
}

static int inst_ld_iy_inddsp(Machine::State& cpu) {
	const auto addr1 = calc_indDSP(cpu);
	const uint16_t data1 = Machine::read16(cpu, addr1);
	op_ld16(cpu, cpu.reg.iy, data1);
	return 6;
}

static int inst_ld_absiy_absbr(Machine::State& cpu) {
	const auto addr0 = calc_absIY(cpu);
	uint8_t data0;
	const auto addr1 = calc_absBR(cpu);
	const uint8_t data1 = Machine::read8(cpu, addr1);
	op_ld8(cpu, data0, data1);
	Machine::write8(cpu, data0, addr0);
	return 4;
}

static int inst_ld_inddsp_ba(Machine::State& cpu) {
	const auto addr0 = calc_indDSP(cpu);
	uint16_t data0;
	op_ld16(cpu, data0, cpu.reg.ba);
	Machine::write16(cpu, data0, addr0);
	return 6;
}

static int inst_ld_absiy_abshl(Machine::State& cpu) {
	const auto addr0 = calc_absIY(cpu);
	uint8_t data0;
	const auto addr1 = calc_absHL(cpu);
	const uint8_t data1 = Machine::read8(cpu, addr1);
	op_ld8(cpu, data0, data1);
	Machine::write8(cpu, data0, addr0);
	return 3;
}

static int inst_ld_inddsp_hl(Machine::State& cpu) {
	const auto addr0 = calc_indDSP(cpu);
	uint16_t data0;
	op_ld16(cpu, data0, cpu.reg.hl);
	Machine::write16(cpu, data0, addr0);
	return 6;
}

static int inst_ld_absiy_absix(Machine::State& cpu) {
	const auto addr0 = calc_absIY(cpu);
	uint8_t data0;
	const auto addr1 = calc_absIX(cpu);
	const uint8_t data1 = Machine::read8(cpu, addr1);
	op_ld8(cpu, data0, data1);
	Machine::write8(cpu, data0, addr0);
	return 3;
}

static int inst_ld_inddsp_ix(Machine::State& cpu) {
	const auto addr0 = calc_indDSP(cpu);
	uint16_t data0;
	op_ld16(cpu, data0, cpu.reg.ix);
	Machine::write16(cpu, data0, addr0);
	return 6;
}

static int inst_ld_absiy_absiy(Machine::State& cpu) {
	const auto addr0 = calc_absIY(cpu);
	uint8_t data0;
	const auto addr1 = calc_absIY(cpu);
	const uint8_t data1 = Machine::read8(cpu, addr1);
	op_ld8(cpu, data0, data1);
	Machine::write8(cpu, data0, addr0);
	return 3;
}

static int inst_ld_inddsp_iy(Machine::State& cpu) {
	const auto addr0 = calc_indDSP(cpu);
	uint16_t data0;
	op_ld16(cpu, data0, cpu.reg.iy);
	Machine::write16(cpu, data0, addr0);
	return 6;
}

static int inst_ld_absbr_a(Machine::State& cpu) {
	const auto addr0 = calc_absBR(cpu);
	uint8_t data0;
	op_ld8(cpu, data0, cpu.reg.a);
	Machine::write8(cpu, data0, addr0);
	return 3;
}

static int inst_ld_absiy_inddix(Machine::State& cpu) {
	const auto addr0 = calc_absIY(cpu);
	uint8_t data0;
	const auto addr1 = calc_indDIX(cpu);
	const uint8_t data1 = Machine::read8(cpu, addr1);
	op_ld8(cpu, data0, data1);
	Machine::write8(cpu, data0, addr0);
	return 5;
}

static int inst_ld_sp_ind16(Machine::State& cpu) {
	const auto addr1 = calc_ind16(cpu);
	const uint16_t data1 = Machine::read16(cpu, addr1);
	op_ld16(cpu, cpu.reg.sp, data1);
	return 6;
}

static int inst_ld_absbr_b(Machine::State& cpu) {
	const auto addr0 = calc_absBR(cpu);
	uint8_t data0;
	op_ld8(cpu, data0, cpu.reg.b);
	Machine::write8(cpu, data0, addr0);
	return 3;
}

static int inst_ld_absiy_inddiy(Machine::State& cpu) {
	const auto addr0 = calc_absIY(cpu);
	uint8_t data0;
	const auto addr1 = calc_indDIY(cpu);
	const uint8_t data1 = Machine::read8(cpu, addr1);
	op_ld8(cpu, data0, data1);
	Machine::write8(cpu, data0, addr0);
	return 5;
}

static int inst_ld_absbr_l(Machine::State& cpu) {
	const auto addr0 = calc_absBR(cpu);
	uint8_t data0;
	op_ld8(cpu, data0, cpu.reg.l);
	Machine::write8(cpu, data0, addr0);
	return 3;
}

static int inst_ld_absiy_indiix(Machine::State& cpu) {
	const auto addr0 = calc_absIY(cpu);
	uint8_t data0;
	const auto addr1 = calc_indIIX(cpu);
	const uint8_t data1 = Machine::read8(cpu, addr1);
	op_ld8(cpu, data0, data1);
	Machine::write8(cpu, data0, addr0);
	return 5;
}

static int inst_ld_absbr_h(Machine::State& cpu) {
	const auto addr0 = calc_absBR(cpu);
	uint8_t data0;
	op_ld8(cpu, data0, cpu.reg.h);
	Machine::write8(cpu, data0, addr0);
	return 3;
}

static int inst_ld_absiy_indiiy(Machine::State& cpu) {
	const auto addr0 = calc_absIY(cpu);
	uint8_t data0;
	const auto addr1 = calc_indIIY(cpu);
	const uint8_t data1 = Machine::read8(cpu, addr1);
	op_ld8(cpu, data0, data1);
	Machine::write8(cpu, data0, addr0);
	return 5;
}

static int inst_ld_ind16_sp(Machine::State& cpu) {
	const auto addr0 = calc_ind16(cpu);
	uint16_t data0;
	op_ld16(cpu, data0, cpu.reg.sp);
	Machine::write16(cpu, data0, addr0);
	return 6;
}

static int inst_ld_absbr_abshl(Machine::State& cpu) {
	const auto addr0 = calc_absBR(cpu);
	uint8_t data0;
	const auto addr1 = calc_absHL(cpu);
	const uint8_t data1 = Machine::read8(cpu, addr1);
	op_ld8(cpu, data0, data1);
	Machine::write8(cpu, data0, addr0);
	return 4;
}

static int inst_ld_absbr_absix(Machine::State& cpu) {
	const auto addr0 = calc_absBR(cpu);
	uint8_t data0;
	const auto addr1 = calc_absIX(cpu);
	const uint8_t data1 = Machine::read8(cpu, addr1);
	op_ld8(cpu, data0, data1);
	Machine::write8(cpu, data0, addr0);
	return 4;
}

static int inst_ld_absbr_absiy(Machine::State& cpu) {
	const auto addr0 = calc_absBR(cpu);
	uint8_t data0;
	const auto addr1 = calc_absIY(cpu);
	const uint8_t data1 = Machine::read8(cpu, addr1);
	op_ld8(cpu, data0, data1);
	Machine::write8(cpu, data0, addr0);
	return 4;
}

static int inst_inc_a(Machine::State& cpu) {
	op_inc8(cpu, cpu.reg.a);
	return 2;
}

static int inst_sla_a(Machine::State& cpu) {
	op_sla8(cpu, cpu.reg.a);
	return 3;
}

static int inst_inc_b(Machine::State& cpu) {
	op_inc8(cpu, cpu.reg.b);
	return 2;
}

static int inst_sla_b(Machine::State& cpu) {
	op_sla8(cpu, cpu.reg.b);
	return 3;
}

static int inst_inc_l(Machine::State& cpu) {
	op_inc8(cpu, cpu.reg.l);
	return 2;
}

static int inst_sla_absbr(Machine::State& cpu) {
	const auto addr0 = calc_absBR(cpu);
	uint8_t data0 = Machine::read8(cpu, addr0);
	op_sla8(cpu, data0);
	Machine::write8(cpu, data0, addr0);
	return 5;
}

static int inst_inc_h(Machine::State& cpu) {
	op_inc8(cpu, cpu.reg.h);
	return 2;
}

static int inst_sla_abshl(Machine::State& cpu) {
	const auto addr0 = calc_absHL(cpu);
	uint8_t data0 = Machine::read8(cpu, addr0);
	op_sla8(cpu, data0);
	Machine::write8(cpu, data0, addr0);
	return 4;
}

static int inst_inc_br(Machine::State& cpu) {
	op_inc8(cpu, cpu.reg.br);
	return 2;
}

static int inst_sll_a(Machine::State& cpu) {
	op_sll8(cpu, cpu.reg.a);
	return 3;
}

static int inst_inc_absbr(Machine::State& cpu) {
	const auto addr0 = calc_absBR(cpu);
	uint8_t data0 = Machine::read8(cpu, addr0);
	op_inc8(cpu, data0);
	Machine::write8(cpu, data0, addr0);
	return 4;
}

static int inst_sll_b(Machine::State& cpu) {
	op_sll8(cpu, cpu.reg.b);
	return 3;
}

static int inst_inc_abshl(Machine::State& cpu) {
	const auto addr0 = calc_absHL(cpu);
	uint8_t data0 = Machine::read8(cpu, addr0);
	op_inc8(cpu, data0);
	Machine::write8(cpu, data0, addr0);
	return 3;
}

static int inst_sll_absbr(Machine::State& cpu) {
	const auto addr0 = calc_absBR(cpu);
	uint8_t data0 = Machine::read8(cpu, addr0);
	op_sll8(cpu, data0);
	Machine::write8(cpu, data0, addr0);
	return 5;
}

static int inst_inc_sp(Machine::State& cpu) {
	op_inc16(cpu, cpu.reg.sp);
	return 2;
}

static int inst_sll_abshl(Machine::State& cpu) {
	const auto addr0 = calc_absHL(cpu);
	uint8_t data0 = Machine::read8(cpu, addr0);
	op_sll8(cpu, data0);
	Machine::write8(cpu, data0, addr0);
	return 4;
}

static int inst_dec_a(Machine::State& cpu) {
	op_dec8(cpu, cpu.reg.a);
	return 2;
}

static int inst_sra_a(Machine::State& cpu) {
	op_sra8(cpu, cpu.reg.a);
	return 3;
}

static int inst_dec_b(Machine::State& cpu) {
	op_dec8(cpu, cpu.reg.b);
	return 2;
}

static int inst_sra_b(Machine::State& cpu) {
	op_sra8(cpu, cpu.reg.b);
	return 3;
}

static int inst_dec_l(Machine::State& cpu) {
	op_dec8(cpu, cpu.reg.l);
	return 2;
}

static int inst_sra_absbr(Machine::State& cpu) {
	const auto addr0 = calc_absBR(cpu);
	uint8_t data0 = Machine::read8(cpu, addr0);
	op_sra8(cpu, data0);
	Machine::write8(cpu, data0, addr0);
	return 5;
}

static int inst_dec_h(Machine::State& cpu) {
	op_dec8(cpu, cpu.reg.h);
	return 2;
}

static int inst_sra_abshl(Machine::State& cpu) {
	const auto addr0 = calc_absHL(cpu);
	uint8_t data0 = Machine::read8(cpu, addr0);
	op_sra8(cpu, data0);
	Machine::write8(cpu, data0, addr0);
	return 4;
}

static int inst_dec_br(Machine::State& cpu) {
	op_dec8(cpu, cpu.reg.br);
	return 2;
}

static int inst_srl_a(Machine::State& cpu) {
	op_srl8(cpu, cpu.reg.a);
	return 3;
}

static int inst_dec_absbr(Machine::State& cpu) {
	const auto addr0 = calc_absBR(cpu);
	uint8_t data0 = Machine::read8(cpu, addr0);
	op_dec8(cpu, data0);
	Machine::write8(cpu, data0, addr0);
	return 4;
}

static int inst_srl_b(Machine::State& cpu) {
	op_srl8(cpu, cpu.reg.b);
	return 3;
}

static int inst_dec_abshl(Machine::State& cpu) {
	const auto addr0 = calc_absHL(cpu);
	uint8_t data0 = Machine::read8(cpu, addr0);
	op_dec8(cpu, data0);
	Machine::write8(cpu, data0, addr0);
	return 3;
}

static int inst_srl_absbr(Machine::State& cpu) {
	const auto addr0 = calc_absBR(cpu);
	uint8_t data0 = Machine::read8(cpu, addr0);
	op_srl8(cpu, data0);
	Machine::write8(cpu, data0, addr0);
	return 5;
}

static int inst_dec_sp(Machine::State& cpu) {
	op_dec16(cpu, cpu.reg.sp);
	return 2;
}

static int inst_srl_abshl(Machine::State& cpu) {
	const auto addr0 = calc_absHL(cpu);
	uint8_t data0 = Machine::read8(cpu, addr0);
	op_srl8(cpu, data0);
	Machine::write8(cpu, data0, addr0);
	return 4;
}

static int inst_inc_ba(Machine::State& cpu) {
	op_inc16(cpu, cpu.reg.ba);
	return 2;
}

static int inst_rl_a(Machine::State& cpu) {
	op_rl8(cpu, cpu.reg.a);
	return 3;
}

static int inst_inc_hl(Machine::State& cpu) {
	op_inc16(cpu, cpu.reg.hl);
	return 2;
}

static int inst_rl_b(Machine::State& cpu) {
	op_rl8(cpu, cpu.reg.b);
	return 3;
}

static int inst_inc_ix(Machine::State& cpu) {
	op_inc16(cpu, cpu.reg.ix);
	return 2;
}

static int inst_rl_absbr(Machine::State& cpu) {
	const auto addr0 = calc_absBR(cpu);
	uint8_t data0 = Machine::read8(cpu, addr0);
	op_rl8(cpu, data0);
	Machine::write8(cpu, data0, addr0);
	return 5;
}

static int inst_inc_iy(Machine::State& cpu) {
	op_inc16(cpu, cpu.reg.iy);
	return 2;
}

static int inst_rl_abshl(Machine::State& cpu) {
	const auto addr0 = calc_absHL(cpu);
	uint8_t data0 = Machine::read8(cpu, addr0);
	op_rl8(cpu, data0);
	Machine::write8(cpu, data0, addr0);
	return 4;
}

static int inst_bit_a_b(Machine::State& cpu) {
	op_bit8(cpu, cpu.reg.a, cpu.reg.b);
	return 2;
}

static int inst_rlc_a(Machine::State& cpu) {
	op_rlc8(cpu, cpu.reg.a);
	return 3;
}

static int inst_bit_abshl_imm8(Machine::State& cpu) {
	const auto addr0 = calc_absHL(cpu);
	const uint8_t data0 = Machine::read8(cpu, addr0);
	const uint8_t data1 = Machine::imm8(cpu);
	op_bit8(cpu, data0, data1);
	return 3;
}

static int inst_rlc_b(Machine::State& cpu) {
	op_rlc8(cpu, cpu.reg.b);
	return 3;
}

static int inst_bit_a_imm8(Machine::State& cpu) {
	const uint8_t data1 = Machine::imm8(cpu);
	op_bit8(cpu, cpu.reg.a, data1);
	return 2;
}

static int inst_rlc_absbr(Machine::State& cpu) {
	const auto addr0 = calc_absBR(cpu);
	uint8_t data0 = Machine::read8(cpu, addr0);
	op_rlc8(cpu, data0);
	Machine::write8(cpu, data0, addr0);
	return 5;
}

static int inst_bit_b_imm8(Machine::State& cpu) {
	const uint8_t data1 = Machine::imm8(cpu);
	op_bit8(cpu, cpu.reg.b, data1);
	return 2;
}

static int inst_rlc_abshl(Machine::State& cpu) {
	const auto addr0 = calc_absHL(cpu);
	uint8_t data0 = Machine::read8(cpu, addr0);
	op_rlc8(cpu, data0);
	Machine::write8(cpu, data0, addr0);
	return 4;
}

static int inst_dec_ba(Machine::State& cpu) {
	op_dec16(cpu, cpu.reg.ba);
	return 2;
}

static int inst_rr_a(Machine::State& cpu) {
	op_rr8(cpu, cpu.reg.a);
	return 3;
}

static int inst_dec_hl(Machine::State& cpu) {
	op_dec16(cpu, cpu.reg.hl);
	return 2;
}

static int inst_rr_b(Machine::State& cpu) {
	op_rr8(cpu, cpu.reg.b);
	return 3;
}

static int inst_dec_ix(Machine::State& cpu) {
	op_dec16(cpu, cpu.reg.ix);
	return 2;
}

static int inst_rr_absbr(Machine::State& cpu) {
	const auto addr0 = calc_absBR(cpu);
	uint8_t data0 = Machine::read8(cpu, addr0);
	op_rr8(cpu, data0);
	Machine::write8(cpu, data0, addr0);
	return 5;
}

static int inst_dec_iy(Machine::State& cpu) {
	op_dec16(cpu, cpu.reg.iy);
	return 2;
}

static int inst_rr_abshl(Machine::State& cpu) {
	const auto addr0 = calc_absHL(cpu);
	uint8_t data0 = Machine::read8(cpu, addr0);
	op_rr8(cpu, data0);
	Machine::write8(cpu, data0, addr0);
	return 4;
}

static int inst_and_sc_imm8(Machine::State& cpu) {
	const uint8_t data1 = Machine::imm8(cpu);
	op_and8(cpu, cpu.reg.sc, data1);
	return 3 + inst_advance(cpu); // Block IRQs
}

static int inst_rrc_a(Machine::State& cpu) {
	op_rrc8(cpu, cpu.reg.a);
	return 3;
}

static int inst_or_sc_imm8(Machine::State& cpu) {
	const uint8_t data1 = Machine::imm8(cpu);
	op_or8(cpu, cpu.reg.sc, data1);
	return 3 + inst_advance(cpu); // Block IRQs
}

static int inst_rrc_b(Machine::State& cpu) {
	op_rrc8(cpu, cpu.reg.b);
	return 3;
}

static int inst_xor_sc_imm8(Machine::State& cpu) {
	const uint8_t data1 = Machine::imm8(cpu);
	op_xor8(cpu, cpu.reg.sc, data1);
	return 3 + inst_advance(cpu); // Block IRQs
}

static int inst_rrc_absbr(Machine::State& cpu) {
	const auto addr0 = calc_absBR(cpu);
	uint8_t data0 = Machine::read8(cpu, addr0);
	op_rrc8(cpu, data0);
	Machine::write8(cpu, data0, addr0);
	return 5;
}

static int inst_ld_sc_imm8(Machine::State& cpu) {
	const uint8_t data1 = Machine::imm8(cpu);
	op_ld8(cpu, cpu.reg.sc, data1);
	return 3 + inst_advance(cpu); // Block IRQs
}

static int inst_rrc_abshl(Machine::State& cpu) {
	const auto addr0 = calc_absHL(cpu);
	uint8_t data0 = Machine::read8(cpu, addr0);
	op_rrc8(cpu, data0);
	Machine::write8(cpu, data0, addr0);
	return 4;
}

static int inst_push_ba(Machine::State& cpu) {
	op_push16(cpu, cpu.reg.ba);
	return 4;
}

static int inst_cpl_a(Machine::State& cpu) {
	op_cpl8(cpu, cpu.reg.a);
	return 3;
}

static int inst_push_hl(Machine::State& cpu) {
	op_push16(cpu, cpu.reg.hl);
	return 4;
}

static int inst_cpl_b(Machine::State& cpu) {
	op_cpl8(cpu, cpu.reg.b);
	return 3;
}

static int inst_push_ix(Machine::State& cpu) {
	op_push16(cpu, cpu.reg.ix);
	return 4;
}

static int inst_cpl_absbr(Machine::State& cpu) {
	const auto addr0 = calc_absBR(cpu);
	uint8_t data0 = Machine::read8(cpu, addr0);
	op_cpl8(cpu, data0);
	Machine::write8(cpu, data0, addr0);
	return 5;
}

static int inst_push_iy(Machine::State& cpu) {
	op_push16(cpu, cpu.reg.iy);
	return 4;
}

static int inst_cpl_abshl(Machine::State& cpu) {
	const auto addr0 = calc_absHL(cpu);
	uint8_t data0 = Machine::read8(cpu, addr0);
	op_cpl8(cpu, data0);
	Machine::write8(cpu, data0, addr0);
	return 4;
}

static int inst_push_br(Machine::State& cpu) {
	op_push8(cpu, cpu.reg.br);
	return 3;
}

static int inst_neg_a(Machine::State& cpu) {
	op_neg8(cpu, cpu.reg.a);
	return 3;
}

static int inst_push_ep(Machine::State& cpu) {
	op_push8(cpu, cpu.reg.ep);
	return 3;
}

static int inst_neg_b(Machine::State& cpu) {
	op_neg8(cpu, cpu.reg.b);
	return 3;
}

int clock_inst_push_ip(Machine::State& cpu) {
	inst_push_ip(cpu);
	return 4;
}

static int inst_neg_absbr(Machine::State& cpu) {
	const auto addr0 = calc_absBR(cpu);
	uint8_t data0 = Machine::read8(cpu, addr0);
	op_neg8(cpu, data0);
	Machine::write8(cpu, data0, addr0);
	return 5;
}

static int inst_push_sc(Machine::State& cpu) {
	op_push8(cpu, cpu.reg.sc);
	return 3;
}

static int inst_neg_abshl(Machine::State& cpu) {
	const auto addr0 = calc_absHL(cpu);
	uint8_t data0 = Machine::read8(cpu, addr0);
	op_neg8(cpu, data0);
	Machine::write8(cpu, data0, addr0);
	return 4;
}

static int inst_pop_ba(Machine::State& cpu) {
	op_pop16(cpu, cpu.reg.ba);
	return 3;
}

int clock_inst_sep(Machine::State& cpu) {
	inst_sep(cpu);
	return 3;
}

static int inst_pop_hl(Machine::State& cpu) {
	op_pop16(cpu, cpu.reg.hl);
	return 3;
}

static int inst_pop_ix(Machine::State& cpu) {
	op_pop16(cpu, cpu.reg.ix);
	return 3;
}

static int inst_pop_iy(Machine::State& cpu) {
	op_pop16(cpu, cpu.reg.iy);
	return 3;
}

static int inst_pop_br(Machine::State& cpu) {
	op_pop8(cpu, cpu.reg.br);
	return 2;
}

static int inst_pop_ep(Machine::State& cpu) {
	op_pop8(cpu, cpu.reg.ep);
	return 2;
}

int clock_inst_pop_ip(Machine::State& cpu) {
	inst_pop_ip(cpu);
	return 3;
}

int clock_inst_halt(Machine::State& cpu) {
	inst_halt(cpu);
	return 3;
}

static int inst_pop_sc(Machine::State& cpu) {
	op_pop8(cpu, cpu.reg.sc);
	return 2 + inst_advance(cpu); // Block IRQs
}

int clock_inst_slp(Machine::State& cpu) {
	inst_slp(cpu);
	return 3;
}

static int inst_ld_a_imm8(Machine::State& cpu) {
	const uint8_t data1 = Machine::imm8(cpu);
	op_ld8(cpu, cpu.reg.a, data1);
	return 2;
}

static int inst_and_b_imm8(Machine::State& cpu) {
	const uint8_t data1 = Machine::imm8(cpu);
	op_and8(cpu, cpu.reg.b, data1);
	return 3;
}

static int inst_push_a(Machine::State& cpu) {
	op_push8(cpu, cpu.reg.a);
	return 3;
}

static int inst_ld_b_imm8(Machine::State& cpu) {
	const uint8_t data1 = Machine::imm8(cpu);
	op_ld8(cpu, cpu.reg.b, data1);
	return 2;
}

static int inst_and_l_imm8(Machine::State& cpu) {
	const uint8_t data1 = Machine::imm8(cpu);
	op_and8(cpu, cpu.reg.l, data1);
	return 3;
}

static int inst_push_b(Machine::State& cpu) {
	op_push8(cpu, cpu.reg.b);
	return 3;
}

static int inst_ld_l_imm8(Machine::State& cpu) {
	const uint8_t data1 = Machine::imm8(cpu);
	op_ld8(cpu, cpu.reg.l, data1);
	return 2;
}

static int inst_and_h_imm8(Machine::State& cpu) {
	const uint8_t data1 = Machine::imm8(cpu);
	op_and8(cpu, cpu.reg.h, data1);
	return 3;
}

static int inst_push_l(Machine::State& cpu) {
	op_push8(cpu, cpu.reg.l);
	return 3;
}

static int inst_ld_h_imm8(Machine::State& cpu) {
	const uint8_t data1 = Machine::imm8(cpu);
	op_ld8(cpu, cpu.reg.h, data1);
	return 2;
}

static int inst_push_h(Machine::State& cpu) {
	op_push8(cpu, cpu.reg.h);
	return 3;
}

static int inst_ld_br_imm8(Machine::State& cpu) {
	const uint8_t data1 = Machine::imm8(cpu);
	op_ld8(cpu, cpu.reg.br, data1);
	return 2;
}

static int inst_or_b_imm8(Machine::State& cpu) {
	const uint8_t data1 = Machine::imm8(cpu);
	op_or8(cpu, cpu.reg.b, data1);
	return 3;
}

static int inst_pop_a(Machine::State& cpu) {
	op_pop8(cpu, cpu.reg.a);
	return 3;
}

static int inst_ld_abshl_imm8(Machine::State& cpu) {
	const auto addr0 = calc_absHL(cpu);
	uint8_t data0;
	const uint8_t data1 = Machine::imm8(cpu);
	op_ld8(cpu, data0, data1);
	Machine::write8(cpu, data0, addr0);
	return 3;
}

static int inst_or_l_imm8(Machine::State& cpu) {
	const uint8_t data1 = Machine::imm8(cpu);
	op_or8(cpu, cpu.reg.l, data1);
	return 3;
}

static int inst_pop_b(Machine::State& cpu) {
	op_pop8(cpu, cpu.reg.b);
	return 3;
}

static int inst_ld_absix_imm8(Machine::State& cpu) {
	const auto addr0 = calc_absIX(cpu);
	uint8_t data0;
	const uint8_t data1 = Machine::imm8(cpu);
	op_ld8(cpu, data0, data1);
	Machine::write8(cpu, data0, addr0);
	return 3;
}

static int inst_or_h_imm8(Machine::State& cpu) {
	const uint8_t data1 = Machine::imm8(cpu);
	op_or8(cpu, cpu.reg.h, data1);
	return 3;
}

static int inst_pop_l(Machine::State& cpu) {
	op_pop8(cpu, cpu.reg.l);
	return 3;
}

static int inst_ld_absiy_imm8(Machine::State& cpu) {
	const auto addr0 = calc_absIY(cpu);
	uint8_t data0;
	const uint8_t data1 = Machine::imm8(cpu);
	op_ld8(cpu, data0, data1);
	Machine::write8(cpu, data0, addr0);
	return 3;
}

static int inst_pop_h(Machine::State& cpu) {
	op_pop8(cpu, cpu.reg.h);
	return 3;
}

static int inst_ld_ba_ind16(Machine::State& cpu) {
	const auto addr1 = calc_ind16(cpu);
	const uint16_t data1 = Machine::read16(cpu, addr1);
	op_ld16(cpu, cpu.reg.ba, data1);
	return 5;
}

static int inst_xor_b_imm8(Machine::State& cpu) {
	const uint8_t data1 = Machine::imm8(cpu);
	op_xor8(cpu, cpu.reg.b, data1);
	return 3;
}

int clock_inst_push_all(Machine::State& cpu) {
	inst_push_all(cpu);
	return 12;
}

static int inst_ld_hl_ind16(Machine::State& cpu) {
	const auto addr1 = calc_ind16(cpu);
	const uint16_t data1 = Machine::read16(cpu, addr1);
	op_ld16(cpu, cpu.reg.hl, data1);
	return 5;
}

static int inst_xor_l_imm8(Machine::State& cpu) {
	const uint8_t data1 = Machine::imm8(cpu);
	op_xor8(cpu, cpu.reg.l, data1);
	return 3;
}

int clock_inst_push_ale(Machine::State& cpu) {
	inst_push_ale(cpu);
	return 15;
}

static int inst_ld_ix_ind16(Machine::State& cpu) {
	const auto addr1 = calc_ind16(cpu);
	const uint16_t data1 = Machine::read16(cpu, addr1);
	op_ld16(cpu, cpu.reg.ix, data1);
	return 5;
}

static int inst_xor_h_imm8(Machine::State& cpu) {
	const uint8_t data1 = Machine::imm8(cpu);
	op_xor8(cpu, cpu.reg.h, data1);
	return 3;
}

static int inst_ld_iy_ind16(Machine::State& cpu) {
	const auto addr1 = calc_ind16(cpu);
	const uint16_t data1 = Machine::read16(cpu, addr1);
	op_ld16(cpu, cpu.reg.iy, data1);
	return 5;
}

static int inst_ld_ind16_ba(Machine::State& cpu) {
	const auto addr0 = calc_ind16(cpu);
	uint16_t data0;
	op_ld16(cpu, data0, cpu.reg.ba);
	Machine::write16(cpu, data0, addr0);
	return 5;
}

static int inst_cp_b_imm8(Machine::State& cpu) {
	const uint8_t data1 = Machine::imm8(cpu);
	op_cp8(cpu, cpu.reg.b, data1);
	return 3;
}

int clock_inst_pop_all(Machine::State& cpu) {
	inst_pop_all(cpu);
	return 11;
}

static int inst_ld_ind16_hl(Machine::State& cpu) {
	const auto addr0 = calc_ind16(cpu);
	uint16_t data0;
	op_ld16(cpu, data0, cpu.reg.hl);
	Machine::write16(cpu, data0, addr0);
	return 5;
}

static int inst_cp_l_imm8(Machine::State& cpu) {
	const uint8_t data1 = Machine::imm8(cpu);
	op_cp8(cpu, cpu.reg.l, data1);
	return 3;
}

int clock_inst_pop_ale(Machine::State& cpu) {
	inst_pop_ale(cpu);
	return 14;
}

static int inst_ld_ind16_ix(Machine::State& cpu) {
	const auto addr0 = calc_ind16(cpu);
	uint16_t data0;
	op_ld16(cpu, data0, cpu.reg.ix);
	Machine::write16(cpu, data0, addr0);
	return 5;
}

static int inst_cp_h_imm8(Machine::State& cpu) {
	const uint8_t data1 = Machine::imm8(cpu);
	op_cp8(cpu, cpu.reg.h, data1);
	return 3;
}

static int inst_ld_ind16_iy(Machine::State& cpu) {
	const auto addr0 = calc_ind16(cpu);
	uint16_t data0;
	op_ld16(cpu, data0, cpu.reg.iy);
	Machine::write16(cpu, data0, addr0);
	return 5;
}

static int inst_cp_br_imm8(Machine::State& cpu) {
	const uint8_t data1 = Machine::imm8(cpu);
	op_cp8(cpu, cpu.reg.br, data1);
	return 3;
}

static int inst_add_ba_imm16(Machine::State& cpu) {
	const uint16_t data1 = Machine::imm16(cpu);
	op_add16(cpu, cpu.reg.ba, data1);
	return 3;
}

static int inst_ld_a_br(Machine::State& cpu) {
	op_ld8(cpu, cpu.reg.a, cpu.reg.br);
	return 2;
}

static int inst_ld_ba_abshl(Machine::State& cpu) {
	const auto addr1 = calc_absHL(cpu);
	const uint16_t data1 = Machine::read16(cpu, addr1);
	op_ld16(cpu, cpu.reg.ba, data1);
	return 5;
}

static int inst_add_hl_imm16(Machine::State& cpu) {
	const uint16_t data1 = Machine::imm16(cpu);
	op_add16(cpu, cpu.reg.hl, data1);
	return 3;
}

static int inst_ld_a_sc(Machine::State& cpu) {
	op_ld8(cpu, cpu.reg.a, cpu.reg.sc);
	return 2;
}

static int inst_ld_hl_abshl(Machine::State& cpu) {
	const auto addr1 = calc_absHL(cpu);
	const uint16_t data1 = Machine::read16(cpu, addr1);
	op_ld16(cpu, cpu.reg.hl, data1);
	return 5;
}

static int inst_add_ix_imm16(Machine::State& cpu) {
	const uint16_t data1 = Machine::imm16(cpu);
	op_add16(cpu, cpu.reg.ix, data1);
	return 3;
}

static int inst_ld_br_a(Machine::State& cpu) {
	op_ld8(cpu, cpu.reg.br, cpu.reg.a);
	return 2;
}

static int inst_ld_ix_abshl(Machine::State& cpu) {
	const auto addr1 = calc_absHL(cpu);
	const uint16_t data1 = Machine::read16(cpu, addr1);
	op_ld16(cpu, cpu.reg.ix, data1);
	return 5;
}

static int inst_add_iy_imm16(Machine::State& cpu) {
	const uint16_t data1 = Machine::imm16(cpu);
	op_add16(cpu, cpu.reg.iy, data1);
	return 3;
}

static int inst_ld_sc_a(Machine::State& cpu) {
	op_ld8(cpu, cpu.reg.sc, cpu.reg.a);
	return 2 + inst_advance(cpu); // Block IRQs
}

static int inst_ld_iy_abshl(Machine::State& cpu) {
	const auto addr1 = calc_absHL(cpu);
	const uint16_t data1 = Machine::read16(cpu, addr1);
	op_ld16(cpu, cpu.reg.iy, data1);
	return 5;
}

static int inst_ld_ba_imm16(Machine::State& cpu) {
	const uint16_t data1 = Machine::imm16(cpu);
	op_ld16(cpu, cpu.reg.ba, data1);
	return 3;
}

static int inst_ld_nb_imm8(Machine::State& cpu) {
	const uint8_t data1 = Machine::imm8(cpu);
	op_ld8(cpu, cpu.reg.nb, data1);
	return 4 + inst_advance(cpu); // Block IRQs
}

static int inst_ld_abshl_ba(Machine::State& cpu) {
	const auto addr0 = calc_absHL(cpu);
	uint16_t data0;
	op_ld16(cpu, data0, cpu.reg.ba);
	Machine::write16(cpu, data0, addr0);
	return 5;
}

static int inst_ld_hl_imm16(Machine::State& cpu) {
	const uint16_t data1 = Machine::imm16(cpu);
	op_ld16(cpu, cpu.reg.hl, data1);
	return 3;
}

static int inst_ld_ep_imm8(Machine::State& cpu) {
	const uint8_t data1 = Machine::imm8(cpu);
	op_ld8(cpu, cpu.reg.ep, data1);
	return 3;
}

static int inst_ld_abshl_hl(Machine::State& cpu) {
	const auto addr0 = calc_absHL(cpu);
	uint16_t data0;
	op_ld16(cpu, data0, cpu.reg.hl);
	Machine::write16(cpu, data0, addr0);
	return 5;
}

static int inst_ld_ix_imm16(Machine::State& cpu) {
	const uint16_t data1 = Machine::imm16(cpu);
	op_ld16(cpu, cpu.reg.ix, data1);
	return 3;
}

static int inst_ld_xp_imm8(Machine::State& cpu) {
	const uint8_t data1 = Machine::imm8(cpu);
	op_ld8(cpu, cpu.reg.xp, data1);
	return 3;
}

static int inst_ld_abshl_ix(Machine::State& cpu) {
	const auto addr0 = calc_absHL(cpu);
	uint16_t data0;
	op_ld16(cpu, data0, cpu.reg.ix);
	Machine::write16(cpu, data0, addr0);
	return 5;
}

static int inst_ld_iy_imm16(Machine::State& cpu) {
	const uint16_t data1 = Machine::imm16(cpu);
	op_ld16(cpu, cpu.reg.iy, data1);
	return 3;
}

static int inst_ld_yp_imm8(Machine::State& cpu) {
	const uint8_t data1 = Machine::imm8(cpu);
	op_ld8(cpu, cpu.reg.yp, data1);
	return 3;
}

static int inst_ld_abshl_iy(Machine::State& cpu) {
	const auto addr0 = calc_absHL(cpu);
	uint16_t data0;
	op_ld16(cpu, data0, cpu.reg.iy);
	Machine::write16(cpu, data0, addr0);
	return 5;
}

static int inst_ex_ba_hl(Machine::State& cpu) {
	op_ex16(cpu, cpu.reg.ba, cpu.reg.hl);
	return 3;
}

static int inst_ld_a_nb(Machine::State& cpu) {
	op_ld8(cpu, cpu.reg.a, cpu.reg.nb);
	return 2;
}

static int inst_ex_ba_ix(Machine::State& cpu) {
	op_ex16(cpu, cpu.reg.ba, cpu.reg.ix);
	return 3;
}

static int inst_ld_a_ep(Machine::State& cpu) {
	op_ld8(cpu, cpu.reg.a, cpu.reg.ep);
	return 2;
}

static int inst_ex_ba_iy(Machine::State& cpu) {
	op_ex16(cpu, cpu.reg.ba, cpu.reg.iy);
	return 3;
}

static int inst_ld_a_xp(Machine::State& cpu) {
	op_ld8(cpu, cpu.reg.a, cpu.reg.xp);
	return 2;
}

static int inst_ex_ba_sp(Machine::State& cpu) {
	op_ex16(cpu, cpu.reg.ba, cpu.reg.sp);
	return 3;
}

static int inst_ld_a_yp(Machine::State& cpu) {
	op_ld8(cpu, cpu.reg.a, cpu.reg.yp);
	return 2;
}

static int inst_ex_a_b(Machine::State& cpu) {
	op_ex8(cpu, cpu.reg.a, cpu.reg.b);
	return 2;
}

static int inst_ld_nb_a(Machine::State& cpu) {
	op_ld8(cpu, cpu.reg.nb, cpu.reg.a);
	return 3 + inst_advance(cpu); // Block IRQs
}

static int inst_ex_a_abshl(Machine::State& cpu) {
	const auto addr1 = calc_absHL(cpu);
	uint8_t data1 = Machine::read8(cpu, addr1);
	op_ex8(cpu, cpu.reg.a, data1);
	Machine::write8(cpu, data1, addr1);
	return 3;
}

static int inst_ld_ep_a(Machine::State& cpu) {
	op_ld8(cpu, cpu.reg.ep, cpu.reg.a);
	return 2;
}

static int inst_ld_xp_a(Machine::State& cpu) {
	op_ld8(cpu, cpu.reg.xp, cpu.reg.a);
	return 2;
}

static int inst_ld_yp_a(Machine::State& cpu) {
	op_ld8(cpu, cpu.reg.yp, cpu.reg.a);
	return 2;
}

static int inst_sub_ba_imm16(Machine::State& cpu) {
	const uint16_t data1 = Machine::imm16(cpu);
	op_sub16(cpu, cpu.reg.ba, data1);
	return 3;
}

static int inst_ld_a_ind16(Machine::State& cpu) {
	const auto addr1 = calc_ind16(cpu);
	const uint8_t data1 = Machine::read8(cpu, addr1);
	op_ld8(cpu, cpu.reg.a, data1);
	return 5;
}

static int inst_ld_ba_absix(Machine::State& cpu) {
	const auto addr1 = calc_absIX(cpu);
	const uint16_t data1 = Machine::read16(cpu, addr1);
	op_ld16(cpu, cpu.reg.ba, data1);
	return 5;
}

static int inst_sub_hl_imm16(Machine::State& cpu) {
	const uint16_t data1 = Machine::imm16(cpu);
	op_sub16(cpu, cpu.reg.hl, data1);
	return 3;
}

static int inst_ld_b_ind16(Machine::State& cpu) {
	const auto addr1 = calc_ind16(cpu);
	const uint8_t data1 = Machine::read8(cpu, addr1);
	op_ld8(cpu, cpu.reg.b, data1);
	return 5;
}

static int inst_ld_hl_absix(Machine::State& cpu) {
	const auto addr1 = calc_absIX(cpu);
	const uint16_t data1 = Machine::read16(cpu, addr1);
	op_ld16(cpu, cpu.reg.hl, data1);
	return 5;
}

static int inst_sub_ix_imm16(Machine::State& cpu) {
	const uint16_t data1 = Machine::imm16(cpu);
	op_sub16(cpu, cpu.reg.ix, data1);
	return 3;
}

static int inst_ld_l_ind16(Machine::State& cpu) {
	const auto addr1 = calc_ind16(cpu);
	const uint8_t data1 = Machine::read8(cpu, addr1);
	op_ld8(cpu, cpu.reg.l, data1);
	return 5;
}

static int inst_ld_ix_absix(Machine::State& cpu) {
	const auto addr1 = calc_absIX(cpu);
	const uint16_t data1 = Machine::read16(cpu, addr1);
	op_ld16(cpu, cpu.reg.ix, data1);
	return 5;
}

static int inst_sub_iy_imm16(Machine::State& cpu) {
	const uint16_t data1 = Machine::imm16(cpu);
	op_sub16(cpu, cpu.reg.iy, data1);
	return 3;
}

static int inst_ld_h_ind16(Machine::State& cpu) {
	const auto addr1 = calc_ind16(cpu);
	const uint8_t data1 = Machine::read8(cpu, addr1);
	op_ld8(cpu, cpu.reg.h, data1);
	return 5;
}

static int inst_ld_iy_absix(Machine::State& cpu) {
	const auto addr1 = calc_absIX(cpu);
	const uint16_t data1 = Machine::read16(cpu, addr1);
	op_ld16(cpu, cpu.reg.iy, data1);
	return 5;
}

static int inst_cp_ba_imm16(Machine::State& cpu) {
	const uint16_t data1 = Machine::imm16(cpu);
	op_cp16(cpu, cpu.reg.ba, data1);
	return 3;
}

static int inst_ld_ind16_a(Machine::State& cpu) {
	const auto addr0 = calc_ind16(cpu);
	uint8_t data0;
	op_ld8(cpu, data0, cpu.reg.a);
	Machine::write8(cpu, data0, addr0);
	return 5;
}

static int inst_ld_absix_ba(Machine::State& cpu) {
	const auto addr0 = calc_absIX(cpu);
	uint16_t data0;
	op_ld16(cpu, data0, cpu.reg.ba);
	Machine::write16(cpu, data0, addr0);
	return 5;
}

static int inst_cp_hl_imm16(Machine::State& cpu) {
	const uint16_t data1 = Machine::imm16(cpu);
	op_cp16(cpu, cpu.reg.hl, data1);
	return 3;
}

static int inst_ld_ind16_b(Machine::State& cpu) {
	const auto addr0 = calc_ind16(cpu);
	uint8_t data0;
	op_ld8(cpu, data0, cpu.reg.b);
	Machine::write8(cpu, data0, addr0);
	return 5;
}

static int inst_ld_absix_hl(Machine::State& cpu) {
	const auto addr0 = calc_absIX(cpu);
	uint16_t data0;
	op_ld16(cpu, data0, cpu.reg.hl);
	Machine::write16(cpu, data0, addr0);
	return 5;
}

static int inst_cp_ix_imm16(Machine::State& cpu) {
	const uint16_t data1 = Machine::imm16(cpu);
	op_cp16(cpu, cpu.reg.ix, data1);
	return 3;
}

static int inst_ld_ind16_l(Machine::State& cpu) {
	const auto addr0 = calc_ind16(cpu);
	uint8_t data0;
	op_ld8(cpu, data0, cpu.reg.l);
	Machine::write8(cpu, data0, addr0);
	return 5;
}

static int inst_ld_absix_ix(Machine::State& cpu) {
	const auto addr0 = calc_absIX(cpu);
	uint16_t data0;
	op_ld16(cpu, data0, cpu.reg.ix);
	Machine::write16(cpu, data0, addr0);
	return 5;
}

static int inst_cp_iy_imm16(Machine::State& cpu) {
	const uint16_t data1 = Machine::imm16(cpu);
	op_cp16(cpu, cpu.reg.iy, data1);
	return 3;
}

static int inst_ld_ind16_h(Machine::State& cpu) {
	const auto addr0 = calc_ind16(cpu);
	uint8_t data0;
	op_ld8(cpu, data0, cpu.reg.h);
	Machine::write8(cpu, data0, addr0);
	return 5;
}

static int inst_ld_absix_iy(Machine::State& cpu) {
	const auto addr0 = calc_absIX(cpu);
	uint16_t data0;
	op_ld16(cpu, data0, cpu.reg.iy);
	Machine::write16(cpu, data0, addr0);
	return 5;
}

static int inst_and_absbr_imm8(Machine::State& cpu) {
	const auto addr0 = calc_absBR(cpu);
	uint8_t data0 = Machine::read8(cpu, addr0);
	const uint8_t data1 = Machine::imm8(cpu);
	op_and8(cpu, data0, data1);
	Machine::write8(cpu, data0, addr0);
	return 5;
}

int clock_inst_mlt(Machine::State& cpu) {
	inst_mlt(cpu);
	return 12;
}

static int inst_ld_ba_absiy(Machine::State& cpu) {
	const auto addr1 = calc_absIY(cpu);
	const uint16_t data1 = Machine::read16(cpu, addr1);
	op_ld16(cpu, cpu.reg.ba, data1);
	return 5;
}

static int inst_or_absbr_imm8(Machine::State& cpu) {
	const auto addr0 = calc_absBR(cpu);
	uint8_t data0 = Machine::read8(cpu, addr0);
	const uint8_t data1 = Machine::imm8(cpu);
	op_or8(cpu, data0, data1);
	Machine::write8(cpu, data0, addr0);
	return 5;
}

int clock_inst_div(Machine::State& cpu) {
	inst_div(cpu);
	return 13;
}

static int inst_ld_hl_absiy(Machine::State& cpu) {
	const auto addr1 = calc_absIY(cpu);
	const uint16_t data1 = Machine::read16(cpu, addr1);
	op_ld16(cpu, cpu.reg.hl, data1);
	return 5;
}

static int inst_xor_absbr_imm8(Machine::State& cpu) {
	const auto addr0 = calc_absBR(cpu);
	uint8_t data0 = Machine::read8(cpu, addr0);
	const uint8_t data1 = Machine::imm8(cpu);
	op_xor8(cpu, data0, data1);
	Machine::write8(cpu, data0, addr0);
	return 5;
}

static int inst_ld_ix_absiy(Machine::State& cpu) {
	const auto addr1 = calc_absIY(cpu);
	const uint16_t data1 = Machine::read16(cpu, addr1);
	op_ld16(cpu, cpu.reg.ix, data1);
	return 5;
}

static int inst_cp_absbr_imm8(Machine::State& cpu) {
	const auto addr0 = calc_absBR(cpu);
	const uint8_t data0 = Machine::read8(cpu, addr0);
	const uint8_t data1 = Machine::imm8(cpu);
	op_cp8(cpu, data0, data1);
	return 4;
}

static int inst_ld_iy_absiy(Machine::State& cpu) {
	const auto addr1 = calc_absIY(cpu);
	const uint16_t data1 = Machine::read16(cpu, addr1);
	op_ld16(cpu, cpu.reg.iy, data1);
	return 5;
}

static int inst_bit_absbr_imm8(Machine::State& cpu) {
	const auto addr0 = calc_absBR(cpu);
	const uint8_t data0 = Machine::read8(cpu, addr0);
	const uint8_t data1 = Machine::imm8(cpu);
	op_bit8(cpu, data0, data1);
	return 4;
}

static int inst_ld_absiy_ba(Machine::State& cpu) {
	const auto addr0 = calc_absIY(cpu);
	uint16_t data0;
	op_ld16(cpu, data0, cpu.reg.ba);
	Machine::write16(cpu, data0, addr0);
	return 5;
}

static int inst_ld_absbr_imm8(Machine::State& cpu) {
	const auto addr0 = calc_absBR(cpu);
	uint8_t data0;
	const uint8_t data1 = Machine::imm8(cpu);
	op_ld8(cpu, data0, data1);
	Machine::write8(cpu, data0, addr0);
	return 4;
}

static int inst_ld_absiy_hl(Machine::State& cpu) {
	const auto addr0 = calc_absIY(cpu);
	uint16_t data0;
	op_ld16(cpu, data0, cpu.reg.hl);
	Machine::write16(cpu, data0, addr0);
	return 5;
}

int clock_inst_pack(Machine::State& cpu) {
	inst_pack(cpu);
	return 2;
}

static int inst_ld_absiy_ix(Machine::State& cpu) {
	const auto addr0 = calc_absIY(cpu);
	uint16_t data0;
	op_ld16(cpu, data0, cpu.reg.ix);
	Machine::write16(cpu, data0, addr0);
	return 5;
}

int clock_inst_upck(Machine::State& cpu) {
	inst_upck(cpu);
	return 2;
}

static int inst_ld_absiy_iy(Machine::State& cpu) {
	const auto addr0 = calc_absIY(cpu);
	uint16_t data0;
	op_ld16(cpu, data0, cpu.reg.iy);
	Machine::write16(cpu, data0, addr0);
	return 5;
}

static int inst_cars_c_imm8(Machine::State& cpu) {
	const uint8_t data0 = Machine::imm8(cpu);
	if (!(cpu.reg.flag.c)) {
		cpu.reg.cb = cpu.reg.nb;
		return 2;
	}
	op_cars8(cpu, data0);
	return 5;
}

static int inst_jrs_lt_imm8(Machine::State& cpu) {
	const uint8_t data0 = Machine::imm8(cpu);
	if (!(cpu.reg.flag.n != cpu.reg.flag.v)) {
		cpu.reg.cb = cpu.reg.nb;
		return 3;
	}
	op_jrs8(cpu, data0);
	return 3;
}

static int inst_ld_ba_ba(Machine::State& cpu) {
	op_ld16(cpu, cpu.reg.ba, cpu.reg.ba);
	return 2;
}

static int inst_cars_nc_imm8(Machine::State& cpu) {
	const uint8_t data0 = Machine::imm8(cpu);
	if (!(!cpu.reg.flag.c)) {
		cpu.reg.cb = cpu.reg.nb;
		return 2;
	}
	op_cars8(cpu, data0);
	return 5;
}

static int inst_jrs_le_imm8(Machine::State& cpu) {
	const uint8_t data0 = Machine::imm8(cpu);
	if (!((cpu.reg.flag.n != cpu.reg.flag.v) || cpu.reg.flag.z)) {
		cpu.reg.cb = cpu.reg.nb;
		return 3;
	}
	op_jrs8(cpu, data0);
	return 3;
}

static int inst_ld_ba_hl(Machine::State& cpu) {
	op_ld16(cpu, cpu.reg.ba, cpu.reg.hl);
	return 2;
}

static int inst_cars_z_imm8(Machine::State& cpu) {
	const uint8_t data0 = Machine::imm8(cpu);
	if (!(cpu.reg.flag.z)) {
		cpu.reg.cb = cpu.reg.nb;
		return 2;
	}
	op_cars8(cpu, data0);
	return 5;
}

static int inst_jrs_gt_imm8(Machine::State& cpu) {
	const uint8_t data0 = Machine::imm8(cpu);
	if (!((cpu.reg.flag.n == cpu.reg.flag.v) && !cpu.reg.flag.z)) {
		cpu.reg.cb = cpu.reg.nb;
		return 3;
	}
	op_jrs8(cpu, data0);
	return 3;
}

static int inst_ld_ba_ix(Machine::State& cpu) {
	op_ld16(cpu, cpu.reg.ba, cpu.reg.ix);
	return 2;
}

static int inst_cars_nz_imm8(Machine::State& cpu) {
	const uint8_t data0 = Machine::imm8(cpu);
	if (!(!cpu.reg.flag.z)) {
		cpu.reg.cb = cpu.reg.nb;
		return 2;
	}
	op_cars8(cpu, data0);
	return 5;
}

static int inst_jrs_ge_imm8(Machine::State& cpu) {
	const uint8_t data0 = Machine::imm8(cpu);
	if (!(cpu.reg.flag.n == cpu.reg.flag.v)) {
		cpu.reg.cb = cpu.reg.nb;
		return 3;
	}
	op_jrs8(cpu, data0);
	return 3;
}

static int inst_ld_ba_iy(Machine::State& cpu) {
	op_ld16(cpu, cpu.reg.ba, cpu.reg.iy);
	return 2;
}

static int inst_jrs_c_imm8(Machine::State& cpu) {
	const uint8_t data0 = Machine::imm8(cpu);
	if (!(cpu.reg.flag.c)) {
		cpu.reg.cb = cpu.reg.nb;
		return 2;
	}
	op_jrs8(cpu, data0);
	return 2;
}

static int inst_jrs_v_imm8(Machine::State& cpu) {
	const uint8_t data0 = Machine::imm8(cpu);
	if (!(cpu.reg.flag.v)) {
		cpu.reg.cb = cpu.reg.nb;
		return 3;
	}
	op_jrs8(cpu, data0);
	return 3;
}

static int inst_ld_hl_ba(Machine::State& cpu) {
	op_ld16(cpu, cpu.reg.hl, cpu.reg.ba);
	return 2;
}

static int inst_jrs_nc_imm8(Machine::State& cpu) {
	const uint8_t data0 = Machine::imm8(cpu);
	if (!(!cpu.reg.flag.c)) {
		cpu.reg.cb = cpu.reg.nb;
		return 2;
	}
	op_jrs8(cpu, data0);
	return 2;
}

static int inst_jrs_nv_imm8(Machine::State& cpu) {
	const uint8_t data0 = Machine::imm8(cpu);
	if (!(!cpu.reg.flag.v)) {
		cpu.reg.cb = cpu.reg.nb;
		return 3;
	}
	op_jrs8(cpu, data0);
	return 3;
}

static int inst_ld_hl_hl(Machine::State& cpu) {
	op_ld16(cpu, cpu.reg.hl, cpu.reg.hl);
	return 2;
}

static int inst_jrs_z_imm8(Machine::State& cpu) {
	const uint8_t data0 = Machine::imm8(cpu);
	if (!(cpu.reg.flag.z)) {
		cpu.reg.cb = cpu.reg.nb;
		return 2;
	}
	op_jrs8(cpu, data0);
	return 2;
}

static int inst_jrs_p_imm8(Machine::State& cpu) {
	const uint8_t data0 = Machine::imm8(cpu);
	if (!(!cpu.reg.flag.n)) {
		cpu.reg.cb = cpu.reg.nb;
		return 3;
	}
	op_jrs8(cpu, data0);
	return 3;
}

static int inst_ld_hl_ix(Machine::State& cpu) {
	op_ld16(cpu, cpu.reg.hl, cpu.reg.ix);
	return 2;
}

static int inst_jrs_nz_imm8(Machine::State& cpu) {
	const uint8_t data0 = Machine::imm8(cpu);
	if (!(!cpu.reg.flag.z)) {
		cpu.reg.cb = cpu.reg.nb;
		return 2;
	}
	op_jrs8(cpu, data0);
	return 2;
}

static int inst_jrs_m_imm8(Machine::State& cpu) {
	const uint8_t data0 = Machine::imm8(cpu);
	if (!(cpu.reg.flag.n)) {
		cpu.reg.cb = cpu.reg.nb;
		return 3;
	}
	op_jrs8(cpu, data0);
	return 3;
}

static int inst_ld_hl_iy(Machine::State& cpu) {
	op_ld16(cpu, cpu.reg.hl, cpu.reg.iy);
	return 2;
}

static int inst_carl_c_imm16(Machine::State& cpu) {
	const uint16_t data0 = Machine::imm16(cpu);
	if (!(cpu.reg.flag.c)) {
		cpu.reg.cb = cpu.reg.nb;
		return 3;
	}
	op_carl16(cpu, data0);
	return 6;
}

static int inst_jrs_f0_imm8(Machine::State& cpu) {
	const uint8_t data0 = Machine::imm8(cpu);
	if (!(cpu.reg.flag.f0)) {
		cpu.reg.cb = cpu.reg.nb;
		return 3;
	}
	op_jrs8(cpu, data0);
	return 3;
}

static int inst_ld_ix_ba(Machine::State& cpu) {
	op_ld16(cpu, cpu.reg.ix, cpu.reg.ba);
	return 2;
}

static int inst_carl_nc_imm16(Machine::State& cpu) {
	const uint16_t data0 = Machine::imm16(cpu);
	if (!(!cpu.reg.flag.c)) {
		cpu.reg.cb = cpu.reg.nb;
		return 3;
	}
	op_carl16(cpu, data0);
	return 6;
}

static int inst_jrs_f1_imm8(Machine::State& cpu) {
	const uint8_t data0 = Machine::imm8(cpu);
	if (!(cpu.reg.flag.f1)) {
		cpu.reg.cb = cpu.reg.nb;
		return 3;
	}
	op_jrs8(cpu, data0);
	return 3;
}

static int inst_ld_ix_hl(Machine::State& cpu) {
	op_ld16(cpu, cpu.reg.ix, cpu.reg.hl);
	return 2;
}

static int inst_carl_z_imm16(Machine::State& cpu) {
	const uint16_t data0 = Machine::imm16(cpu);
	if (!(cpu.reg.flag.z)) {
		cpu.reg.cb = cpu.reg.nb;
		return 3;
	}
	op_carl16(cpu, data0);
	return 6;
}

static int inst_jrs_f2_imm8(Machine::State& cpu) {
	const uint8_t data0 = Machine::imm8(cpu);
	if (!(cpu.reg.flag.f2)) {
		cpu.reg.cb = cpu.reg.nb;
		return 3;
	}
	op_jrs8(cpu, data0);
	return 3;
}

static int inst_ld_ix_ix(Machine::State& cpu) {
	op_ld16(cpu, cpu.reg.ix, cpu.reg.ix);
	return 2;
}

static int inst_carl_nz_imm16(Machine::State& cpu) {
	const uint16_t data0 = Machine::imm16(cpu);
	if (!(!cpu.reg.flag.z)) {
		cpu.reg.cb = cpu.reg.nb;
		return 3;
	}
	op_carl16(cpu, data0);
	return 6;
}

static int inst_jrs_f3_imm8(Machine::State& cpu) {
	const uint8_t data0 = Machine::imm8(cpu);
	if (!(cpu.reg.flag.f3)) {
		cpu.reg.cb = cpu.reg.nb;
		return 3;
	}
	op_jrs8(cpu, data0);
	return 3;
}

static int inst_ld_ix_iy(Machine::State& cpu) {
	op_ld16(cpu, cpu.reg.ix, cpu.reg.iy);
	return 2;
}

static int inst_jrl_c_imm16(Machine::State& cpu) {
	const uint16_t data0 = Machine::imm16(cpu);
	if (!(cpu.reg.flag.c)) {
		cpu.reg.cb = cpu.reg.nb;
		return 3;
	}
	op_jrl16(cpu, data0);
	return 3;
}

static int inst_jrs_nf0_imm8(Machine::State& cpu) {
	const uint8_t data0 = Machine::imm8(cpu);
	if (!(!cpu.reg.flag.f0)) {
		cpu.reg.cb = cpu.reg.nb;
		return 3;
	}
	op_jrs8(cpu, data0);
	return 3;
}

static int inst_ld_iy_ba(Machine::State& cpu) {
	op_ld16(cpu, cpu.reg.iy, cpu.reg.ba);
	return 2;
}

static int inst_jrl_nc_imm16(Machine::State& cpu) {
	const uint16_t data0 = Machine::imm16(cpu);
	if (!(!cpu.reg.flag.c)) {
		cpu.reg.cb = cpu.reg.nb;
		return 3;
	}
	op_jrl16(cpu, data0);
	return 3;
}

static int inst_jrs_nf1_imm8(Machine::State& cpu) {
	const uint8_t data0 = Machine::imm8(cpu);
	if (!(!cpu.reg.flag.f1)) {
		cpu.reg.cb = cpu.reg.nb;
		return 3;
	}
	op_jrs8(cpu, data0);
	return 3;
}

static int inst_ld_iy_hl(Machine::State& cpu) {
	op_ld16(cpu, cpu.reg.iy, cpu.reg.hl);
	return 2;
}

static int inst_jrl_z_imm16(Machine::State& cpu) {
	const uint16_t data0 = Machine::imm16(cpu);
	if (!(cpu.reg.flag.z)) {
		cpu.reg.cb = cpu.reg.nb;
		return 3;
	}
	op_jrl16(cpu, data0);
	return 3;
}

static int inst_jrs_nf2_imm8(Machine::State& cpu) {
	const uint8_t data0 = Machine::imm8(cpu);
	if (!(!cpu.reg.flag.f2)) {
		cpu.reg.cb = cpu.reg.nb;
		return 3;
	}
	op_jrs8(cpu, data0);
	return 3;
}

static int inst_ld_iy_ix(Machine::State& cpu) {
	op_ld16(cpu, cpu.reg.iy, cpu.reg.ix);
	return 2;
}

static int inst_jrl_nz_imm16(Machine::State& cpu) {
	const uint16_t data0 = Machine::imm16(cpu);
	if (!(!cpu.reg.flag.z)) {
		cpu.reg.cb = cpu.reg.nb;
		return 3;
	}
	op_jrl16(cpu, data0);
	return 3;
}

static int inst_jrs_nf3_imm8(Machine::State& cpu) {
	const uint8_t data0 = Machine::imm8(cpu);
	if (!(!cpu.reg.flag.f3)) {
		cpu.reg.cb = cpu.reg.nb;
		return 3;
	}
	op_jrs8(cpu, data0);
	return 3;
}

static int inst_ld_iy_iy(Machine::State& cpu) {
	op_ld16(cpu, cpu.reg.iy, cpu.reg.iy);
	return 2;
}

static int inst_cars_imm8(Machine::State& cpu) {
	const uint8_t data0 = Machine::imm8(cpu);
	op_cars8(cpu, data0);
	return 5;
}

static int inst_cars_lt_imm8(Machine::State& cpu) {
	const uint8_t data0 = Machine::imm8(cpu);
	if (!(cpu.reg.flag.n != cpu.reg.flag.v)) {
		cpu.reg.cb = cpu.reg.nb;
		return 3;
	}
	op_cars8(cpu, data0);
	return 6;
}

static int inst_ld_sp_ba(Machine::State& cpu) {
	op_ld16(cpu, cpu.reg.sp, cpu.reg.ba);
	return 2;
}

static int inst_jrs_imm8(Machine::State& cpu) {
	const uint8_t data0 = Machine::imm8(cpu);
	op_jrs8(cpu, data0);
	return 2;
}

static int inst_cars_le_imm8(Machine::State& cpu) {
	const uint8_t data0 = Machine::imm8(cpu);
	if (!((cpu.reg.flag.n != cpu.reg.flag.v) || cpu.reg.flag.z)) {
		cpu.reg.cb = cpu.reg.nb;
		return 3;
	}
	op_cars8(cpu, data0);
	return 6;
}

static int inst_ld_sp_hl(Machine::State& cpu) {
	op_ld16(cpu, cpu.reg.sp, cpu.reg.hl);
	return 2;
}

static int inst_carl_imm16(Machine::State& cpu) {
	const uint16_t data0 = Machine::imm16(cpu);
	op_carl16(cpu, data0);
	return 6;
}

static int inst_cars_gt_imm8(Machine::State& cpu) {
	const uint8_t data0 = Machine::imm8(cpu);
	if (!((cpu.reg.flag.n == cpu.reg.flag.v) && !cpu.reg.flag.z)) {
		cpu.reg.cb = cpu.reg.nb;
		return 3;
	}
	op_cars8(cpu, data0);
	return 6;
}

static int inst_ld_sp_ix(Machine::State& cpu) {
	op_ld16(cpu, cpu.reg.sp, cpu.reg.ix);
	return 2;
}

static int inst_jrl_imm16(Machine::State& cpu) {
	const uint16_t data0 = Machine::imm16(cpu);
	op_jrl16(cpu, data0);
	return 3;
}

static int inst_cars_ge_imm8(Machine::State& cpu) {
	const uint8_t data0 = Machine::imm8(cpu);
	if (!(cpu.reg.flag.n == cpu.reg.flag.v)) {
		cpu.reg.cb = cpu.reg.nb;
		return 3;
	}
	op_cars8(cpu, data0);
	return 6;
}

static int inst_ld_sp_iy(Machine::State& cpu) {
	op_ld16(cpu, cpu.reg.sp, cpu.reg.iy);
	return 2;
}

static int inst_jp_hl(Machine::State& cpu) {
	op_jp16(cpu, cpu.reg.hl);
	return 2;
}

static int inst_cars_v_imm8(Machine::State& cpu) {
	const uint8_t data0 = Machine::imm8(cpu);
	if (!(cpu.reg.flag.v)) {
		cpu.reg.cb = cpu.reg.nb;
		return 3;
	}
	op_cars8(cpu, data0);
	return 6;
}

static int inst_ld_hl_sp(Machine::State& cpu) {
	op_ld16(cpu, cpu.reg.hl, cpu.reg.sp);
	return 2;
}

int clock_inst_djr_nz_rr(Machine::State& cpu) {
	inst_djr_nz_rr(cpu);
	return 4;
}

static int inst_cars_nv_imm8(Machine::State& cpu) {
	const uint8_t data0 = Machine::imm8(cpu);
	if (!(!cpu.reg.flag.v)) {
		cpu.reg.cb = cpu.reg.nb;
		return 3;
	}
	op_cars8(cpu, data0);
	return 6;
}

static int inst_ld_hl_pc(Machine::State& cpu) {
	op_ld16(cpu, cpu.reg.hl, cpu.reg.pc);
	return 2;
}

static int inst_swap_a(Machine::State& cpu) {
	op_swap8(cpu, cpu.reg.a);
	return 2;
}

static int inst_cars_p_imm8(Machine::State& cpu) {
	const uint8_t data0 = Machine::imm8(cpu);
	if (!(!cpu.reg.flag.n)) {
		cpu.reg.cb = cpu.reg.nb;
		return 3;
	}
	op_cars8(cpu, data0);
	return 6;
}

static int inst_swap_abshl(Machine::State& cpu) {
	const auto addr0 = calc_absHL(cpu);
	uint8_t data0 = Machine::read8(cpu, addr0);
	op_swap8(cpu, data0);
	Machine::write8(cpu, data0, addr0);
	return 3;
}

static int inst_cars_m_imm8(Machine::State& cpu) {
	const uint8_t data0 = Machine::imm8(cpu);
	if (!(cpu.reg.flag.n)) {
		cpu.reg.cb = cpu.reg.nb;
		return 3;
	}
	op_cars8(cpu, data0);
	return 6;
}

int clock_inst_ret(Machine::State& cpu) {
	inst_ret(cpu);
	return 4;
}

static int inst_cars_f0_imm8(Machine::State& cpu) {
	const uint8_t data0 = Machine::imm8(cpu);
	if (!(cpu.reg.flag.f0)) {
		cpu.reg.cb = cpu.reg.nb;
		return 3;
	}
	op_cars8(cpu, data0);
	return 6;
}

static int inst_ld_ba_sp(Machine::State& cpu) {
	op_ld16(cpu, cpu.reg.ba, cpu.reg.sp);
	return 2;
}

static int inst_rete(Machine::State& cpu) {
	op_rete8(cpu);
	return 5 + inst_advance(cpu); // Block IRQs
}

static int inst_cars_f1_imm8(Machine::State& cpu) {
	const uint8_t data0 = Machine::imm8(cpu);
	if (!(cpu.reg.flag.f1)) {
		cpu.reg.cb = cpu.reg.nb;
		return 3;
	}
	op_cars8(cpu, data0);
	return 6;
}

static int inst_ld_ba_pc(Machine::State& cpu) {
	op_ld16(cpu, cpu.reg.ba, cpu.reg.pc);
	return 2;
}

int clock_inst_rets(Machine::State& cpu) {
	inst_rets(cpu);
	return 6;
}

static int inst_cars_f2_imm8(Machine::State& cpu) {
	const uint8_t data0 = Machine::imm8(cpu);
	if (!(cpu.reg.flag.f2)) {
		cpu.reg.cb = cpu.reg.nb;
		return 3;
	}
	op_cars8(cpu, data0);
	return 6;
}

static int inst_ld_ix_sp(Machine::State& cpu) {
	op_ld16(cpu, cpu.reg.ix, cpu.reg.sp);
	return 2;
}

static int inst_call_ind16(Machine::State& cpu) {
	const auto addr0 = calc_ind16(cpu);
	const uint16_t data0 = Machine::read16(cpu, addr0);
	op_call16(cpu, data0);
	return 8;
}

static int inst_cars_f3_imm8(Machine::State& cpu) {
	const uint8_t data0 = Machine::imm8(cpu);
	if (!(cpu.reg.flag.f3)) {
		cpu.reg.cb = cpu.reg.nb;
		return 3;
	}
	op_cars8(cpu, data0);
	return 6;
}

static int inst_int_vect(Machine::State& cpu) {
	const auto addr0 = calc_vect(cpu);
	const uint16_t data0 = Machine::read16(cpu, addr0);
	op_int16(cpu, data0);
	return 8;
}

static int inst_cars_nf0_imm8(Machine::State& cpu) {
	const uint8_t data0 = Machine::imm8(cpu);
	if (!(!cpu.reg.flag.f0)) {
		cpu.reg.cb = cpu.reg.nb;
		return 3;
	}
	op_cars8(cpu, data0);
	return 6;
}

static int inst_jp_vect(Machine::State& cpu) {
	const auto addr0 = calc_vect(cpu);
	const uint16_t data0 = Machine::read16(cpu, addr0);
	op_jp16(cpu, data0);
	return 4;
}

static int inst_cars_nf1_imm8(Machine::State& cpu) {
	const uint8_t data0 = Machine::imm8(cpu);
	if (!(!cpu.reg.flag.f1)) {
		cpu.reg.cb = cpu.reg.nb;
		return 3;
	}
	op_cars8(cpu, data0);
	return 6;
}

static int inst_cars_nf2_imm8(Machine::State& cpu) {
	const uint8_t data0 = Machine::imm8(cpu);
	if (!(!cpu.reg.flag.f2)) {
		cpu.reg.cb = cpu.reg.nb;
		return 3;
	}
	op_cars8(cpu, data0);
	return 6;
}

static int inst_ld_iy_sp(Machine::State& cpu) {
	op_ld16(cpu, cpu.reg.iy, cpu.reg.sp);
	return 2;
}

int clock_inst_nop(Machine::State& cpu) {
	inst_nop(cpu);
	return 2;
}

static int inst_cars_nf3_imm8(Machine::State& cpu) {
	const uint8_t data0 = Machine::imm8(cpu);
	if (!(!cpu.reg.flag.f3)) {
		cpu.reg.cb = cpu.reg.nb;
		return 3;
	}
	op_cars8(cpu, data0);
	return 6;
}

int inst_advance(Machine::State& cpu) {
	switch (Machine::imm8(cpu)) {
	case 0x00: return inst_add_a_a(cpu);
	case 0x01: return inst_add_a_b(cpu);
	case 0x02: return inst_add_a_imm8(cpu);
	case 0x03: return inst_add_a_abshl(cpu);
	case 0x04: return inst_add_a_absbr(cpu);
	case 0x05: return inst_add_a_ind16(cpu);
	case 0x06: return inst_add_a_absix(cpu);
	case 0x07: return inst_add_a_absiy(cpu);
	case 0x08: return inst_adc_a_a(cpu);
	case 0x09: return inst_adc_a_b(cpu);
	case 0x0A: return inst_adc_a_imm8(cpu);
	case 0x0B: return inst_adc_a_abshl(cpu);
	case 0x0C: return inst_adc_a_absbr(cpu);
	case 0x0D: return inst_adc_a_ind16(cpu);
	case 0x0E: return inst_adc_a_absix(cpu);
	case 0x0F: return inst_adc_a_absiy(cpu);
	case 0x10: return inst_sub_a_a(cpu);
	case 0x11: return inst_sub_a_b(cpu);
	case 0x12: return inst_sub_a_imm8(cpu);
	case 0x13: return inst_sub_a_abshl(cpu);
	case 0x14: return inst_sub_a_absbr(cpu);
	case 0x15: return inst_sub_a_ind16(cpu);
	case 0x16: return inst_sub_a_absix(cpu);
	case 0x17: return inst_sub_a_absiy(cpu);
	case 0x18: return inst_sbc_a_a(cpu);
	case 0x19: return inst_sbc_a_b(cpu);
	case 0x1A: return inst_sbc_a_imm8(cpu);
	case 0x1B: return inst_sbc_a_abshl(cpu);
	case 0x1C: return inst_sbc_a_absbr(cpu);
	case 0x1D: return inst_sbc_a_ind16(cpu);
	case 0x1E: return inst_sbc_a_absix(cpu);
	case 0x1F: return inst_sbc_a_absiy(cpu);
	case 0x20: return inst_and_a_a(cpu);
	case 0x21: return inst_and_a_b(cpu);
	case 0x22: return inst_and_a_imm8(cpu);
	case 0x23: return inst_and_a_abshl(cpu);
	case 0x24: return inst_and_a_absbr(cpu);
	case 0x25: return inst_and_a_ind16(cpu);
	case 0x26: return inst_and_a_absix(cpu);
	case 0x27: return inst_and_a_absiy(cpu);
	case 0x28: return inst_or_a_a(cpu);
	case 0x29: return inst_or_a_b(cpu);
	case 0x2A: return inst_or_a_imm8(cpu);
	case 0x2B: return inst_or_a_abshl(cpu);
	case 0x2C: return inst_or_a_absbr(cpu);
	case 0x2D: return inst_or_a_ind16(cpu);
	case 0x2E: return inst_or_a_absix(cpu);
	case 0x2F: return inst_or_a_absiy(cpu);
	case 0x30: return inst_cp_a_a(cpu);
	case 0x31: return inst_cp_a_b(cpu);
	case 0x32: return inst_cp_a_imm8(cpu);
	case 0x33: return inst_cp_a_abshl(cpu);
	case 0x34: return inst_cp_a_absbr(cpu);
	case 0x35: return inst_cp_a_ind16(cpu);
	case 0x36: return inst_cp_a_absix(cpu);
	case 0x37: return inst_cp_a_absiy(cpu);
	case 0x38: return inst_xor_a_a(cpu);
	case 0x39: return inst_xor_a_b(cpu);
	case 0x3A: return inst_xor_a_imm8(cpu);
	case 0x3B: return inst_xor_a_abshl(cpu);
	case 0x3C: return inst_xor_a_absbr(cpu);
	case 0x3D: return inst_xor_a_ind16(cpu);
	case 0x3E: return inst_xor_a_absix(cpu);
	case 0x3F: return inst_xor_a_absiy(cpu);
	case 0x40: return inst_ld_a_a(cpu);
	case 0x41: return inst_ld_a_b(cpu);
	case 0x42: return inst_ld_a_l(cpu);
	case 0x43: return inst_ld_a_h(cpu);
	case 0x44: return inst_ld_a_absbr(cpu);
	case 0x45: return inst_ld_a_abshl(cpu);
	case 0x46: return inst_ld_a_absix(cpu);
	case 0x47: return inst_ld_a_absiy(cpu);
	case 0x48: return inst_ld_b_a(cpu);
	case 0x49: return inst_ld_b_b(cpu);
	case 0x4A: return inst_ld_b_l(cpu);
	case 0x4B: return inst_ld_b_h(cpu);
	case 0x4C: return inst_ld_b_absbr(cpu);
	case 0x4D: return inst_ld_b_abshl(cpu);
	case 0x4E: return inst_ld_b_absix(cpu);
	case 0x4F: return inst_ld_b_absiy(cpu);
	case 0x50: return inst_ld_l_a(cpu);
	case 0x51: return inst_ld_l_b(cpu);
	case 0x52: return inst_ld_l_l(cpu);
	case 0x53: return inst_ld_l_h(cpu);
	case 0x54: return inst_ld_l_absbr(cpu);
	case 0x55: return inst_ld_l_abshl(cpu);
	case 0x56: return inst_ld_l_absix(cpu);
	case 0x57: return inst_ld_l_absiy(cpu);
	case 0x58: return inst_ld_h_a(cpu);
	case 0x59: return inst_ld_h_b(cpu);
	case 0x5A: return inst_ld_h_l(cpu);
	case 0x5B: return inst_ld_h_h(cpu);
	case 0x5C: return inst_ld_h_absbr(cpu);
	case 0x5D: return inst_ld_h_abshl(cpu);
	case 0x5E: return inst_ld_h_absix(cpu);
	case 0x5F: return inst_ld_h_absiy(cpu);
	case 0x60: return inst_ld_absix_a(cpu);
	case 0x61: return inst_ld_absix_b(cpu);
	case 0x62: return inst_ld_absix_l(cpu);
	case 0x63: return inst_ld_absix_h(cpu);
	case 0x64: return inst_ld_absix_absbr(cpu);
	case 0x65: return inst_ld_absix_abshl(cpu);
	case 0x66: return inst_ld_absix_absix(cpu);
	case 0x67: return inst_ld_absix_absiy(cpu);
	case 0x68: return inst_ld_abshl_a(cpu);
	case 0x69: return inst_ld_abshl_b(cpu);
	case 0x6A: return inst_ld_abshl_l(cpu);
	case 0x6B: return inst_ld_abshl_h(cpu);
	case 0x6C: return inst_ld_abshl_absbr(cpu);
	case 0x6D: return inst_ld_abshl_abshl(cpu);
	case 0x6E: return inst_ld_abshl_absix(cpu);
	case 0x6F: return inst_ld_abshl_absiy(cpu);
	case 0x70: return inst_ld_absiy_a(cpu);
	case 0x71: return inst_ld_absiy_b(cpu);
	case 0x72: return inst_ld_absiy_l(cpu);
	case 0x73: return inst_ld_absiy_h(cpu);
	case 0x74: return inst_ld_absiy_absbr(cpu);
	case 0x75: return inst_ld_absiy_abshl(cpu);
	case 0x76: return inst_ld_absiy_absix(cpu);
	case 0x77: return inst_ld_absiy_absiy(cpu);
	case 0x78: return inst_ld_absbr_a(cpu);
	case 0x79: return inst_ld_absbr_b(cpu);
	case 0x7A: return inst_ld_absbr_l(cpu);
	case 0x7B: return inst_ld_absbr_h(cpu);
	case 0x7D: return inst_ld_absbr_abshl(cpu);
	case 0x7E: return inst_ld_absbr_absix(cpu);
	case 0x7F: return inst_ld_absbr_absiy(cpu);
	case 0x80: return inst_inc_a(cpu);
	case 0x81: return inst_inc_b(cpu);
	case 0x82: return inst_inc_l(cpu);
	case 0x83: return inst_inc_h(cpu);
	case 0x84: return inst_inc_br(cpu);
	case 0x85: return inst_inc_absbr(cpu);
	case 0x86: return inst_inc_abshl(cpu);
	case 0x87: return inst_inc_sp(cpu);
	case 0x88: return inst_dec_a(cpu);
	case 0x89: return inst_dec_b(cpu);
	case 0x8A: return inst_dec_l(cpu);
	case 0x8B: return inst_dec_h(cpu);
	case 0x8C: return inst_dec_br(cpu);
	case 0x8D: return inst_dec_absbr(cpu);
	case 0x8E: return inst_dec_abshl(cpu);
	case 0x8F: return inst_dec_sp(cpu);
	case 0x90: return inst_inc_ba(cpu);
	case 0x91: return inst_inc_hl(cpu);
	case 0x92: return inst_inc_ix(cpu);
	case 0x93: return inst_inc_iy(cpu);
	case 0x94: return inst_bit_a_b(cpu);
	case 0x95: return inst_bit_abshl_imm8(cpu);
	case 0x96: return inst_bit_a_imm8(cpu);
	case 0x97: return inst_bit_b_imm8(cpu);
	case 0x98: return inst_dec_ba(cpu);
	case 0x99: return inst_dec_hl(cpu);
	case 0x9A: return inst_dec_ix(cpu);
	case 0x9B: return inst_dec_iy(cpu);
	case 0x9C: return inst_and_sc_imm8(cpu);
	case 0x9D: return inst_or_sc_imm8(cpu);
	case 0x9E: return inst_xor_sc_imm8(cpu);
	case 0x9F: return inst_ld_sc_imm8(cpu);
	case 0xA0: return inst_push_ba(cpu);
	case 0xA1: return inst_push_hl(cpu);
	case 0xA2: return inst_push_ix(cpu);
	case 0xA3: return inst_push_iy(cpu);
	case 0xA4: return inst_push_br(cpu);
	case 0xA5: return inst_push_ep(cpu);
	case 0xA6: return clock_inst_push_ip(cpu);
	case 0xA7: return inst_push_sc(cpu);
	case 0xA8: return inst_pop_ba(cpu);
	case 0xA9: return inst_pop_hl(cpu);
	case 0xAA: return inst_pop_ix(cpu);
	case 0xAB: return inst_pop_iy(cpu);
	case 0xAC: return inst_pop_br(cpu);
	case 0xAD: return inst_pop_ep(cpu);
	case 0xAE: return clock_inst_pop_ip(cpu);
	case 0xAF: return inst_pop_sc(cpu);
	case 0xB0: return inst_ld_a_imm8(cpu);
	case 0xB1: return inst_ld_b_imm8(cpu);
	case 0xB2: return inst_ld_l_imm8(cpu);
	case 0xB3: return inst_ld_h_imm8(cpu);
	case 0xB4: return inst_ld_br_imm8(cpu);
	case 0xB5: return inst_ld_abshl_imm8(cpu);
	case 0xB6: return inst_ld_absix_imm8(cpu);
	case 0xB7: return inst_ld_absiy_imm8(cpu);
	case 0xB8: return inst_ld_ba_ind16(cpu);
	case 0xB9: return inst_ld_hl_ind16(cpu);
	case 0xBA: return inst_ld_ix_ind16(cpu);
	case 0xBB: return inst_ld_iy_ind16(cpu);
	case 0xBC: return inst_ld_ind16_ba(cpu);
	case 0xBD: return inst_ld_ind16_hl(cpu);
	case 0xBE: return inst_ld_ind16_ix(cpu);
	case 0xBF: return inst_ld_ind16_iy(cpu);
	case 0xC0: return inst_add_ba_imm16(cpu);
	case 0xC1: return inst_add_hl_imm16(cpu);
	case 0xC2: return inst_add_ix_imm16(cpu);
	case 0xC3: return inst_add_iy_imm16(cpu);
	case 0xC4: return inst_ld_ba_imm16(cpu);
	case 0xC5: return inst_ld_hl_imm16(cpu);
	case 0xC6: return inst_ld_ix_imm16(cpu);
	case 0xC7: return inst_ld_iy_imm16(cpu);
	case 0xC8: return inst_ex_ba_hl(cpu);
	case 0xC9: return inst_ex_ba_ix(cpu);
	case 0xCA: return inst_ex_ba_iy(cpu);
	case 0xCB: return inst_ex_ba_sp(cpu);
	case 0xCC: return inst_ex_a_b(cpu);
	case 0xCD: return inst_ex_a_abshl(cpu);
	case 0xD0: return inst_sub_ba_imm16(cpu);
	case 0xD1: return inst_sub_hl_imm16(cpu);
	case 0xD2: return inst_sub_ix_imm16(cpu);
	case 0xD3: return inst_sub_iy_imm16(cpu);
	case 0xD4: return inst_cp_ba_imm16(cpu);
	case 0xD5: return inst_cp_hl_imm16(cpu);
	case 0xD6: return inst_cp_ix_imm16(cpu);
	case 0xD7: return inst_cp_iy_imm16(cpu);
	case 0xD8: return inst_and_absbr_imm8(cpu);
	case 0xD9: return inst_or_absbr_imm8(cpu);
	case 0xDA: return inst_xor_absbr_imm8(cpu);
	case 0xDB: return inst_cp_absbr_imm8(cpu);
	case 0xDC: return inst_bit_absbr_imm8(cpu);
	case 0xDD: return inst_ld_absbr_imm8(cpu);
	case 0xDE: return clock_inst_pack(cpu);
	case 0xDF: return clock_inst_upck(cpu);
	case 0xE0: return inst_cars_c_imm8(cpu);
	case 0xE1: return inst_cars_nc_imm8(cpu);
	case 0xE2: return inst_cars_z_imm8(cpu);
	case 0xE3: return inst_cars_nz_imm8(cpu);
	case 0xE4: return inst_jrs_c_imm8(cpu);
	case 0xE5: return inst_jrs_nc_imm8(cpu);
	case 0xE6: return inst_jrs_z_imm8(cpu);
	case 0xE7: return inst_jrs_nz_imm8(cpu);
	case 0xE8: return inst_carl_c_imm16(cpu);
	case 0xE9: return inst_carl_nc_imm16(cpu);
	case 0xEA: return inst_carl_z_imm16(cpu);
	case 0xEB: return inst_carl_nz_imm16(cpu);
	case 0xEC: return inst_jrl_c_imm16(cpu);
	case 0xED: return inst_jrl_nc_imm16(cpu);
	case 0xEE: return inst_jrl_z_imm16(cpu);
	case 0xEF: return inst_jrl_nz_imm16(cpu);
	case 0xF0: return inst_cars_imm8(cpu);
	case 0xF1: return inst_jrs_imm8(cpu);
	case 0xF2: return inst_carl_imm16(cpu);
	case 0xF3: return inst_jrl_imm16(cpu);
	case 0xF4: return inst_jp_hl(cpu);
	case 0xF5: return clock_inst_djr_nz_rr(cpu);
	case 0xF6: return inst_swap_a(cpu);
	case 0xF7: return inst_swap_abshl(cpu);
	case 0xF8: return clock_inst_ret(cpu);
	case 0xF9: return inst_rete(cpu);
	case 0xFA: return clock_inst_rets(cpu);
	case 0xFB: return inst_call_ind16(cpu);
	case 0xFC: return inst_int_vect(cpu);
	case 0xFD: return inst_jp_vect(cpu);
	case 0xFF: return clock_inst_nop(cpu);
	default: return inst_undefined(cpu);
	case 0xCE:
		switch (Machine::imm8(cpu)) {
		case 0x00: return inst_add_a_inddix(cpu);
		case 0x01: return inst_add_a_inddiy(cpu);
		case 0x02: return inst_add_a_indiix(cpu);
		case 0x03: return inst_add_a_indiiy(cpu);
		case 0x04: return inst_add_abshl_a(cpu);
		case 0x05: return inst_add_abshl_imm8(cpu);
		case 0x06: return inst_add_abshl_absix(cpu);
		case 0x07: return inst_add_abshl_absiy(cpu);
		case 0x08: return inst_adc_a_inddix(cpu);
		case 0x09: return inst_adc_a_inddiy(cpu);
		case 0x0A: return inst_adc_a_indiix(cpu);
		case 0x0B: return inst_adc_a_indiiy(cpu);
		case 0x0C: return inst_adc_abshl_a(cpu);
		case 0x0D: return inst_adc_abshl_imm8(cpu);
		case 0x0E: return inst_adc_abshl_absix(cpu);
		case 0x0F: return inst_adc_abshl_absiy(cpu);
		case 0x10: return inst_sub_a_inddix(cpu);
		case 0x11: return inst_sub_a_inddiy(cpu);
		case 0x12: return inst_sub_a_indiix(cpu);
		case 0x13: return inst_sub_a_indiiy(cpu);
		case 0x14: return inst_sub_abshl_a(cpu);
		case 0x15: return inst_sub_abshl_imm8(cpu);
		case 0x16: return inst_sub_abshl_absix(cpu);
		case 0x17: return inst_sub_abshl_absiy(cpu);
		case 0x18: return inst_sbc_a_inddix(cpu);
		case 0x19: return inst_sbc_a_inddiy(cpu);
		case 0x1A: return inst_sbc_a_indiix(cpu);
		case 0x1B: return inst_sbc_a_indiiy(cpu);
		case 0x1C: return inst_sbc_abshl_a(cpu);
		case 0x1D: return inst_sbc_abshl_imm8(cpu);
		case 0x1E: return inst_sbc_abshl_absix(cpu);
		case 0x1F: return inst_sbc_abshl_absiy(cpu);
		case 0x20: return inst_and_a_inddix(cpu);
		case 0x21: return inst_and_a_inddiy(cpu);
		case 0x22: return inst_and_a_indiix(cpu);
		case 0x23: return inst_and_a_indiiy(cpu);
		case 0x24: return inst_and_abshl_a(cpu);
		case 0x25: return inst_and_abshl_imm8(cpu);
		case 0x26: return inst_and_abshl_absix(cpu);
		case 0x27: return inst_and_abshl_absiy(cpu);
		case 0x28: return inst_or_a_inddix(cpu);
		case 0x29: return inst_or_a_inddiy(cpu);
		case 0x2A: return inst_or_a_indiix(cpu);
		case 0x2B: return inst_or_a_indiiy(cpu);
		case 0x2C: return inst_or_abshl_a(cpu);
		case 0x2D: return inst_or_abshl_imm8(cpu);
		case 0x2E: return inst_or_abshl_absix(cpu);
		case 0x2F: return inst_or_abshl_absiy(cpu);
		case 0x30: return inst_cp_a_inddix(cpu);
		case 0x31: return inst_cp_a_inddiy(cpu);
		case 0x32: return inst_cp_a_indiix(cpu);
		case 0x33: return inst_cp_a_indiiy(cpu);
		case 0x34: return inst_cp_abshl_a(cpu);
		case 0x35: return inst_cp_abshl_imm8(cpu);
		case 0x36: return inst_cp_abshl_absix(cpu);
		case 0x37: return inst_cp_abshl_absiy(cpu);
		case 0x38: return inst_xor_a_inddix(cpu);
		case 0x39: return inst_xor_a_inddiy(cpu);
		case 0x3A: return inst_xor_a_indiix(cpu);
		case 0x3B: return inst_xor_a_indiiy(cpu);
		case 0x3C: return inst_xor_abshl_a(cpu);
		case 0x3D: return inst_xor_abshl_imm8(cpu);
		case 0x3E: return inst_xor_abshl_absix(cpu);
		case 0x3F: return inst_xor_abshl_absiy(cpu);
		case 0x40: return inst_ld_a_inddix(cpu);
		case 0x41: return inst_ld_a_inddiy(cpu);
		case 0x42: return inst_ld_a_indiix(cpu);
		case 0x43: return inst_ld_a_indiiy(cpu);
		case 0x44: return inst_ld_inddix_a(cpu);
		case 0x45: return inst_ld_inddiy_a(cpu);
		case 0x46: return inst_ld_indiix_a(cpu);
		case 0x47: return inst_ld_indiiy_a(cpu);
		case 0x48: return inst_ld_b_inddix(cpu);
		case 0x49: return inst_ld_b_inddiy(cpu);
		case 0x4A: return inst_ld_b_indiix(cpu);
		case 0x4B: return inst_ld_b_indiiy(cpu);
		case 0x4C: return inst_ld_inddix_b(cpu);
		case 0x4D: return inst_ld_inddiy_b(cpu);
		case 0x4E: return inst_ld_indiix_b(cpu);
		case 0x4F: return inst_ld_indiiy_b(cpu);
		case 0x50: return inst_ld_l_inddix(cpu);
		case 0x51: return inst_ld_l_inddiy(cpu);
		case 0x52: return inst_ld_l_indiix(cpu);
		case 0x53: return inst_ld_l_indiiy(cpu);
		case 0x54: return inst_ld_inddix_l(cpu);
		case 0x55: return inst_ld_inddiy_l(cpu);
		case 0x56: return inst_ld_indiix_l(cpu);
		case 0x57: return inst_ld_indiiy_l(cpu);
		case 0x58: return inst_ld_h_inddix(cpu);
		case 0x59: return inst_ld_h_inddiy(cpu);
		case 0x5A: return inst_ld_h_indiix(cpu);
		case 0x5B: return inst_ld_h_indiiy(cpu);
		case 0x5C: return inst_ld_inddix_h(cpu);
		case 0x5D: return inst_ld_inddiy_h(cpu);
		case 0x5E: return inst_ld_indiix_h(cpu);
		case 0x5F: return inst_ld_indiiy_h(cpu);
		case 0x60: return inst_ld_abshl_inddix(cpu);
		case 0x61: return inst_ld_abshl_inddiy(cpu);
		case 0x62: return inst_ld_abshl_indiix(cpu);
		case 0x63: return inst_ld_abshl_indiiy(cpu);
		case 0x68: return inst_ld_absix_inddix(cpu);
		case 0x69: return inst_ld_absix_inddiy(cpu);
		case 0x6A: return inst_ld_absix_indiix(cpu);
		case 0x6B: return inst_ld_absix_indiiy(cpu);
		case 0x78: return inst_ld_absiy_inddix(cpu);
		case 0x79: return inst_ld_absiy_inddiy(cpu);
		case 0x7A: return inst_ld_absiy_indiix(cpu);
		case 0x7B: return inst_ld_absiy_indiiy(cpu);
		case 0x80: return inst_sla_a(cpu);
		case 0x81: return inst_sla_b(cpu);
		case 0x82: return inst_sla_absbr(cpu);
		case 0x83: return inst_sla_abshl(cpu);
		case 0x84: return inst_sll_a(cpu);
		case 0x85: return inst_sll_b(cpu);
		case 0x86: return inst_sll_absbr(cpu);
		case 0x87: return inst_sll_abshl(cpu);
		case 0x88: return inst_sra_a(cpu);
		case 0x89: return inst_sra_b(cpu);
		case 0x8A: return inst_sra_absbr(cpu);
		case 0x8B: return inst_sra_abshl(cpu);
		case 0x8C: return inst_srl_a(cpu);
		case 0x8D: return inst_srl_b(cpu);
		case 0x8E: return inst_srl_absbr(cpu);
		case 0x8F: return inst_srl_abshl(cpu);
		case 0x90: return inst_rl_a(cpu);
		case 0x91: return inst_rl_b(cpu);
		case 0x92: return inst_rl_absbr(cpu);
		case 0x93: return inst_rl_abshl(cpu);
		case 0x94: return inst_rlc_a(cpu);
		case 0x95: return inst_rlc_b(cpu);
		case 0x96: return inst_rlc_absbr(cpu);
		case 0x97: return inst_rlc_abshl(cpu);
		case 0x98: return inst_rr_a(cpu);
		case 0x99: return inst_rr_b(cpu);
		case 0x9A: return inst_rr_absbr(cpu);
		case 0x9B: return inst_rr_abshl(cpu);
		case 0x9C: return inst_rrc_a(cpu);
		case 0x9D: return inst_rrc_b(cpu);
		case 0x9E: return inst_rrc_absbr(cpu);
		case 0x9F: return inst_rrc_abshl(cpu);
		case 0xA0: return inst_cpl_a(cpu);
		case 0xA1: return inst_cpl_b(cpu);
		case 0xA2: return inst_cpl_absbr(cpu);
		case 0xA3: return inst_cpl_abshl(cpu);
		case 0xA4: return inst_neg_a(cpu);
		case 0xA5: return inst_neg_b(cpu);
		case 0xA6: return inst_neg_absbr(cpu);
		case 0xA7: return inst_neg_abshl(cpu);
		case 0xA8: return clock_inst_sep(cpu);
		case 0xAE: return clock_inst_halt(cpu);
		case 0xAF: return clock_inst_slp(cpu);
		case 0xB0: return inst_and_b_imm8(cpu);
		case 0xB1: return inst_and_l_imm8(cpu);
		case 0xB2: return inst_and_h_imm8(cpu);
		case 0xB4: return inst_or_b_imm8(cpu);
		case 0xB5: return inst_or_l_imm8(cpu);
		case 0xB6: return inst_or_h_imm8(cpu);
		case 0xB8: return inst_xor_b_imm8(cpu);
		case 0xB9: return inst_xor_l_imm8(cpu);
		case 0xBA: return inst_xor_h_imm8(cpu);
		case 0xBC: return inst_cp_b_imm8(cpu);
		case 0xBD: return inst_cp_l_imm8(cpu);
		case 0xBE: return inst_cp_h_imm8(cpu);
		case 0xBF: return inst_cp_br_imm8(cpu);
		case 0xC0: return inst_ld_a_br(cpu);
		case 0xC1: return inst_ld_a_sc(cpu);
		case 0xC2: return inst_ld_br_a(cpu);
		case 0xC3: return inst_ld_sc_a(cpu);
		case 0xC4: return inst_ld_nb_imm8(cpu);
		case 0xC5: return inst_ld_ep_imm8(cpu);
		case 0xC6: return inst_ld_xp_imm8(cpu);
		case 0xC7: return inst_ld_yp_imm8(cpu);
		case 0xC8: return inst_ld_a_nb(cpu);
		case 0xC9: return inst_ld_a_ep(cpu);
		case 0xCA: return inst_ld_a_xp(cpu);
		case 0xCB: return inst_ld_a_yp(cpu);
		case 0xCC: return inst_ld_nb_a(cpu);
		case 0xCD: return inst_ld_ep_a(cpu);
		case 0xCE: return inst_ld_xp_a(cpu);
		case 0xCF: return inst_ld_yp_a(cpu);
		case 0xD0: return inst_ld_a_ind16(cpu);
		case 0xD1: return inst_ld_b_ind16(cpu);
		case 0xD2: return inst_ld_l_ind16(cpu);
		case 0xD3: return inst_ld_h_ind16(cpu);
		case 0xD4: return inst_ld_ind16_a(cpu);
		case 0xD5: return inst_ld_ind16_b(cpu);
		case 0xD6: return inst_ld_ind16_l(cpu);
		case 0xD7: return inst_ld_ind16_h(cpu);
		case 0xD8: return clock_inst_mlt(cpu);
		case 0xD9: return clock_inst_div(cpu);
		case 0xE0: return inst_jrs_lt_imm8(cpu);
		case 0xE1: return inst_jrs_le_imm8(cpu);
		case 0xE2: return inst_jrs_gt_imm8(cpu);
		case 0xE3: return inst_jrs_ge_imm8(cpu);
		case 0xE4: return inst_jrs_v_imm8(cpu);
		case 0xE5: return inst_jrs_nv_imm8(cpu);
		case 0xE6: return inst_jrs_p_imm8(cpu);
		case 0xE7: return inst_jrs_m_imm8(cpu);
		case 0xE8: return inst_jrs_f0_imm8(cpu);
		case 0xE9: return inst_jrs_f1_imm8(cpu);
		case 0xEA: return inst_jrs_f2_imm8(cpu);
		case 0xEB: return inst_jrs_f3_imm8(cpu);
		case 0xEC: return inst_jrs_nf0_imm8(cpu);
		case 0xED: return inst_jrs_nf1_imm8(cpu);
		case 0xEE: return inst_jrs_nf2_imm8(cpu);
		case 0xEF: return inst_jrs_nf3_imm8(cpu);
		case 0xF0: return inst_cars_lt_imm8(cpu);
		case 0xF1: return inst_cars_le_imm8(cpu);
		case 0xF2: return inst_cars_gt_imm8(cpu);
		case 0xF3: return inst_cars_ge_imm8(cpu);
		case 0xF4: return inst_cars_v_imm8(cpu);
		case 0xF5: return inst_cars_nv_imm8(cpu);
		case 0xF6: return inst_cars_p_imm8(cpu);
		case 0xF7: return inst_cars_m_imm8(cpu);
		case 0xF8: return inst_cars_f0_imm8(cpu);
		case 0xF9: return inst_cars_f1_imm8(cpu);
		case 0xFA: return inst_cars_f2_imm8(cpu);
		case 0xFB: return inst_cars_f3_imm8(cpu);
		case 0xFC: return inst_cars_nf0_imm8(cpu);
		case 0xFD: return inst_cars_nf1_imm8(cpu);
		case 0xFE: return inst_cars_nf2_imm8(cpu);
		case 0xFF: return inst_cars_nf3_imm8(cpu);
		default: return inst_undefined(cpu);
		}
	case 0xCF:
		switch (Machine::imm8(cpu)) {
		case 0x00: return inst_add_ba_ba(cpu);
		case 0x01: return inst_add_ba_hl(cpu);
		case 0x02: return inst_add_ba_ix(cpu);
		case 0x03: return inst_add_ba_iy(cpu);
		case 0x04: return inst_adc_ba_ba(cpu);
		case 0x05: return inst_adc_ba_hl(cpu);
		case 0x06: return inst_adc_ba_ix(cpu);
		case 0x07: return inst_adc_ba_iy(cpu);
		case 0x08: return inst_sub_ba_ba(cpu);
		case 0x09: return inst_sub_ba_hl(cpu);
		case 0x0A: return inst_sub_ba_ix(cpu);
		case 0x0B: return inst_sub_ba_iy(cpu);
		case 0x0C: return inst_sbc_ba_ba(cpu);
		case 0x0D: return inst_sbc_ba_hl(cpu);
		case 0x0E: return inst_sbc_ba_ix(cpu);
		case 0x0F: return inst_sbc_ba_iy(cpu);
		case 0x18: return inst_cp_ba_ba(cpu);
		case 0x19: return inst_cp_ba_hl(cpu);
		case 0x1A: return inst_cp_ba_ix(cpu);
		case 0x1B: return inst_cp_ba_iy(cpu);
		case 0x20: return inst_add_hl_ba(cpu);
		case 0x21: return inst_add_hl_hl(cpu);
		case 0x22: return inst_add_hl_ix(cpu);
		case 0x23: return inst_add_hl_iy(cpu);
		case 0x24: return inst_adc_hl_ba(cpu);
		case 0x25: return inst_adc_hl_hl(cpu);
		case 0x26: return inst_adc_hl_ix(cpu);
		case 0x27: return inst_adc_hl_iy(cpu);
		case 0x28: return inst_sub_hl_ba(cpu);
		case 0x29: return inst_sub_hl_hl(cpu);
		case 0x2A: return inst_sub_hl_ix(cpu);
		case 0x2B: return inst_sub_hl_iy(cpu);
		case 0x2C: return inst_sbc_hl_ba(cpu);
		case 0x2D: return inst_sbc_hl_hl(cpu);
		case 0x2E: return inst_sbc_hl_ix(cpu);
		case 0x2F: return inst_sbc_hl_iy(cpu);
		case 0x38: return inst_cp_hl_ba(cpu);
		case 0x39: return inst_cp_hl_hl(cpu);
		case 0x3A: return inst_cp_hl_ix(cpu);
		case 0x3B: return inst_cp_hl_iy(cpu);
		case 0x40: return inst_add_ix_ba(cpu);
		case 0x41: return inst_add_ix_hl(cpu);
		case 0x42: return inst_add_iy_ba(cpu);
		case 0x43: return inst_add_iy_hl(cpu);
		case 0x44: return inst_add_sp_ba(cpu);
		case 0x45: return inst_add_sp_hl(cpu);
		case 0x48: return inst_sub_ix_ba(cpu);
		case 0x49: return inst_sub_ix_hl(cpu);
		case 0x4A: return inst_sub_iy_ba(cpu);
		case 0x4B: return inst_sub_iy_hl(cpu);
		case 0x4C: return inst_sub_sp_ba(cpu);
		case 0x4D: return inst_sub_sp_hl(cpu);
		case 0x5C: return inst_cp_sp_ba(cpu);
		case 0x5D: return inst_cp_sp_hl(cpu);
		case 0x60: return inst_adc_ba_imm16(cpu);
		case 0x61: return inst_adc_hl_imm16(cpu);
		case 0x62: return inst_sbc_ba_imm16(cpu);
		case 0x63: return inst_sbc_hl_imm16(cpu);
		case 0x68: return inst_add_sp_imm16(cpu);
		case 0x6A: return inst_sub_sp_imm16(cpu);
		case 0x6C: return inst_cp_sp_imm16(cpu);
		case 0x6E: return inst_ld_sp_imm16(cpu);
		case 0x70: return inst_ld_ba_inddsp(cpu);
		case 0x71: return inst_ld_hl_inddsp(cpu);
		case 0x72: return inst_ld_ix_inddsp(cpu);
		case 0x73: return inst_ld_iy_inddsp(cpu);
		case 0x74: return inst_ld_inddsp_ba(cpu);
		case 0x75: return inst_ld_inddsp_hl(cpu);
		case 0x76: return inst_ld_inddsp_ix(cpu);
		case 0x77: return inst_ld_inddsp_iy(cpu);
		case 0x78: return inst_ld_sp_ind16(cpu);
		case 0x7C: return inst_ld_ind16_sp(cpu);
		case 0xB0: return inst_push_a(cpu);
		case 0xB1: return inst_push_b(cpu);
		case 0xB2: return inst_push_l(cpu);
		case 0xB3: return inst_push_h(cpu);
		case 0xB4: return inst_pop_a(cpu);
		case 0xB5: return inst_pop_b(cpu);
		case 0xB6: return inst_pop_l(cpu);
		case 0xB7: return inst_pop_h(cpu);
		case 0xB8: return clock_inst_push_all(cpu);
		case 0xB9: return clock_inst_push_ale(cpu);
		case 0xBC: return clock_inst_pop_all(cpu);
		case 0xBD: return clock_inst_pop_ale(cpu);
		case 0xC0: return inst_ld_ba_abshl(cpu);
		case 0xC1: return inst_ld_hl_abshl(cpu);
		case 0xC2: return inst_ld_ix_abshl(cpu);
		case 0xC3: return inst_ld_iy_abshl(cpu);
		case 0xC4: return inst_ld_abshl_ba(cpu);
		case 0xC5: return inst_ld_abshl_hl(cpu);
		case 0xC6: return inst_ld_abshl_ix(cpu);
		case 0xC7: return inst_ld_abshl_iy(cpu);
		case 0xD0: return inst_ld_ba_absix(cpu);
		case 0xD1: return inst_ld_hl_absix(cpu);
		case 0xD2: return inst_ld_ix_absix(cpu);
		case 0xD3: return inst_ld_iy_absix(cpu);
		case 0xD4: return inst_ld_absix_ba(cpu);
		case 0xD5: return inst_ld_absix_hl(cpu);
		case 0xD6: return inst_ld_absix_ix(cpu);
		case 0xD7: return inst_ld_absix_iy(cpu);
		case 0xD8: return inst_ld_ba_absiy(cpu);
		case 0xD9: return inst_ld_hl_absiy(cpu);
		case 0xDA: return inst_ld_ix_absiy(cpu);
		case 0xDB: return inst_ld_iy_absiy(cpu);
		case 0xDC: return inst_ld_absiy_ba(cpu);
		case 0xDD: return inst_ld_absiy_hl(cpu);
		case 0xDE: return inst_ld_absiy_ix(cpu);
		case 0xDF: return inst_ld_absiy_iy(cpu);
		case 0xE0: return inst_ld_ba_ba(cpu);
		case 0xE1: return inst_ld_ba_hl(cpu);
		case 0xE2: return inst_ld_ba_ix(cpu);
		case 0xE3: return inst_ld_ba_iy(cpu);
		case 0xE4: return inst_ld_hl_ba(cpu);
		case 0xE5: return inst_ld_hl_hl(cpu);
		case 0xE6: return inst_ld_hl_ix(cpu);
		case 0xE7: return inst_ld_hl_iy(cpu);
		case 0xE8: return inst_ld_ix_ba(cpu);
		case 0xE9: return inst_ld_ix_hl(cpu);
		case 0xEA: return inst_ld_ix_ix(cpu);
		case 0xEB: return inst_ld_ix_iy(cpu);
		case 0xEC: return inst_ld_iy_ba(cpu);
		case 0xED: return inst_ld_iy_hl(cpu);
		case 0xEE: return inst_ld_iy_ix(cpu);
		case 0xEF: return inst_ld_iy_iy(cpu);
		case 0xF0: return inst_ld_sp_ba(cpu);
		case 0xF1: return inst_ld_sp_hl(cpu);
		case 0xF2: return inst_ld_sp_ix(cpu);
		case 0xF3: return inst_ld_sp_iy(cpu);
		case 0xF4: return inst_ld_hl_sp(cpu);
		case 0xF5: return inst_ld_hl_pc(cpu);
		case 0xF8: return inst_ld_ba_sp(cpu);
		case 0xF9: return inst_ld_ba_pc(cpu);
		case 0xFA: return inst_ld_ix_sp(cpu);
		case 0xFE: return inst_ld_iy_sp(cpu);
		default: return inst_undefined(cpu);
		}
	}
}
