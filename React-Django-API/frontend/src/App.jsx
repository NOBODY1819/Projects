import react from "react"
import {BrowserRouter, Routes, Route, Navigate} from "react-router-dom"
import Home from "./pages/home.jsx"
import Login from "./pages/login"
import Register from "./pages/register"
import Notfound from "./pages/notFound"
import ProtectedRoute from "./components/protectedRoute"

function Logout() {
  localStorage.clear()
  return <Navigate to="/login" />
}

function RegisterAndLogout() {
  localStorage.clear()
  return <Register />
}

function App() {
  return (
    <BrowserRouter>
      <Routes>
        <Route
        path="/"
        element={
          <ProtectedRoute>
            <Home />
          </ProtectedRoute>
        }
        />
        <Route path="/login" element={<Login />} />
        <Route path="/logout" element={<Logout />} />
        <Route path="/register" element={<RegisterAndLogout />} />
        <Route path="*" element={<Notfound />} />
  
      </Routes>
    </BrowserRouter>
  )
}

export default App
