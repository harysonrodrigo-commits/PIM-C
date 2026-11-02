const pageConfig = document.getElementById("page-config");
const pageHome = document.getElementById("page-home");
const pageHistoric = document.getElementById("page-historic");


const secoes = [pageConfig, pageHistoric, pageHome];

const buttonHome = document.getElementById("buttonHome");
const buttonHistoric = document.getElementById("buttonHistoric");
const buttonConfig = document.getElementById("buttonConfig");

function show(section) {
    secoes.forEach ((s) => (s.style.display = "none"));
    if (section) section.style.display = "flex";
}

buttonConfig.addEventListener("click", () => show(pageConfig));
buttonHome.addEventListener("click", () => show(pageHome));
buttonHistoric.addEventListener("click", () => show(pageHistoric));

show(pageHome);

const boxOption = document.getElementById("boxOption");
const callOption = document.getElementById("callOption")
const contCall = document.getElementById("contCall");

const optionOne = document.getElementById("optionOne");
const optionTwo = document.getElementById("optionTwo");
const optionThree = document.getElementById("optionThree");
const optionFour = document.getElementById("optionFour");
const optionFive = document.getElementById("optionFive");

const callOne = document.getElementById("callOne");
const callTwo = document.getElementById("callTwo");
const callThree = document.getElementById("callThree");
const callFour = document.getElementById("callFour");
const callFive = document.getElementById("callFive");

const options = [callOne, callThree, callFour, callFive];
const buttons = [optionOne, optionTwo, optionThree, optionFour, optionFive];

function showOption(section) {
    options.forEach ((s) => (s.style.display = "none"));
    if (section) section.style.display = "flex";
}

buttons.forEach((btn, i) => {
    btn.addEventListener("click", () => {
        boxOption.style.display = "none";
        callOne.style.display = "flex";
    })
});

const question = document.getElementById("question");

buttonHistoric.addEventListener("click", () => {
    showOption(null);
    boxOption.style.display = "flex";
    question.style.display = "none" ? "flex" : "none";
    callTwo.style.display = "flex" ? "none" : "flex";
})

const categorias = {
  "Computador": [
    "Computador lento ou travando",
    "Computador não liga",
    "Tela azul (BSOD)",
    "Teclado ou mouse com defeito",
    "Falta de espaço em disco"
  ],
  "Software e sistemas": [
    "Programa não abre ou fecha sozinho",
    "Solicitação de instalação de software",
    "Licença expirada",
    "Suspeita de vírus ou malware"
  ],
  "Rede e internet": [
    "Sem acesso à internet",
    "Internet lenta",
    "Wi-Fi não conecta",
    "Problemas com VPN"
  ],
  "Impressoras e periféricos": [
    "Impressora não imprime",
    "Impressora offline",
    "Papel atolado ou toner acabando",
    "Webcam, microfone ou fone sem funcionar"
  ],
  "E-mail e comunicação": [
    "Não consigo enviar ou receber e-mails",
    "Caixa de e-mail cheia",
    "Problemas com Teams, Zoom ou Meet"
  ],
  "Segurança": [
    "Recebi um e-mail ou link suspeito",
    "Perda ou roubo de equipamento",
    "Suspeita de acesso indevido à conta"
  ]
};

const selectProblem = document.getElementById("problem");


function preencherProblemas(categoria) {
    selectProblem.innerHTML = '<option value="">Selecione o problema</option>';

    categorias[categoria].forEach((problema) => {
    const option = document.createElement("option");
    option.value = problema;
    option.textContent = problema;
    selectProblem.appendChild(option);
    });
}

optionOne.addEventListener("click", () => {
    preencherProblemas("Computador")
    question.style.display = "none"
});

selectProblem.addEventListener("change", function() {
  const problemOption = selectProblem.value;
  

  callTwo.classList.remove("open");
  void callTwo.offsetWidth;


  if (problemOption === "Computador lento ou travando") {
    callTwo.innerHTML = "<li>Demora excessiva para ligar ou abrir programas: O sistema leva vários minutos para iniciar ou trava por longos períodos ao tentar abrir programas do dia a dia (como Word, Excel, navegadores de internet ou o sistema da empresa).</li><li>Congelamentos frequentes: A tela 'congela', a seta do mouse para de mover ou aparece a mensagem '(Não está respondendo)' na janela do programa.</li><li>Superaquecimento ou barulho excessivo: O computador esquenta muito ou faz um barulho forte e contínuo nas ventoinhas, ficando visivelmente mais lento logo em seguida.</li><li>Respostas com atraso: Você digita no teclado ou clica com o mouse, mas o computador demora alguns segundos para mostrar a ação na tela.</li>"
    callTwo.style.display = "flex";
    callTwo.classList.add("open");
  } else {
    callTwo.innerHTML = ""
    callTwo.style.display = "none";
  }
})

showOption(null);




