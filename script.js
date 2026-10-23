const back_color = document.querySelectorAll(".back-color");
const tema = document.getElementById("tema");

function aplicarTema(valor) {
    back_color.forEach((el) => {
        el.classList.toggle("light", valor === "light");});
}

tema.addEventListener("change", () => {
    aplicarTema(tema.value);
    localStorage.setItem("tema", tema.value);
});

const salvo = localStorage.getItem("tema");
if (salvo) {
    tema.value = salvo;
}
aplicarTema(tema.value);


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


const seePassword = document.getElementById("seePassword");
const passwordInput = document.getElementById("passwordInput");

seePassword.addEventListener("click", () => {
    if (passwordInput.type === "password") {
        passwordInput.type = "text";
    } else {
        passwordInput.type = "password";
    }
});

