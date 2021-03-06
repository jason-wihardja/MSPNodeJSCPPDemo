﻿module.exports = function (express) {
    // EXPRESS ROUTER
    var router = express.Router({ mergeParams: true });
    
    router.get('/', function (request, response, next) {
        var helloAddon = require('../addons/HelloAddon');
        
        response.render('IndexView', {
            title: helloAddon.hello(),
            content1: helloAddon.hello(request.query.message || "")
        });
    });
    
    router.use('/factorial', require('./factorialAPI.js')(express));
    router.use('/prime', require('./primeAPI.js')(express));
    router.use('/performance', require('./performanceAPI.js')(express));
    
    return router;
}