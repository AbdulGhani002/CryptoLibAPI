const express = require('express');
const router = express.Router();
const cryptoController = require('../controllers/cryptoController');

router.get('/generatePrimeNumber', cryptoController.generatePrimeNumber);
router.post('/encryptAES', cryptoController.encryptAES);
router.post('/decryptAES', cryptoController.decryptAES);
router.post('/hashFunction', cryptoController.hashFunction);

module.exports = router;
