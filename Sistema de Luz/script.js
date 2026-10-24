
const botaoMenu = document.getElementById("menu-pequeno");
const menuLinks = document.getElementById("menu-links");

botaoMenu.addEventListener("click", () => {
    const menuAberto = menuLinks.classList.toggle("ativo");

    botaoMenu.innerHTML = menuAberto
        ? '<i class="fa-solid fa-xmark"></i>'
        : '<i class="fa-solid fa-bars"></i>';

    botaoMenu.setAttribute("aria-expanded", menuAberto);
});


const enderecoESP32 = "http://192.168.0.12";

const ambientes = document.querySelectorAll(".ambiente");

ambientes.forEach((ambiente) => {
    const nomeAmbiente = ambiente.dataset.ambiente;
    const botaoLigar = ambiente.querySelector(".btn-on");
    const botaoDesligar = ambiente.querySelector(".btn-off");

    async function controlarLuz(estado) {
        try {
            const resposta = await fetch(
                `${enderecoESP32}/luz?ambiente=${nomeAmbiente}&estado=${estado}`
            );

            if (!resposta.ok) {
                throw new Error("O ESP32 retornou um erro.");
            }

            console.log(`${nomeAmbiente}: comando ${estado} enviado!`);
        } catch (erro) {
            console.error("Erro ao controlar a luz:", erro);
        }
    }

    botaoLigar.addEventListener("click", () => controlarLuz("on"));
    botaoDesligar.addEventListener("click", () => controlarLuz("off"));
});