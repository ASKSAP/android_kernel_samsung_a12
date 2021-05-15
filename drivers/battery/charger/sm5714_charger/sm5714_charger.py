config = {
    "build": {
        "file": "sm5714_charger.py",
        "location": [
            {
                "dst": "drivers/battery/charger/sm5714_charger/",
                "src": "sm5714* Kconfig:update Makefile:update",
            },
            {
                "dst": "arch/arm64/boot/dts/samsung/",
                "src": "sm5714_charger.dtsi",
            },
        ],
        "path": "battery/charger/sm5714_charger",
    },
    "interfaces": {
        "outports": [
            {
                "labels": [
                    {
                        "label": "sm5714-charger",
                        "value": "sm5714-charger",
                    }
                ],
                "type": "charger_name",
            }
        ]
    },
    "features": [
        {
            "configs": {
                "False": [],
                "True": [
                    "CONFIG_CHARGER_SM5714=y"
                ],
            },
            "label": "General",
            "type": "boolean",
        }
    ],
    "header": {
        "name": "SM5714 Charger",
        "product": "SM5714",
        "type": "CHARGER",
        "uuid": "0f0da7f2-da12-4509-9e19-071fac6e114c",
        "variant": "SM5714",
        "vendor": "Silicon Mitus",
        "required": [
            [
                # uuid: SM5714 mfd
                "3c2fa966-55e1-4a5a-9619-5adcb799fdfd",
                # uuid: SM5714 Fuelgauge
                "d72103b9-3d37-440d-9bf4-df21e5dc04cd",
            ]
        ],
    },
}


def load():

    return config


if __name__ == "__main__":
    print(load())
