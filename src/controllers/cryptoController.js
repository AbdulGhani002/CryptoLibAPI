const cryptolib = require('../../addon/build/Release/cryptolib');


exports.generatePrimeNumber = (req, res) => {
    try {
        const prime = cryptolib.generatePrimeNumber();
        res.status(200).json({ prime });
    } catch (error) {
        res.status(500).json({ error: error.message });
    }
};

exports.encryptAES = (req, res) => {
    const { message, key } = req.body;
    try {
        const encrypted = cryptolib.encryptAES(message, key.toString());
        res.status(200).json({ encrypted });
    } catch (error) {
        res.status(500).json({ error: error.message });
    }
};

exports.decryptAES = (req, res) => {
    const { cipher, key } = req.body;
    try {
        const decrypted = cryptolib.decryptAES(cipher, key.toString());
        res.status(200).json({ decrypted });
    } catch (error) {
        res.status(500).json({ error: error.message });
    }
};

exports.hashFunction = (req, res) => {
    const { message } = req.body;
    try {
        const hash = cryptolib.hashFunction(message);
        res.status(200).json({ hash });
    } catch (error) {
        res.status(500).json({ error: error.message });
    }
};
