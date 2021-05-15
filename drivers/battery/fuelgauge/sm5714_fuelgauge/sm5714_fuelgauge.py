config = {
    "build": {
        "file": "sm5714_fuelgauge.py",
        "location": [
            {
                "dst": "drivers/battery/fuelgauge/sm5714_fuelgauge/",
                "src": "sm5714* Kconfig:update Makefile:update",
            },
            {
                "dst": "arch/arm64/boot/dts/samsung/",
                "src": "*.dtsi",
            },
        ],
        "path": "battery/fuelgauge/sm5714_fuelgauge",
    },
    "features": [
        {
            "configs": {
                "False": [],
                "True": [
                    "CONFIG_FUELGAUGE_SM5714=y"
                ],
            },
            "label": "General",
            "type": "boolean",
        }
    ],
    "header": {
        "name": "SM5714 Fuelgauge",
        "product": "SM5714",
        "type": "FUELGAUGE",
        "uuid": "d72103b9-3d37-440d-9bf4-df21e5dc04cd",
        "variant": "SM5714",
        "vendor": "Silicon Mitus",
        "required": [
            [
                # uuid: SM5714 mfd
                "3c2fa966-55e1-4a5a-9619-5adcb799fdfd",
            ]
        ],
    },
}


def load():

    return config


if __name__ == "__main__":
    print(load())
