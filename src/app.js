const express = require('express');
const config = require('./config/config');
const cryptoRoutes = require('./routes/cryptoRoutes');
const errorHandler = require('./middleware/errorHandler');

const app = express();

app.use(express.json());
app.use('/api/crypto', cryptoRoutes);
app.use(errorHandler);

app.listen(config.port, () => {
    console.log(`Server is running on port ${config.port}`);
});
