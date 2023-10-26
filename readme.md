# QMK Dubeolsik (두벌식)

An experimental QMK code piece that aims to simulate a [Dubeolsik](https://en.wikipedia.org/wiki/Keyboard_layout#Dubeolsik) layout within the QMK firmware.

For Korean typists who prefer a customized English layout (e.g. Colemak-DH), simply remapping the QWERTY layout is not a viable option, as it would also scramble the Korean layout. There are a few ways to address this issue, each with its own set of limitations:

- Instead add a custom English layout on their computers.
  - Adding a custom layout to a computer is difficult.
- Add an additional layer to the keyboard. Toggle the language input and layer at the same time.
  - The sync between the language input and the layer is not guaranteed.

This custom QMK code piece can overcome above limitations by directly inputting Korean letters. For instance, when Korean is enabled, pressing Q will send literal "ㅂ" instead of "KC_Q". It tries to combine letters interactively, just like how Windows Korean IME works.

## Prerequisites

This code piece utilizes the QMK Unicode feature. Some installations or modifications may be necessary since Unicode input methods are not enabled by default in most operating systems.
Please read the [QMK Firmware documentation](https://docs.qmk.fm/#/feature_unicode?id=input-modes) and follow the OS-specific instructions.

Additionally for WinCompose users, the default compose key (Right Alt) will also activate "한/영" key in the Korean IME. You can choose to do one of the following to prevent it:

- Set the compose key to a different key (e.g. `F13`), and edit `UNICODE_KEY_WINC` value (e.g. `KC_F13`) in `config.h` file
- Disable the Korean IME and use the English QWERTY layout.

## Configuration

In `keymaps.c` file, edit `keymaps[][MATRIX_ROWS][MATRIX_COLS]` and `dbs_keymap[MATRIX_ROWS][MATRIX_COLS]` to your own keyboard layout.

A timer is implemented to reset the korean input (to clear the cache) if there is no korean input for a certain amount of time.
The timer duration is specified as `DBS_TIMEOUT_MS` in `config.h` file.
