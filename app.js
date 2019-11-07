const SerialPort = require('serialport');
const WebSocket = require('ws')

const ReadLine = SerialPort.parsers.Readline;

//Inicialza o servidor websocket
const wss = new WebSocket.Server({ port: 8080 })

//Quando algum cliente se conectar
wss.on('connection', ws => {
    console.log('Cliente conectado ao servidor WebSocket');
    ws.send('Conectado ao servidor Web Socket')
}) 

wss.on('message', message => {
    console.log(message);
})

setInterval(() => {
    wss.clients.forEach(function each(client) {
        if (client.readyState === WebSocket.OPEN) {
        client.send(Math.random());
        }
    });
}, 2000);

// //Cria a conexão com a porta COM3 (Falta fazer uma validação para ver se a porta existe)
// const port = new SerialPort('COM3', {
//     baudRate: 9600,
// })

// const parser = port.pipe(new ReadLine({delimiter : '\n', }))

// port.on('open', () => {
//     console.log("Aberta");
// })

// //Quando a porta COM3 mandar algum dado
// parser.on('data', (dados) => {
//     console.log('Mensagem recebida da porta COM3')

//     if(wss.clients.size > 0){
//         console.log('Enviando mensagem para o cliente...')
//         console.log(dados.toString('utf8'));
//         //Itera os clientes e envia a mensagem
//         wss.clients.forEach(function each(client) {
//             if (client.readyState === WebSocket.OPEN) {
//               client.send(dados.toString('utf8'));
//             }
//           });
//     }else{
//         console.log('Sem cliente conectado...')
//     }
// })

// parser.on('error', (err) => {
//     console.log(`Erro: ${err}`);
// })





